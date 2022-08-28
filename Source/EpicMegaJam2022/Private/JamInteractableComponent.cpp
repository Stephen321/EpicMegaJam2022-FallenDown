// Fill out your copyright notice in the Description page of Project Settings.


#include "JamInteractableComponent.h"

#include "Interface_JamInteractor.h"
#include "JamHUDBase.h"


// Sets default values for this component's properties
UJamInteractableComponent::UJamInteractableComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	SetGenerateOverlapEvents(true);
	Super::SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);

	Message = FText::FromString(TEXT("Press the interact here to find out more"));
	OnComponentBeginOverlap.AddDynamic(this, &UJamInteractableComponent::ComponentBeginOverlap);
	OnComponentEndOverlap.AddDynamic(this, &UJamInteractableComponent::ComponentEndOverlap);

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

	// ...
	
}


// Called every frame
void UJamInteractableComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                              FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UJamInteractableComponent::ComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor->Implements<UInterface_JamInteractor>())
	{
		IInterface_JamInteractor::Execute_BeginInteraction(OtherActor, this);
	}
}

void UJamInteractableComponent::ComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && OtherActor->Implements<UInterface_JamInteractor>())
	{
		IInterface_JamInteractor::Execute_EndInteraction(OtherActor, this);
	}
}

