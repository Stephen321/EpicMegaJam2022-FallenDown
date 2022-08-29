// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "UObject/WeakInterfacePtr.h"
#include "JamInteractableComponent.generated.h"

class IInterface_JamInteractAction;
class UInterface_JamInteractAction;
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteract);

UCLASS(ClassGroup=(Jam), meta=(BlueprintSpawnableComponent))
class EPICMEGAJAM2022_API UJamInteractableComponent : public UBoxComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UJamInteractableComponent();
	virtual ~UJamInteractableComponent() override;

	UPROPERTY(BlueprintAssignable, Category="Jam")
	FOnInteract OnInteract;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category="Jam")
	bool IsInteractable() const;
	
	UFUNCTION(BlueprintCallable, Category="Jam")
	void SetInteractable(bool bInInteractable);

	UFUNCTION(BlueprintCallable, Category="Jam")
	void Interact(AActor* Interactor);

private:
	UFUNCTION()
	void ComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	
	UFUNCTION()
	void ComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess), Category="Jam")
	bool bCanInteractOnlyOnce = false;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess), Category="Jam")
	float InteractCooldown = 3.f;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess), Category="Jam")
	FText InteractText;

private:
	bool bInteractable;
	FTimerHandle TimerHandle;

	UPROPERTY()
	TWeakObjectPtr<AActor> OverlappingActor;
	
	UPROPERTY()
	TObjectPtr<UObject> InteractActionInterface;
};
