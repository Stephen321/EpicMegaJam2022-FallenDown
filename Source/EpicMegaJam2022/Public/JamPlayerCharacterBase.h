// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interface_JamInteractor.h"
#include "GameFramework/Character.h"
#include "JamPlayerCharacterBase.generated.h"

UCLASS()
class EPICMEGAJAM2022_API AJamPlayerCharacterBase : public ACharacter, public IInterface_JamInteractor
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AJamPlayerCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// Called to bind functionality to input

private:
	UPROPERTY(Category = Jam, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent;
	
	UPROPERTY(Category = Jam, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArmComponent;
};
