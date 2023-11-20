// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter_Class.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AMyCharacter_Class::AMyCharacter_Class()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter_Class::BeginPlay()
{
	Super::BeginPlay();
	Movement = Super::GetCharacterMovement();
}

// Called every frame
void AMyCharacter_Class::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter_Class::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("Move Forward"), this, &AMyCharacter_Class::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Move Backward"), this, &AMyCharacter_Class::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Move Right"), this, &AMyCharacter_Class::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Move Left"), this, &AMyCharacter_Class::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AMyCharacter_Class::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AMyCharacter_Class::LookUp);

}


//Movement 
void AMyCharacter_Class::MoveForward(float AxisValue)
{
	if (Movement->MovementMode == EMovementMode::MOVE_Swimming) {
		FVector forwardcam = activeCam->GetForwardVector();
		AddMovementInput(forwardcam, AxisValue);
	}
	else {
		FVector Forward = UKismetMathLibrary::GetForwardVector(FRotator(0, GetControlRotation().Yaw, 0));
		AddMovementInput(Forward, AxisValue);
	}
}

void AMyCharacter_Class::MoveRight(float AxisValue)
{
	FVector Right = UKismetMathLibrary::GetRightVector(FRotator(0, GetControlRotation().Yaw, 0));
	AddMovementInput(Right, AxisValue);
}

//Aiming
void AMyCharacter_Class::Turn(float AxisValue)
{
	float finalaim = 0.01 * AxisValue * MouseXSens;

	if (InverseMouseX) {
		finalaim = finalaim * -1.0;
	}
	AddControllerYawInput(finalaim);
}

void AMyCharacter_Class::LookUp(float AxisValue)
{
	float finalaim = 0.01 * AxisValue * MouseYSens;

	if (InverseMouseY) {
		finalaim = finalaim * -1.0;
	}
	AddControllerPitchInput(finalaim);
}

