// Fill out your copyright notice in the Description page of Project Settings.


#include "JamPlayerCharacterBase.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

namespace PlayerCharacterInternal
{
	static FName CameraComponentName = TEXT("Camera");
	static FName SpringArmComponentName = TEXT("SpringArm");	
}

// Sets default values
AJamPlayerCharacterBase::AJamPlayerCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(PlayerCharacterInternal::SpringArmComponentName);
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(PlayerCharacterInternal::CameraComponentName);
	CameraComponent->SetupAttachment(SpringArmComponent);
}

// Called when the game starts or when spawned
void AJamPlayerCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AJamPlayerCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AJamPlayerCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

