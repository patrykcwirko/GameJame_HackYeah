// Fill out your copyright notice in the Description page of Project Settings.


#include "SphereCharacter.h"

// Sets default values
ASphereCharacter::ASphereCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ASphereCharacter::AddForwardMovementInput(float Scale, bool bForce)
{

}

// Called when the game starts or when spawned
void ASphereCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASphereCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASphereCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

