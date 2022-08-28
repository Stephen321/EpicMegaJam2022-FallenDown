// Fill out your copyright notice in the Description page of Project Settings.


#include "Interface_JamInteractor.h"


// Add default functionality here for any IJamInteractor functions that are not pure virtual.
void IInterface_JamInteractor::BeginInteraction_Implementation(UJamInteractableComponent* InteractableComponent)
{
	bCanInteract = true;
}
   
void IInterface_JamInteractor::EndInteraction_Implementation(UJamInteractableComponent* InteractableComponent)
{
	bCanInteract = false;	
}
