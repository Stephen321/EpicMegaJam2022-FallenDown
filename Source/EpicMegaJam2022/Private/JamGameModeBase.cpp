// Fill out your copyright notice in the Description page of Project Settings.


#include "JamGameModeBase.h"

#include "JamGameStateBase.h"
#include "UI/JamHUDBase.h"
#include "JamPlayerCharacterBase.h"
#include "JamPlayerControllerBase.h"
#include "JamPlayerStateBase.h"

AJamGameModeBase::AJamGameModeBase()
{
	GameStateClass = AJamGameStateBase::StaticClass();
	PlayerControllerClass = AJamPlayerControllerBase::StaticClass();
	PlayerStateClass = AJamPlayerStateBase::StaticClass();
	HUDClass = AJamHUDBase::StaticClass();
	DefaultPawnClass = AJamPlayerCharacterBase::StaticClass();
}
