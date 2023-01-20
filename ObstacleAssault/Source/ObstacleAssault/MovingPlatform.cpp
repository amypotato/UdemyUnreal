// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ActorName = GetName();

	UE_LOG(LogTemp, Display, TEXT("Created A Moving Platform Instance with Name %s"), *ActorName);
	UE_LOG(LogTemp, Display, TEXT("Configured Move Distance %f"), MoveDistance);
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime) {
	// Send platform back if gone too far
	if (ShouldPlatformReturn()) {
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MoveDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	} else {
		FVector CurrentLocation = GetActorLocation();
		// Add vector to that location
		CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
		// Set the location
		SetActorLocation(CurrentLocation);
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime) {
	FRotator CurrentRotation = GetActorRotation();
	UE_LOG(LogTemp, Display, TEXT("In Rotate Platform"));
}

bool AMovingPlatform::ShouldPlatformReturn() const {
	return GetDistanceMoved() > MoveDistance;
}

float AMovingPlatform::GetDistanceMoved() const {
	return FVector::Distance(StartLocation, GetActorLocation());
}