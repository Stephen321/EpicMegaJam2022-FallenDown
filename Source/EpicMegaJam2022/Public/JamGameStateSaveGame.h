// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "UObject/Object.h"
#include "JamGameStateSaveGame.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class EPICMEGAJAM2022_API UJamGameStateSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="Jam")
	bool bGameWon = false;
};
