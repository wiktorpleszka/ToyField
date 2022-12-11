// Fill out your copyright notice in the Description page of Project Settings.


#include "SoliderCharacter.h"

// Sets default values
ASoliderCharacter::ASoliderCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASoliderCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ASoliderCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASoliderCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASoliderCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &ASoliderCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &ASoliderCharacter::LookUp);

}

void ASoliderCharacter::MoveForward(float Value)
{
	if (Controller != nullptr && Value != 0.f)
	{
		const FRotator YawRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);
		const FVector Direction(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X));
	}
}

void ASoliderCharacter::MoveRight(float Value)
{
	if (Controller != nullptr && Value != 0.f)
	{
		const FRotator YawRotation(0.f, Controller->GetControlRotation().Yaw, 0.f);
		const FVector Direction(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y));
	}
}

void ASoliderCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void ASoliderCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

// Called every frame
void ASoliderCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


