// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ACustomPlayerCharacter::ACustomPlayerCharacter()
{
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);
}

void ACustomPlayerCharacter::MoveForward(float Value)
{
	if (!FMath::IsNearlyZero(Value, 1e-6f))
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void ACustomPlayerCharacter::MoveRight(float Value)
{
	if (!FMath::IsNearlyZero(Value, 1e-6f))
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void ACustomPlayerCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void ACustomPlayerCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

