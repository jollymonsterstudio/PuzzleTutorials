// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Puzzle1/Component/MovableStaticMeshComponent.h"

#include "Puzzle1/Interface/InteractableInterface.h"

#include "MovingStaticMeshActor.generated.h"

UCLASS()
class PUZZLE1_API AMovingStaticMeshActor : public AActor, public IInteractableInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingStaticMeshActor();

	virtual FName GetInteractTag_Implementation() override;
	virtual void Interact_Implementation(bool bInteracting) override;

	bool IsDisabled() const { return bIsDisabled; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Moving")
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Moving")
	UMovableStaticMeshComponent* MovableMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Moving")
	FName InteractTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Moving")
	bool bIsDisabled;
};
