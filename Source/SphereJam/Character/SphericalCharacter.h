// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SphericalCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class ASphericalSphere;

UCLASS()
class SPHEREJAM_API ASphericalCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASphericalCharacter();

private:
	UPROPERTY(Category = "Components", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	UPROPERTY(Category = "Components", VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* MainCamera;

public:
	UPROPERTY(Category = "Properties", EditAnywhere, BlueprintReadWrite)
	ASphericalSphere* Sphere;

public:
	UFUNCTION(BlueprintCallable)
	void AddForwardMovementInput(float Scale, bool bForce);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
