// Fill out your copyright notice in the Description page of Project Settings.


#include "Homework.h"

// Sets default values
AHomework::AHomework()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AHomework::BeginPlay()
{
	Super::BeginPlay();


	TestFunction();

}

// Called every frame
void AHomework::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AHomework::TestFunction()
{
	GEngine->AddOnScreenDebugMessage(0, 5.0f, FColor::Green, FString::Printf(TEXT("Hello %i"), intA));
}
