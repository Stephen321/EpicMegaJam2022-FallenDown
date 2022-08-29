// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JamInteractionSubsystem.generated.h"

class UJamWidgetLevelHUD;
class UJamInteractableComponent;
/**
 * 
 */
UCLASS()
class EPICMEGAJAM2022_API UJamInteractionSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void PostInitialize() override;
	virtual void OnWorldBeginPlay(UWorld& InWorld) override;
	virtual void OnWorldComponentsUpdated(UWorld& World) override;

	// these are triggered everytime an interaction event happens
	void HUDBeginInteraction(UJamInteractableComponent* InteractableComponent);
	void HUDEndInteraction(UJamInteractableComponent* InteractableComponent);
	void HUDOnInteract(UJamInteractableComponent* InteractableComponent);

private:
	TWeakObjectPtr<UJamWidgetLevelHUD> ActiveWidgetLevelHUD;
};
