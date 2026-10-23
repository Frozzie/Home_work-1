// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerController.h"
#include "CustomCharacter.h"

void ACustomPlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
	CashedBaseCharacter = Cast<ACustomCharacter>(InPawn);
}

void ACustomPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	InputComponent->BindAxis("MoveForward", this, &ACustomPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ACustomPlayerController::MoveRight);
	InputComponent->BindAxis("Turn", this, &ACustomPlayerController::Turn);
	InputComponent->BindAxis("LookUp", this, &ACustomPlayerController::LookUp);
	InputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &ACustomPlayerController::Jump);
	InputComponent->BindAction("Crouch", EInputEvent::IE_Pressed, this, &ACustomPlayerController::ChangeCrouchState);
	InputComponent->BindAction("Sprint", EInputEvent::IE_Pressed, this, &ACustomPlayerController::StartSprint);
	InputComponent->BindAction("Sprint", EInputEvent::IE_Released, this, &ACustomPlayerController::StopSprint);
}

void ACustomPlayerController::MoveForward(float Value)
{
	if (CashedBaseCharacter.IsValid())
	{
		CashedBaseCharacter->MoveForward(Value);
	}
}

void ACustomPlayerController::MoveRight(float Value)
{
	if (CashedBaseCharacter.IsValid())
	{
		CashedBaseCharacter->MoveRight(Value);
	}
}

void ACustomPlayerController::Turn(float Value)
{
	if (CashedBaseCharacter.IsValid())
	{
		CashedBaseCharacter->Turn(Value);
	}
}

void ACustomPlayerController::LookUp(float Value)
{
	if (CashedBaseCharacter.IsValid())
	{
		CashedBaseCharacter->LookUp(Value);
	}
}

void ACustomPlayerController::TurnAtRate(float Value)
{
	if (CashedBaseCharacter.IsValid())
	{
		CashedBaseCharacter->TurnAtRate(Value);
	}
}

void ACustomPlayerController::LookUpAtRate(float Value)
{
	if (CashedBaseCharacter.IsValid())
	{
		CashedBaseCharacter->LookUpAtRate(Value);
	}
}

void ACustomPlayerController::ChangeCrouchState()
{
	if (CashedBaseCharacter.IsValid())
	{
		CashedBaseCharacter->ChangeCrouchState();
	}
}

void ACustomPlayerController::Jump()
{
	if (CashedBaseCharacter.IsValid())
	{
		CashedBaseCharacter->Jump();
	}
}

void ACustomPlayerController::StartSprint()
{
	if (CashedBaseCharacter.IsValid())
	{
		CashedBaseCharacter->StartSprint();
	}
}

void ACustomPlayerController::StopSprint()
{
	if (CashedBaseCharacter.IsValid())
	{
		CashedBaseCharacter->StopSprint();
	}
}
