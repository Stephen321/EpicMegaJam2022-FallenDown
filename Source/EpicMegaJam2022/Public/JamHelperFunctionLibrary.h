// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "JamHelperFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class EPICMEGAJAM2022_API UJamHelperFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Jam")
	static FName GetInteractActionName();
	
	UFUNCTION(BlueprintCallable, Category="Jam")
	static void SaveGame(UObject* WorldContextObject);
	
	UFUNCTION(BlueprintCallable, Category="Jam")
	static bool IsGameWon(UObject* WorldContextObject);
};
