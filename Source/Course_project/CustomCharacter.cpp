// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void ACustomCharacter::ChangeCrouchState()
{
	if(GetCharacterMovement()->IsCrouching())
	{
		UnCrouch();
	}
	else
	{
		Crouch();
	}
}

bool ACustomCharacter::CanSprint()
{
	return true;
}

void ACustomCharacter::StartSprint()
{
	bIsSprintRequested = true;
}

void ACustomCharacter::StopSprint()
{
	bIsSprintRequested = false;
}

void ACustomCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bIsSprintRequested && !bIsSprinting && CanSprint())
	{
		bIsSprinting = true;
		DefaultMaxMovementSpeed = GetCharacterMovement()->MaxWalkSpeed;
		GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
	}
	else if (!bIsSprintRequested && bIsSprinting)
	{
		bIsSprinting = false;
		GetCharacterMovement()->MaxWalkSpeed = DefaultMaxMovementSpeed;
	}
}

