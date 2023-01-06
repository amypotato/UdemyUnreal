// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	InitialPosition = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector CurrentLocation = GetActorLocation();
	// Add vector to that location
	CurrentLocation = CurrentLocation + (MoveVector * DeltaTime);
	// Set the location
	SetActorLocation(CurrentLocation);
	// Send platform back if gone too far
	difference = FVector::Distance(CurrentLocation, InitialPosition);

	if (difference > distance){
		MoveVector = -MoveVector;
		FVector MoveDirection = MoveVector.GetSafeNormal();
		InitialPosition = CurrentLocation + MoveDirection * distance;
		SetActorLocation(InitialPosition);
	}
}

