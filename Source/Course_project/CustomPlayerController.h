// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CustomCharacter.h"
#include "CustomPlayerController.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class COURSE_PROJECT_API ACustomPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void SetPawn(APawn* InPawn) override;

protected:
	virtual void SetupInputComponent() override;

private:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void TurnAtRate(float Value);
	void LookUpAtRate(float Value);
	void ChangeCrouchState();
	void Jump();

	void StartSprint();
	void StopSprint();
	

	TSoftObjectPtr <ACustomCharacter> CashedBaseCharacter;
};
