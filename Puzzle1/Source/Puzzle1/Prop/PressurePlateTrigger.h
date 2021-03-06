// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "Puzzle1/Component/MovableStaticMeshComponent.h"
#include "PressurePlateTrigger.generated.h"

UCLASS()
class PUZZLE1_API APressurePlateTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APressurePlateTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	UFUNCTION()
	void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:
	void Interact(bool bIsInteracting);

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(AllowPrivateAcess = "true"), Category = "Trigger")
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(AllowPrivateAcess = "true"), Category = "Trigger")
	UMovableStaticMeshComponent* MoveableMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta=(AllowPrivateAcess = "true"), Category = "Trigger")
	USphereComponent* OverlapComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Trigger")
	bool bIsDisabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Trigger")
	bool bResetTrigger;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Trigger")
	TArray<FName> TargetTags;

private:
	bool bIsTriggered;
};
