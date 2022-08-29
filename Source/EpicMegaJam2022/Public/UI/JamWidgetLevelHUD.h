// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Interaction/Interface_JamInteractor.h"
#include "UI/JamWidgetBase.h"
#include "JamWidgetLevelHUD.generated.h"

class UJamInteractableComponent;
class AJamHUDBase;
/**
 * 
 */
UCLASS()
class EPICMEGAJAM2022_API UJamWidgetLevelHUD : public UJamWidgetBase, public IInterface_JamInteractor
{
	GENERATED_BODY()

public:
	void SetOwningHUD(AJamHUDBase* InOwningHUD);
	
private:
	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess))
	TWeakObjectPtr<AJamHUDBase> OwningHUD;
};

UCLASS()
class EPICMEGAJAM2022_API UJamWidgetMainMenuLevelHUD : public UJamWidgetBase
{
	GENERATED_BODY()

public:
};

UCLASS()
class EPICMEGAJAM2022_API UJamWidgetPurgatoryLevelHUD : public UJamWidgetBase
{
	GENERATED_BODY()
};
