// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Components/CapsuleComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	//Setting Health to standard value
	Health = MaxHealth;
	PlayerCharacterMovement = GetCharacterMovement();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Setting up all the movement and main key for the character (PC/Joypad)
	PlayerInputComponent->BindAxis(TEXT("MoveForeward"), this, &APlayerCharacter::MoveForeward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &APlayerCharacter::MoveRight);
	
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &APawn::AddControllerYawInput);

	PlayerInputComponent->BindAxis(TEXT("LookRightRate"), this, &APlayerCharacter::LookRightRate);
	PlayerInputComponent->BindAxis(TEXT("LookUpRate"), this, &APlayerCharacter::LookUpRate);

	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ACharacter::Jump);

	PlayerInputComponent->BindAction(TEXT("IncreaseSpeed"), IE_Pressed, this, &APlayerCharacter::IncreaseMovementSpeed);
	PlayerInputComponent->BindAction(TEXT("IncreaseSpeed"), IE_Released, this, &APlayerCharacter::NormalizeMovementSpeed);
	PlayerInputComponent->BindAction(TEXT("DecreaseSpeed"), IE_Pressed, this, &APlayerCharacter::DecreaseMovementSpeed);
	PlayerInputComponent->BindAction(TEXT("DecreaseSpeed"), IE_Released, this, &APlayerCharacter::NormalizeMovementSpeed);
}

void APlayerCharacter::MoveForeward(float AxisValue)
{
	if (AxisValue != 0.0f){
		AddMovementInput(GetActorForwardVector() * AxisValue);
		UE_LOG(LogTemp, Warning, TEXT("FWD"));
		UE_LOG(LogTemp, Warning, TEXT("FWD %f"), AxisValue);
	}
}

void APlayerCharacter::MoveRight(float AxisValue)
{
	if (AxisValue != 0.0f){
		AddMovementInput(GetActorRightVector() * AxisValue);
		UE_LOG(LogTemp, Warning, TEXT("RIGHT"));
		UE_LOG(LogTemp, Warning, TEXT("RIGHT %f"), AxisValue);
	}
}

void APlayerCharacter::IncreaseMovementSpeed() 
{
	PlayerCharacterMovement->MaxWalkSpeed = IncreasedSpeed * SpeedRate;
}

void APlayerCharacter::NormalizeMovementSpeed() 
{
	PlayerCharacterMovement->MaxWalkSpeed = NormalSpeed * SpeedRate;
}

void APlayerCharacter::DecreaseMovementSpeed()
{
	PlayerCharacterMovement->MaxWalkSpeed = DecrasedSpeed * SpeedRate;
}

void APlayerCharacter::LookUpRate(float AxisValue)
{
	AddControllerPitchInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}

void APlayerCharacter::LookRightRate(float AxisValue)
{
	AddControllerYawInput(AxisValue * RotationRate * GetWorld()->GetDeltaSeconds());
}