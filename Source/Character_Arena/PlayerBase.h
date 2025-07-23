// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Components/MeshComponent.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"

//camera
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

//imput functions
#include "Components/InputComponent.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

//combo system
#include "ComboManagerComponent.h"
#include "ComboTemplate.h"
#include "PlayerBase.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UInputMappingContext;
class UInputAction;

UCLASS()
class CHARACTER_ARENA_API APlayerBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//player statistics
	UPROPERTY(EditAnywhere, Category = "Player Statistics")
	float playerSpeed = 10;

	UPROPERTY(EditAnywhere, Category = "Player Statistics")
	float cameraSpeed = 10;

	//IMPUT HANDELING
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* inputMappingContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* cameraRotateXAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* cameraRotateYAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* playerMoveAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* attack1Action;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* attack2Action;

	//camera components
	UPROPERTY(EditAnywhere, Category = "Camera")
	UCameraComponent* cameraComponent;

	UPROPERTY(EditAnywhere, Category = "Camera")
	USpringArmComponent* springArmComponent;

	//pther player components
	UPROPERTY(EditAnywhere, Category = "Sound")
	UAudioComponent* playerAudeoComponent;

	UPROPERTY(EditAnywhere, Category = "Sound")
	TArray<USoundBase*> attack2SoundLibary;

	//combo system
	UPROPERTY(EditAnywhere)
	UComboManagerComponent* comboManager;

	//combo attack 1
	UPROPERTY(EditAnywhere, Category = "combo|combo attack 1")
	float AT1damage;
	UPROPERTY(EditAnywhere, Category = "combo|combo attack 1")
	float AT1stun;
	UPROPERTY(EditAnywhere, Category = "combo|combo attack 1")
	FString AT1name;
	UPROPERTY(EditAnywhere, Category = "combo|combo attack 1")
	TArray<USoundBase*> AT1SoundLibary;
	UPROPERTY(EditAnywhere, Category = "combo|combo attack 1")
	UAnimSequence* AT1animation;
;

private:
	void CameraRotateY(const FInputActionValue& Value);
	void CameraRotateX(const FInputActionValue& Value);
	void PlayerMove(const FInputActionValue& Value);
	void Aattack1(const FInputActionValue& Value);
	void Aattack2(const FInputActionValue& Value);

};
