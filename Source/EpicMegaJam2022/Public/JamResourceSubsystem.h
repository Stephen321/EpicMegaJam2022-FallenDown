// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JamConstants.h"
#include "JamResourceTypes.h"
#include "JamResourceSubsystem.generated.h"

class AJamGameStateBase;

// bp accessible events for changes to game state
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTokensChanged, int32, Tokens);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBalanceChanged, int32, Balance);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBalanceThresholdReached, EJamBalanceType, BalanceType, EJamBalanceThreshold, Threshold);

/**
 * State stored on GameState but logic handled by this subsystem
 */
UCLASS()
class EPICMEGAJAM2022_API UJamResourceSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void PostInitialize() override;
	virtual void OnWorldBeginPlay(UWorld& InWorld) override;
	virtual void OnWorldComponentsUpdated(UWorld& World) override;
	
	// TODO: this really shouldn't be here...
	bool GetGameWon();
	
	UFUNCTION(BlueprintCallable, Category="Jam")
	void AddTokens(int32 Count);
	
	UFUNCTION(BlueprintCallable, Category="Jam")
	void RemoveTokens(int32 Count);
	
	UFUNCTION(BlueprintCallable, Category="Jam")
	void ResetTokens();
	
	UFUNCTION(BlueprintCallable, Category="Jam")
	int32 GetTokens();

	UFUNCTION(BlueprintCallable, Category="Jam")
	void ChangeBalance(EJamBalanceType Direction, EJamBalanceAmount Amount);
	
	UFUNCTION(BlueprintCallable, Category="Jam")
	void ResetBalance();

	//constants
	UFUNCTION(BlueprintCallable, Category="Jam")
	int32 GetHellBalance() const { return JamConstants::HellBalance; }
	
	UFUNCTION(BlueprintCallable, Category="Jam")
	int32 GetHeavenBalance() const { return JamConstants::HeavenBalance; }
	
	UFUNCTION(BlueprintCallable, Category="Jam")
	int32 GetBalanceSmallThreshold() const { return JamConstants::BalanceSmallThreshold; };
	
	UFUNCTION(BlueprintCallable, Category="Jam")
	int32 GetBalanceMediumThreshold() const { return JamConstants::BalanceMediumThreshold; };
	
	UFUNCTION(BlueprintCallable, Category="Jam")
	int32 GetBalanceLargeThreshold() const { return JamConstants::BalanceLargeThreshold; };
	
	UFUNCTION(BlueprintCallable, Category="Jam")
	int32 GetBalanceDangerThreshold() const { return JamConstants::BalanceDangerThreshold; };
	
	// delegates
	UPROPERTY(BlueprintAssignable, Category="Jam")
	FOnTokensChanged OnTokensChanged;
	
	UPROPERTY(BlueprintAssignable, Category="Jam")
	FOnBalanceChanged OnBalanceChanged;
	
	UPROPERTY(BlueprintAssignable, Category="Jam")
	FOnBalanceThresholdReached OnBalanceThresholdReached;
	
	
private:
	TWeakObjectPtr<AJamGameStateBase> GameState;
};
