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

void UJamResourceSubsystem::AddTokens(int32 Count)
{
	if (GameState.IsValid())
	{
		GameState->AddTokens(Count);
		OnTokensChanged.Broadcast(GameState->GetTokens());
	}
}

bool UJamResourceSubsystem::RemoveTokens(int32 Count)
{
	if (GameState.IsValid())
	{
		if (GameState->RemoveTokens(Count))
		{
			OnTokensChanged.Broadcast(GameState->GetTokens());
			return true;
		}
	}
	return false;
}
