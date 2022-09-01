// Fill out your copyright notice in the Description page of Project Settings.


#include "JamResourceSubsystem.h"

#include "JamGameStateBase.h"

void UJamResourceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	GetWorld()->OnActorsInitialized.AddLambda([this](const UWorld::FActorsInitializedParams& Params)
	{
		GameState = Cast<AJamGameStateBase>(Params.World->GetGameState());
	});
}

void UJamResourceSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

bool UJamResourceSubsystem::GetGameWon()
{
	if (GameState.IsValid())
	{
		return GameState->GetGameWon();
	}
	return false;
}

void UJamResourceSubsystem::AddTokens(int32 Count)
{
	if (GameState.IsValid())
	{
		GameState->AddTokens(Count);
		OnTokensChanged.Broadcast(GameState->GetTokens());
	}
}

void UJamResourceSubsystem::RemoveTokens(int32 Count)
{
	if (GameState.IsValid())
	{
		GameState->RemoveTokens(Count);
		OnTokensChanged.Broadcast(GameState->GetTokens());
	}
}

void UJamResourceSubsystem::ResetTokens()
{
	if (GameState.IsValid())
	{
		GameState->ResetTokens();
		OnTokensChanged.Broadcast(GameState->GetTokens());
	}
}

int32 UJamResourceSubsystem::GetTokens()
{
	if (GameState.IsValid())
	{
		return GameState->GetTokens();
	}
	return 0;
}

void UJamResourceSubsystem::ChangeBalance(EJamBalanceType Direction, EJamBalanceAmount Amount)
{
	if (!GameState.IsValid())
	{
		return;
	}
	
	int32 AmountValue = JamConstants::BalanceSmallAmount;
	if (Amount == EJamBalanceAmount::Medium)
	{
		AmountValue = JamConstants::BalanceMediumAmount;	
	}
	else if (Amount == EJamBalanceAmount::Large)
	{
		AmountValue = JamConstants::BalanceLargeAmount;	
	}
	
	if (Direction == EJamBalanceType::Hell)
	{
		AmountValue = -AmountValue;
	}
	EJamBalanceType Type;
	EJamBalanceThreshold Threshold;
	GameState->ChangeBalance(AmountValue, Type, Threshold);
	if (Threshold != EJamBalanceThreshold::NoChange)
	{
		OnBalanceThresholdReached.Broadcast(Type, Threshold);
	}
	OnBalanceChanged.Broadcast(GameState->GetBalance());
}

void UJamResourceSubsystem::ResetBalance()
{
	if (GameState.IsValid())
	{
		GameState->ResetBalance();
		OnBalanceChanged.Broadcast(GameState->GetBalance());
	}
}
