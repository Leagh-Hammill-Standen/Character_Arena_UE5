// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "Engine/TimerHandle.h"
#include "Engine/World.h"
#include "ComboTemplate.h"
#include "Components/SkeletalMeshComponent.h"

#include "ComboManagerComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CHARACTER_ARENA_API UComboManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UComboManagerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	enum imputDirections { forward, back, left, right, null };
	imputDirections lastImputDirectionInuput = null;
	UComboTemplate* lastMoveInput;

	FTimerHandle resetHandle;
	void ResetLastInput();

	UPROPERTY(EditAnywhere)
	TArray<UComboTemplate*> MoveList;

	UFUNCTION()
	void addNewMove(float damage, float stun, FString name, TArray<USoundBase*> SoundLibary, UAnimSequence* animation);

	UFUNCTION()
	UComboTemplate* getMoveByName(FString MoveName);

private:
	
		
};
