// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "Components/SkeletalMeshComponent.h"

#include "ComboTemplate.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CHARACTER_ARENA_API UComboTemplate : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UComboTemplate();
	~UComboTemplate();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	

	UPROPERTY(EditAnywhere)
	FString attackName = "Default name";

	//stores the attack sound effects, to be played on activation
	UPROPERTY(EditAnywhere)
	TArray<USoundBase*> attack2SoundLibary;

	UPROPERTY(EditAnywhere)
	float attackDamage = 10;

	//the amount of time a hit enemy is stunned in seconds on a hit
	UPROPERTY(EditAnywhere)
	float attackStun = 2;

	//the animation to be played, must be settup bethore hand with activation frames
	UPROPERTY(EditAnywhere)
	UAnimSequence* attackAnimation;

	//is this move a folowup to a prior move in a combo
	UPROPERTY(EditAnywhere)
	bool isFollowupMove = false;

	//what move should this follow up on, leve null if it is the start of a combo
	UPROPERTY(EditAnywhere)
	UComboTemplate* lastMove;

	UFUNCTION()
	void Init(float damage, float stun, FString name, TArray<USoundBase*> SoundLibary, UAnimSequence* animation);

	UFUNCTION()
	void PlayComboAnim(USkeletalMeshComponent* actorMesh);

		
};
