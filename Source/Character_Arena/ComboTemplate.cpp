// Fill out your copyright notice in the Description page of Project Settings.


#include "ComboTemplate.h"

// Sets default values for this component's properties
UComboTemplate::UComboTemplate()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	
}


// Called when the game starts
void UComboTemplate::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UComboTemplate::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UComboTemplate::Init(float damage, float stun, FString name, TArray<USoundBase*> SoundLibary, UAnimSequence* animation)
{
	attackDamage = damage;
	attackStun = stun;
	attackName = name;
	attack2SoundLibary = SoundLibary;
	attackAnimation = animation;
}

void UComboTemplate::PlayComboAnim(USkeletalMeshComponent* actorMesh)
{
	actorMesh->PlayAnimation(attackAnimation, false);
}

// de-constructor
UComboTemplate::~UComboTemplate()
{
}

