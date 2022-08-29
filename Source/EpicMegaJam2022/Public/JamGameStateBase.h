// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JamResourceTypes.h"
#include "GameFramework/GameStateBase.h"
#include "JamGameStateBase.generated.h"


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
	AJamGameStateBase();
	
	void AddTokens(int32 Count);
	void RemoveTokens(int32 Count);
	int32 GetTokens() const { return Tokens; }
	void ResetTokens() { Tokens = 0; }
	
	void ChangeBalance(int32 Count, EJamBalanceType& Type, EJamBalanceThreshold& OutThreshold);
	int32 GetBalance() const { return Balance; }
	void ResetBalance() { Balance = 0; }

private:
	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess), Category="Jam")
	int32 Tokens;
	
	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess), Category="Jam")
	int32 Balance;
};
