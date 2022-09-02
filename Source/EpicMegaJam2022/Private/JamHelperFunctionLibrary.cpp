// Fill out your copyright notice in the Description page of Project Settings.


#include "JamHelperFunctionLibrary.h"

#include "JamConstants.h"
#include "JamGameStateSaveGame.h"
#include "JamResourceSubsystem.h"
#include "Kismet/GameplayStatics.h"

#define SAVE_GAME_SLOT TEXT("GameState")

FName UJamHelperFunctionLibrary::GetInteractActionName()
{
	return JamConstants::InteractActionName;
}

void UJamHelperFunctionLibrary::SaveGame(UObject* WorldContextObject)
{
	UWorld* World = (WorldContextObject != nullptr)
		? GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull)
		: nullptr;

	// TODO: do all this better...ew
	if (World)
	{
		UJamResourceSubsystem* ResourceSubsystem = World->GetSubsystem<UJamResourceSubsystem>();
		if (ResourceSubsystem)
		{


			UJamGameStateSaveGame* SaveGame = nullptr;
			if (UGameplayStatics::DoesSaveGameExist(SAVE_GAME_SLOT, 0))
			{
				SaveGame = Cast<UJamGameStateSaveGame>(UGameplayStatics::LoadGameFromSlot(SAVE_GAME_SLOT, 0));
			}
			else
			{
				SaveGame = Cast<UJamGameStateSaveGame>(UGameplayStatics::CreateSaveGameObject(UJamGameStateSaveGame::StaticClass()));
			}
			if (SaveGame)
			{
				SaveGame->bGameWon = ResourceSubsystem->GetGameWon();
			}
			UGameplayStatics::SaveGameToSlot(SaveGame, SAVE_GAME_SLOT, 0);
		}
	}
}

bool UJamHelperFunctionLibrary::IsGameWon(UObject* WorldContextObject)
{
	UWorld* World = (WorldContextObject != nullptr)
		? GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull)
		: nullptr;

	// TODO: do all this better...ew
	if (World)
	{
		UJamResourceSubsystem* ResourceSubsystem = World->GetSubsystem<UJamResourceSubsystem>();
		if (ResourceSubsystem)
		{
			UJamGameStateSaveGame* SaveGame = nullptr;
			if (UGameplayStatics::DoesSaveGameExist(SAVE_GAME_SLOT, 0))
			{
				SaveGame = Cast<UJamGameStateSaveGame>(UGameplayStatics::LoadGameFromSlot(SAVE_GAME_SLOT, 0));
			}
			else
			{
				SaveGame = Cast<UJamGameStateSaveGame>(UGameplayStatics::CreateSaveGameObject(UJamGameStateSaveGame::StaticClass()));
			}
			if (SaveGame)
			{
				return SaveGame->bGameWon;
			}
		}
	}
	return false;
}
