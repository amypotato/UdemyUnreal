// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	FVector MoveVector = FVector(0.5, 0.5, 0);

	UPROPERTY(EditAnywhere)
	double distance = 100.0;

	UPROPERTY(VisibleAnywhere)
	double difference = 0.0;

	UPROPERTY(VisibleAnywhere)
	FVector InitialPosition = FVector();
};
