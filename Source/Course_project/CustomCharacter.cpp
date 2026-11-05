// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomCharacter.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"

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

void ACustomCharacter::RegisterInteractiveActor(AInteractiveActor* InteractiveActor)
{
	AvailableInteractiveActors.Add(InteractiveActor);
}

void ACustomCharacter::UnregisterInteractiveActor(AInteractiveActor* InteractiveActor)
{
	AvailableInteractiveActors.Remove(InteractiveActor);
}

void ACustomCharacter::OnSprintStart_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("ACustomCharacter::OnSprintStart_Implementation"))
}

void ACustomCharacter::OnSprintEnd_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("ACustomCharacter::OnSprintEnd_Implementation"))
}

void ACustomCharacter::OnMovementModeChanged(EMovementMode PrevMovementMode, uint8 PreviousCustomMode)
{
	Super::OnMovementModeChanged(PrevMovementMode, PreviousCustomMode);

	// figure out how to change collisions, the method below doesnt work

	//if(GetCharacterMovement()->MovementMode == MOVE_Swimming)
	//{
		//Crouch();
		//CharacterOwner->GetCapsuleComponent()->SetCapsuleSize(SwimmingCapsuleRadius, SwimmingCapsuleHalfHeight);
	//}
	//else if (PreviousCustomMode == MOVE_Swimming && GetCharacterMovement()->MovementMode != MOVE_Swimming)
	//{
		//UnCrouch();
		// i tried to make this work, it just doesnt
		//ACharacter* DefaultCharacter = CharacterOwner->GetClass()->GetDefaultObject<ACharacter>();
		//CharacterOwner->GetCapsuleComponent()->SetCapsuleSize(DefaultCharacter->GetCapsuleComponent()->GetUnscaledCapsuleRadius(), DefaultCharacter->GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight(), true);
	//}
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

	GEngine->AddOnScreenDebugMessage(1, 1.0f, FColor::Yellow, FString::Printf(TEXT("Stamina: %.2f"), CurrentStamina));
}

