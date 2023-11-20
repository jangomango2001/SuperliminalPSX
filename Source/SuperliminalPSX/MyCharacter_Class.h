// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter_Class.generated.h"

class UCameraComponent;
class UCharacterMovementComponent;

UCLASS()
class SUPERLIMINALPSX_API AMyCharacter_Class : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter_Class();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Playersettings")
		UCameraComponent* activeCam = NULL;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Playersettings")
		float MouseXSens = 25.f;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Playersettings")
		float MouseYSens = 25.f;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Playersettings")
		bool InverseMouseX = false;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite, meta = (AllowPrivateAccess = "true"), Category = "Playersettings")
		bool InverseMouseY = false;

	UCharacterMovementComponent* Movement;

	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);


	void Turn(float AxisValue);
	void LookUp(float AxisValue);
};
