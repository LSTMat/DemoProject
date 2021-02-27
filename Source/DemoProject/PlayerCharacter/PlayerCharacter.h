// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class DEMOPROJECT_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Sets default values for this character's properties
	APlayerCharacter();

private:

	//Sensibility for scrolling
	UPROPERTY(EditAnywhere)
		float RotationRate = 40;
	
	//MAIN function for movement
	void MoveForeward(float AxisValue);
	void MoveRight(float AxisValue);
	void LookUpRate(float AxisValue);
	void LookRightRate(float AxisValue);

	//Values for different types of speed
	UPROPERTY(EditAnywhere)
		float SpeedRate = 1;
	UPROPERTY(EditAnywhere)
		float IncreasedSpeed = 800.0f;
	UPROPERTY(EditAnywhere)
		float NormalSpeed = 550.0f;
	UPROPERTY(EditAnywhere)
		float DecrasedSpeed = 300.0f;
	UPROPERTY(VisibleAnywhere)
		UCharacterMovementComponent* PlayerCharacterMovement;
	//functions for modify speeds
	void IncreaseMovementSpeed();
	void NormalizeMovementSpeed();
	void DecreaseMovementSpeed();

	//Property of Character
	UPROPERTY(EditDefaultsOnly)
		float MaxHealth = 100;
	UPROPERTY(VisibleAnywhere)
		float Health;

};
