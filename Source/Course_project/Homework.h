// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Homework.generated.h"

UCLASS()
class COURSE_PROJECT_API AHomework : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHomework();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "MyCustomFunctions")
	void TestFunction();

	UPROPERTY(EditAnywhere)
	float floatA = 1.0;

	UPROPERTY(EditDefaultsOnly)
	int intA = 1;

	UPROPERTY(EditInstanceOnly)
	bool boolA = true;
};