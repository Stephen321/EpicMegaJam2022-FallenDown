// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/JamHUDBase.h"
#include "UI/JamWidgetLevelHUD.h"

AJamHUDBase::AJamHUDBase()
{
}

void AJamHUDBase::SetWidgetLevelHUD(UJamWidgetLevelHUD* InWidgetLevelHUD)
{
	WidgetLevelHUD = InWidgetLevelHUD;
	if (WidgetLevelHUD.IsValid())
	{
		WidgetLevelHUD->SetOwningHUD(this);
	}
}
