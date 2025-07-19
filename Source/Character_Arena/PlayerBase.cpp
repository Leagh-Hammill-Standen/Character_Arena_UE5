// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBase.h"


// Sets default values
APlayerBase::APlayerBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// set pawn possesion
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;

	// Create camera components
	springArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	springArmComponent->SetupAttachment(RootComponent);
	springArmComponent->TargetArmLength = 600.0f; // Distance from the player
	cameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	cameraComponent->SetupAttachment(springArmComponent);
}

// Called when the game starts or when spawned
void APlayerBase::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (PlayerController) {
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		Subsystem->AddMappingContext(inputMappingContext, 0);
	}
	
}

// Called every frame
void APlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	UEnhancedInputComponent* EIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	EIC->BindAction(cameraRotateXAction, ETriggerEvent::Triggered, this, &APlayerBase::CameraRotateX);
	EIC->BindAction(cameraRotateYAction, ETriggerEvent::Triggered, this, &APlayerBase::CameraRotateY);
	EIC->BindAction(playerMoveAction, ETriggerEvent::Triggered, this, &APlayerBase::PlayerMove);

}

void APlayerBase::CameraRotateX(const FInputActionValue& Value)
{
	//get input vallue
	float RotationValue = Value.Get<float>();
	FRotator NewRotation = springArmComponent->GetComponentRotation();
	NewRotation.Yaw += RotationValue;
	NewRotation.Roll = 0;
	springArmComponent->SetWorldRotation(NewRotation);
}

void APlayerBase::CameraRotateY(const FInputActionValue& Value)
{
	float RotationValue = Value.Get<float>();
	FRotator NewRotation = springArmComponent->GetComponentRotation();
	NewRotation.Pitch += RotationValue;
	NewRotation.Roll = 0;
	springArmComponent->SetWorldRotation(NewRotation);
	
}

void APlayerBase::PlayerMove(const FInputActionValue& Value)
{
	FVector2D inputValue = Value.Get<FVector2D>();

	FVector forwardVector(cameraComponent->GetForwardVector().X, cameraComponent->GetForwardVector().Y, 0);
	AddMovementInput(forwardVector, inputValue.Y);
	FVector rightVector(cameraComponent->GetRightVector().X, cameraComponent->GetRightVector().Y, 0);
	AddMovementInput(rightVector, inputValue.X);
	
	FRotator movementRotation(GetVelocity().Rotation());

	movementRotation.Yaw -= 90;

	GetMesh()->SetWorldRotation(movementRotation);
}
