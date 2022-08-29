// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "JamHUDBase.generated.h"

class UJamWidgetLevelHUD;
class UJamInteractableComponent;
/**
 * 
 */
UCLASS()
class EPICMEGAJAM2022_API AJamHUDBase : public AHUD
{
	GENERATED_BODY()

public:
	AJamHUDBase();
	
	UFUNCTION(BlueprintCallable, Category="Jam")
	void BeginInteraction(UJamInteractableComponent* InteractableComponent);
	
	UFUNCTION(BlueprintCallable, Category="Jam")
	void EndInteraction(UJamInteractableComponent* InteractableComponent);
	
	UFUNCTION(BlueprintCallable, Category="Jam")
	void OnInteract(UJamInteractableComponent* InteractableComponent);

	UFUNCTION(BlueprintCallable, Category="Jam")
	void SetWidgetLevelHUD(UJamWidgetLevelHUD* InWidgetLevelHUD);

private:
	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess))
	TWeakObjectPtr<UJamWidgetLevelHUD> WidgetLevelHUD;
};
