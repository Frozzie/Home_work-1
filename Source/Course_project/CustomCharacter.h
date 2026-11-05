// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CustomCharacter.generated.h"

class AInteractiveActor;
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

	UFUNCTION(BlueprintCallable, Category = "Character | Movement")
	virtual void StartSprint();
	UFUNCTION(BlueprintCallable, Category = "Character | Movement")
	virtual void StopSprint();

	virtual void Tick(float DeltaTime) override;

	virtual void SwimForward(float Value) {};

	virtual void SwimRight(float Value) {};

	virtual void SwimUp(float Value) {};

	virtual bool CanSprint();

	FORCEINLINE bool GetIsSprinting() const { return bIsSprinting;}

	void RegisterInteractiveActor(AInteractiveActor* InteractiveActor);
	void UnregisterInteractiveActor(AInteractiveActor* InteractiveActor);

protected:

	UFUNCTION(BlueprintNativeEvent, Category = "Character | Movement")
	void OnSprintStart();
	virtual void OnSprintStart_Implementation();

	UFUNCTION(BlueprintNativeEvent, Category = "Character | Movement")
	void OnSprintEnd();
	virtual void OnSprintEnd_Implementation();

	virtual void OnMovementModeChanged(EMovementMode PrevMovementMode, uint8 PreviousCustomMode = 0) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character | Movement")
	float SprintSpeed = 350.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character | Movement")
	float CurrentStamina = 100.f;

	UPROPERTY(Category = "Character | Movement | Swimming", EditAnywhere, BlueprintReadWrite, meta = (ClampMin="0.0"))
	float SwimmingCapsuleRadius = 60.f;

	UPROPERTY(Category = "Character | Movement | Swimming", EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0.0"))
	float SwimmingCapsuleHalfHeight = 60.f;

private:
	float DefaultMaxMovementSpeed = 150.f;
	bool bIsSprintRequested = false;
	bool bIsSprinting = false;

	TArray<AInteractiveActor*> AvailableInteractiveActors;
};
