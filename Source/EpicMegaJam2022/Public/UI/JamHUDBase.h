// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "JamWidgetLevelHUD.h"
#include "GameFramework/HUD.h"
#include "JamHUDBase.generated.h"

class UJamWidgetMainMenuLevelHUD;
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

protected:
	
public:
	UFUNCTION(BlueprintCallable, Category="Jam")
	void SetWidgetLevelHUD(UJamWidgetLevelHUD* InWidgetLevelHUD);
	
	TWeakObjectPtr<UJamWidgetLevelHUD> GetWidgetLevelHUD() const { return WidgetLevelHUD; }
	
private:
	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess))
	TWeakObjectPtr<UJamWidgetLevelHUD> WidgetLevelHUD;
	
};
