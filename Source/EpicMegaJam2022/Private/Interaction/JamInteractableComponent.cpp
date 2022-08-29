// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/JamInteractableComponent.h"

#include "Interaction/Interface_JamInteractor.h"
#include "Interaction/Interface_JamInteraction.h"
#include "Interaction/JamInteractionSubsystem.h"

#include "GameFramework/InputSettings.h"


// Sets default values for this component's properties
UJamInteractableComponent::UJamInteractableComponent()
	: bInteractable(true)
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	SetGenerateOverlapEvents(true);
	Super::SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);

	OnComponentBeginOverlap.AddDynamic(this, &UJamInteractableComponent::ComponentBeginOverlap);
	OnComponentEndOverlap.AddDynamic(this, &UJamInteractableComponent::ComponentEndOverlap);

	InteractText = FText::FromString(TEXT("Interact"));
}

UJamInteractableComponent::~UJamInteractableComponent()
{
	OnComponentBeginOverlap.RemoveAll(this);
	OnComponentEndOverlap.RemoveAll(this);
}


// Called when the game starts
void UJamInteractableComponent::BeginPlay()
{
	Super::BeginPlay();

	Interactions.Empty();
	AActor* Owner = GetOwner();
	if (Owner->Implements<UInterface_JamInteraction>())
	{
		Interactions.Add(Owner);
	}

	
	TArray<UActorComponent*> InteractionComponents = Owner->GetComponentsByInterface(UInterface_JamInteraction::StaticClass());
	Interactions.Append(InteractionComponents);
}


// Called every frame
void UJamInteractableComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                              FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UJamInteractableComponent::IsInteractable() const
{
	return bInteractable;
}

void UJamInteractableComponent::SetInteractable(bool bInInteractable)
{
	bInteractable = bInInteractable;
}

void UJamInteractableComponent::Interact(AActor* Interactor)
{
	if (bInteractable)
	{
		bInteractable = false;
		OnInteract.Broadcast(); 
		for (auto& Interaction : Interactions)
		{
			IInterface_JamInteraction::Execute_Interact(Interaction.Get(), this, Interactor);
		}
		UWorld* World = GetWorld();
		
		World->GetSubsystem<UJamInteractionSubsystem>()->HUDOnInteract(this);
		
		World->GetTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda([this] ()
		{
			bInteractable = !bCanInteractOnlyOnce;

			// if interactor hasnt moved out of the interaction bounds then trigger HUD again without needing to exit and enter
			if (bInteractable)
			{
				BeginInteraction(OverlappingActor.Get());
			}
		}), InteractCooldown, false);
		
	}
}

void UJamInteractableComponent::ComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                                      UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OverlappingActor = OtherActor;
	if (!IsInteractable())
	{
		return;
	}
	BeginInteraction(OtherActor);
}

void UJamInteractableComponent::ComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	OverlappingActor.Reset();
	EndInteraction(OtherActor);
}

void UJamInteractableComponent::BeginInteraction(TWeakObjectPtr<AActor> Interactor)
{
	if (Interactor.IsValid() && Interactor->Implements<UInterface_JamInteractor>())
	{
		IInterface_JamInteractor::Execute_EndInteraction(Interactor.Get(), this);
		GetWorld()->GetSubsystem<UJamInteractionSubsystem>()->HUDBeginInteraction(this);
	}
}

void UJamInteractableComponent::EndInteraction(TWeakObjectPtr<AActor> Interactor)
{
	if (Interactor.IsValid() && Interactor->Implements<UInterface_JamInteractor>())
	{
		IInterface_JamInteractor::Execute_EndInteraction(Interactor.Get(), this);
		GetWorld()->GetSubsystem<UJamInteractionSubsystem>()->HUDEndInteraction(this);
	}
}

