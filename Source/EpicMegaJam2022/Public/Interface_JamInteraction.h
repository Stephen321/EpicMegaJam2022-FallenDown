// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interface_JamInteraction.generated.h"

class UJamInteractableComponent;
// This class does not need to be modified.
UINTERFACE()
class UInterface_JamInteraction : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class EPICMEGAJAM2022_API IInterface_JamInteraction
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintImplementableEvent, Category="Jam")
	void Interact(UJamInteractableComponent* InteractableComponent, AActor* Interactor);
};
