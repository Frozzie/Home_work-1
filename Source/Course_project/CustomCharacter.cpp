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

void ACustomCharacter::OnSprintStart_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("ACustomCharacter::OnSprintStart_Implementation"))
}

void ACustomCharacter::OnSprintEnd_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("ACustomCharacter::OnSprintEnd_Implementation"))
}

void ACustomCharacter::StartSprint()
{
	bIsSprintRequested = true;
	if (bIsCrouched)
	{
		UnCrouch();
	}
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
		OnSprintStart();
	}
	else if (!bIsSprintRequested && bIsSprinting)
	{
		bIsSprinting = false;
		GetCharacterMovement()->MaxWalkSpeed = DefaultMaxMovementSpeed;
		OnSprintEnd();
	}
}

