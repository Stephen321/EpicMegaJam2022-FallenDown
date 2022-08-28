// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "JamGameStateBase.generated.h"

// bp accessible events for changes to game state
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTokensChanged, int32, Tokens);

/**
 * Seeing as there is only over going to be 1 player. We keep Balance and Tokens here
 * Balance in particular is more relevant as it will determine other aspects of Gameplay
 * Tokens *could* be kept on PlayerState but not necessary
 */
UCLASS()
class EPICMEGAJAM2022_API AJamGameStateBase : public AGameStateBase
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintCallable, Category="Jam")
	void AddTokens(int32 Count);
	
	UFUNCTION(BlueprintCallable, Category="Jam")
	bool RemoveTokens(int32 Count);

public: // Delegates
	UPROPERTY(BlueprintAssignable, Category="Jam")
	FOnTokensChanged OnTokensChanged;

private:
	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess), Category="Jam")
	int32 Tokens;
};
