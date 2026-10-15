// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerAnimInstance.h"
#include "CustomCharacter.h"
#include "CustomPlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

void UCustomPlayerAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	checkf(TryGetPawnOwner()->IsA<ACustomPlayerCharacter>(), TEXT("UCustomPlayerAnimInstance::NativeBeginPlay() Pawn owner is not a ACustomPlayerCharacter"));
	CachedPlayerCharacter = Cast<ACustomPlayerCharacter>(TryGetPawnOwner());
}

void UCustomPlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (!CachedPlayerCharacter.IsValid())
	{
		return;
	}
	UCharacterMovementComponent* CharacterMovement = CachedPlayerCharacter->GetCharacterMovement();

	Speed = CachedPlayerCharacter->GetVelocity().Size();
	bIsFalling = CharacterMovement->IsFalling();
	bIsCrouching = CharacterMovement->IsCrouching();

	bIsSprinting = CachedPlayerCharacter->GetIsSprinting();
}
