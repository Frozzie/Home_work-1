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

	virtual void StartSprint();
	virtual void StopSprint();

	virtual void Tick(float DeltaTime) override;

	virtual bool CanSprint();

	FORCEINLINE bool GetIsSprinting() const { return bIsSprinting; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character | Controls")
	float BaseTurnRate = 45.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character | Controls")
	float BaseLookUpRate = 45.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character | Movement")
	float SprintSpeed = 350.f;

	

private:
	float DefaultMaxMovementSpeed = 150.f;
	bool bIsSprintRequested = false;
	bool bIsSprinting = false;
};
