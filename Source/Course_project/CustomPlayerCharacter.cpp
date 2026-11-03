// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
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
	if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling() && !FMath::IsNearlyZero(Value, 1e-6f))
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void ACustomPlayerCharacter::MoveRight(float Value)
{
	if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling() && !FMath::IsNearlyZero(Value, 1e-6f))
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

void ACustomPlayerCharacter::SwimForward(float Value)
{
	if (GetCharacterMovement()->IsSwimming() && !FMath::IsNearlyZero(Value, 1e-6f))
	{
		FRotator PitchYawRotator(GetControlRotation().Pitch, GetControlRotation().Yaw, 0.f);
		FVector ForwardVector = PitchYawRotator.RotateVector(FVector::ForwardVector);
		AddMovementInput(ForwardVector, Value);
	}
}

void ACustomPlayerCharacter::SwimRight(float Value)
{
	if (GetCharacterMovement()->IsSwimming() && !FMath::IsNearlyZero(Value, 1e-6f))
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void ACustomPlayerCharacter::SwimUp(float Value)
{
	if (GetCharacterMovement()->IsSwimming() && !FMath::IsNearlyZero(Value, 1e-6f))
	{
		AddMovementInput(FVector::UpVector, Value);
	}
}


