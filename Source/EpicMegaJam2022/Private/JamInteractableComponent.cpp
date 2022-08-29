// Fill out your copyright notice in the Description page of Project Settings.


#include "JamInteractableComponent.h"

#include "Interface_JamInteractor.h"
#include "JamHUDBase.h"
#include "Interface_JamInteractAction.h"
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

	if (!InteractActionInterface)
	{
		AActor* Owner = GetOwner();
		if (Owner->Implements<UInterface_JamInteractAction>())
		{
			InteractActionInterface = Owner;
		}

		
		TArray<UActorComponent*> Components = Owner->GetComponentsByInterface(UInterface_JamInteractAction::StaticClass());
		if (Components.Num() > 0)
		{
			InteractActionInterface = Components[0];
		}
	}
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
		if (InteractActionInterface)
		{
			IInterface_JamInteractAction::Execute_Interact(InteractActionInterface.Get(), this, Interactor);
		}
		
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateLambda([this] ()
		{
			bInteractable = !bCanInteractOnlyOnce;

			// if interactor hasnt moved out of the interaction bounds then trigger HUD again without needing to exit and enter
			if (bInteractable && OverlappingActor.IsValid() && OverlappingActor->Implements<UInterface_JamInteractor>())
			{
				IInterface_JamInteractor::Execute_BeginInteraction(OverlappingActor.Get(), this);
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
	if (OtherActor && OtherActor->Implements<UInterface_JamInteractor>())
	{
		IInterface_JamInteractor::Execute_BeginInteraction(OtherActor, this);
	}
}

void UJamInteractableComponent::ComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	OverlappingActor.Reset();
	if (OtherActor && OtherActor->Implements<UInterface_JamInteractor>())
	{
		IInterface_JamInteractor::Execute_EndInteraction(OtherActor, this);
	}
}

