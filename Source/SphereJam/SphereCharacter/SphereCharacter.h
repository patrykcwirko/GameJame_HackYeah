// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SphereCharacter.generated.h"

UCLASS()
class SPHEREJAM_API ASphereCharacter : public APawn
{
	GENERATED_BODY()

public:
	ASphereCharacter();

public:
	void AddForwardMovementInput(float Scale, bool bForce);

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
