// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Platform_C.generated.h"

UCLASS()
class COURSE_PROJECT_API APlatform_C : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatform_C();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* PlatformMesh;

	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector MoveVelocity = FVector(100.0f, 0.0f, 0.0f);

	UPROPERTY(EditAnywhere, Category = "Movement")
	float MaxDistance = 500.0f;

	FVector StartLocation;
};
