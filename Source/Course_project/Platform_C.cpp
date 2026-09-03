// Fill out your copyright notice in the Description page of Project Settings.


#include "Platform_C.h"

// Sets default values
APlatform_C::APlatform_C()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlatformMesh"));
	RootComponent = PlatformMesh;
}

// Called when the game starts or when spawned
void APlatform_C::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
}

// Called every frame
void APlatform_C::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	CurrentLocation += MoveVelocity * DeltaTime;
	SetActorLocation(CurrentLocation);

	float DistanceTraveled = FVector::Dist(StartLocation, CurrentLocation);

	if (DistanceTraveled >= MaxDistance)
	{
		FVector MoveDirection = MoveVelocity.GetSafeNormal();
		StartLocation = StartLocation + (MoveDirection * MaxDistance);
		SetActorLocation(StartLocation);

		MoveVelocity = -MoveVelocity;
	}
}

