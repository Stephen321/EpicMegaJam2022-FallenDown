// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "JamWidgetBase.h"
#include "JamWidgetLevelHUD.generated.h"

class UJamInteractableComponent;
class AJamHUDBase;
/**
 * 
 */
UCLASS()
class EPICMEGAJAM2022_API UJamWidgetLevelHUD : public UJamWidgetBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, Category="Jam")
	void OnBeginInteraction(UJamInteractableComponent* InteractableComponent);
	
	UFUNCTION(BlueprintImplementableEvent, Category="Jam")
	void OnEndInteraction(UJamInteractableComponent* InteractableComponent);

	void SetOwningHUD(AJamHUDBase* InOwningHUD);

private:
	UPROPERTY(BlueprintReadWrite, meta=(AllowPrivateAccess))
	TWeakObjectPtr<AJamHUDBase> OwningHUD;
};
