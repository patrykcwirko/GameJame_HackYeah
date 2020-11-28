// Fill out your copyright notice in the Description page of Project Settings.


#include "SphericalCharacter.h"
#include "../Sphere/SphericalSphere.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ASphericalCharacter::ASphericalCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	if (CameraBoom)
	{
		CameraBoom->SetupAttachment(RootComponent);
	}

	MainCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Main Camera"));
	if (MainCamera)
	{
		MainCamera->SetupAttachment(CameraBoom);
	}

	GetCharacterMovement()->GravityScale = 0.f;
}

void ASphericalCharacter::AddForwardMovementInput(float Scale, bool bForce)
{
	AddMovementInput(GetActorForwardVector(), Scale, bForce);
}

// Called when the game starts or when spawned
void ASphericalCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASphericalCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Sphere)
	{
		FRotator rot = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), Sphere->GetActorLocation());
		SetActorRotation(FRotator(rot.Pitch - 90.f, rot.Yaw, rot.Roll));
		GetCharacterMovement()->AddForce(GetActorForwardVector() * -1 * 980.f);
	}
}

// Called to bind functionality to input
void ASphericalCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
