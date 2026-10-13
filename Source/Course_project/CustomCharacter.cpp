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
