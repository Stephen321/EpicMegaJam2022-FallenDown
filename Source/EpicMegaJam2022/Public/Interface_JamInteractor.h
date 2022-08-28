// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JamInteractableComponent.h"
#include "UObject/Interface.h"
#include "Interface_JamInteractor.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UInterface_JamInteractor : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class EPICMEGAJAM2022_API IInterface_JamInteractor
{
	GENERATED_BODY()

public:
	// events
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Jam")
    void BeginInteraction(UJamInteractableComponent* InteractableComponent);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Jam")
    void EndInteraction(UJamInteractableComponent* InteractableComponent);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category="Jam")
    void OnInteract(UJamInteractableComponent* InteractableComponent);
};
