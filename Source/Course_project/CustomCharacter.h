// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CustomCharacter.generated.h"

UCLASS(Abstract, NotBlueprintable)
class COURSE_PROJECT_API ACustomCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	virtual void MoveForward(float Value) {};
	virtual void MoveRight(float Value) {};
	virtual void Turn(float Value) {};
	virtual void LookUp(float Value) {};
	virtual void TurnAtRate(float Value) {};
	virtual void LookUpAtRate(float Value) {};

	virtual void ChangeCrouchState();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character | Camera")
	float BaseTurnRate = 45.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character | Camera")
	float BaseLookUpRate = 45.f;

};
