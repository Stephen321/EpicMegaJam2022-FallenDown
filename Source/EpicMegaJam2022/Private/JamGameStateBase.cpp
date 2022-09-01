// Fill out your copyright notice in the Description page of Project Settings.

#include "JamGameStateBase.h"

#include "JamConstants.h"

AJamGameStateBase::AJamGameStateBase()
{
	Tokens = 0;
	Balance = 0;
}

void AJamGameStateBase::AddTokens(int32 Count)
{
	check(Count > 0);
	
	Tokens += Count;
}

void AJamGameStateBase::RemoveTokens(int32 Count)
{
	if (Tokens >= Count)
	{
		Tokens -= Count;
	}
	Tokens = 0;
}

void AJamGameStateBase::ChangeBalance(int32 Count, EJamBalanceType& Type, EJamBalanceThreshold& OutThreshold)
{
	
	uint32 PreviousBalance = FMath::Abs(Balance);
	Balance += Count;
	uint32 CurrentBalance = FMath::Abs(Balance);
	Type = EJamBalanceType::Hell;
	if (Balance > 0)
	{
		Type = EJamBalanceType::Heaven;
	}
	
	OutThreshold = EJamBalanceThreshold::NoChange;

	if (PreviousBalance < JamConstants::BalanceSmallThreshold &&
		CurrentBalance >= JamConstants::BalanceSmallAmount)
	{
		OutThreshold = EJamBalanceThreshold::Small;	
	}
	else if (PreviousBalance < JamConstants::BalanceMediumAmount &&
		CurrentBalance >= JamConstants::BalanceMediumAmount)
	{
		OutThreshold = EJamBalanceThreshold::Medium;	
	}
	else if (PreviousBalance < JamConstants::BalanceLargeAmount &&
		CurrentBalance >= JamConstants::BalanceLargeAmount)
	{
		OutThreshold = EJamBalanceThreshold::Large;	
	}
	else if (PreviousBalance < JamConstants::BalanceDangerThreshold &&
		CurrentBalance >= JamConstants::BalanceDangerThreshold)
	{
		OutThreshold = EJamBalanceThreshold::Danger;	
	}
	
	if (Balance < JamConstants::HellBalance)
	{
		OutThreshold = EJamBalanceThreshold::Maxed;
	}
	if (Balance > JamConstants::HeavenBalance)
	{
		OutThreshold = EJamBalanceThreshold::Maxed;
	}
}

bool AJamGameStateBase::GetGameWon()
{
	return bGameWon;
}

