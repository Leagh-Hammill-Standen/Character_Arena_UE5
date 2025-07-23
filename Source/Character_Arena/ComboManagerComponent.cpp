// Fill out your copyright notice in the Description page of Project Settings.


#include "ComboManagerComponent.h"

// Sets default values for this component's properties
UComboManagerComponent::UComboManagerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UComboManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(resetHandle, this, &UComboManagerComponent::ResetLastInput, 7, true);

	// ...
	
}


// Called every frame
void UComboManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UComboManagerComponent::ResetLastInput()
{
	lastImputDirectionInuput = null;
	lastMoveInput = nullptr;
}

void UComboManagerComponent::addNewMove(float damage, float stun, FString name, TArray<USoundBase*> SoundLibary, UAnimSequence* animation)
{
	UPROPERTY(EditAnywhere)
	UComboTemplate* newMove = NewObject<UComboTemplate>(this);
	newMove->Init(damage, stun, name, SoundLibary, animation);
	MoveList.Add(newMove);
}

UComboTemplate* UComboManagerComponent::getMoveByName(FString MoveName)
{
	for (int i = 0; i < MoveList.Num() - 1; i++)
	{
		if (MoveList[i]->attackName == MoveName)
		{
			return MoveList[i];
		}
	}
	return nullptr;
}

