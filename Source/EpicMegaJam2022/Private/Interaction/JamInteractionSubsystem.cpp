// Fill out your copyright notice in the Description page of Project Settings.


#include "Interaction/JamInteractionSubsystem.h"
#include "Interaction/Interface_JamInteractor.h"

#include "UI/JamHUDBase.h"
#include "UI/JamWidgetLevelHUD.h"

void UJamInteractionSubsystem::PostInitialize()
{
	Super::PostInitialize();
}

void UJamInteractionSubsystem::OnWorldBeginPlay(UWorld& InWorld)
{
	Super::OnWorldBeginPlay(InWorld);
	
	InWorld.GetTimerManager().SetTimerForNextTick([this, &InWorld]()
	{
		AJamHUDBase* HUD = Cast<AJamHUDBase>(InWorld.GetFirstPlayerController()->GetHUD());
		if (HUD)
		{
			ActiveWidgetLevelHUD = HUD->GetWidgetLevelHUD();
			ensure(ActiveWidgetLevelHUD.IsValid());
		}
	});
}

void UJamInteractionSubsystem::OnWorldComponentsUpdated(UWorld& World)
{
	Super::OnWorldComponentsUpdated(World);
}

void UJamInteractionSubsystem::HUDBeginInteraction(UJamInteractableComponent* InteractableComponent)
{
	IInterface_JamInteractor::Execute_BeginInteraction(ActiveWidgetLevelHUD.Get(), InteractableComponent);
}

void UJamInteractionSubsystem::HUDEndInteraction(UJamInteractableComponent* InteractableComponent)
{
	IInterface_JamInteractor::Execute_EndInteraction(ActiveWidgetLevelHUD.Get(), InteractableComponent);
}

void UJamInteractionSubsystem::HUDOnInteract(UJamInteractableComponent* InteractableComponent)
{
	IInterface_JamInteractor::Execute_OnInteract(ActiveWidgetLevelHUD.Get(), InteractableComponent);
}
