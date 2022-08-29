// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "JamResourceSubsystem.generated.h"

class AJamGameStateBase;
// bp accessible events for changes to game state
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTokensChanged, int32, Tokens);

/**
 * State stored on GameState but logic handled by this subsystem
 */
UCLASS()
class EPICMEGAJAM2022_API UJamResourceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	
	UFUNCTION(BlueprintCallable, Category="Jam")
	void AddTokens(int32 Count);
	
	UFUNCTION(BlueprintCallable, Category="Jam")
	bool RemoveTokens(int32 Count);

	// delegates
	UPROPERTY(BlueprintAssignable, Category="Jam")
	FOnTokensChanged OnTokensChanged;

private:
	TWeakObjectPtr<AJamGameStateBase> GameState;
};
