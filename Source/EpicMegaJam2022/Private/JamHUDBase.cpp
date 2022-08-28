// Fill out your copyright notice in the Description page of Project Settings.


#include "JamHUDBase.h"

#include "JamWidgetLevelHUD.h"

AJamHUDBase::AJamHUDBase()
{
}

void AJamHUDBase::BeginInteraction(UJamInteractableComponent* InteractableComponent)
{
	if (WidgetLevelHUD.IsValid())
	{
		WidgetLevelHUD->OnBeginInteraction(InteractableComponent);	
	}
}

void AJamHUDBase::EndInteraction(UJamInteractableComponent* InteractableComponent)
{
	if (WidgetLevelHUD.IsValid())
	{
		WidgetLevelHUD->OnEndInteraction(InteractableComponent);	
	}
}

void AJamHUDBase::SetWidgetLevelHUD(UJamWidgetLevelHUD* InWidgetLevelHUD)
{
	WidgetLevelHUD = InWidgetLevelHUD;
	if (WidgetLevelHUD.IsValid())
	{
		WidgetLevelHUD->SetOwningHUD(this);
	}
}
