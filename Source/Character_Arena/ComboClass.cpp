// Fill out your copyright notice in the Description page of Project Settings.


#include "ComboClass.h"

ComboClass::ComboClass(float damage, float stun, FString name, TArray<USoundBase*> SoundLibary, UAnimSequence* animation)
{
	attackDamage = damage;
	attackStun = stun;
	attackName = name;
	attack2SoundLibary = SoundLibary;
	attackAnimation = animation;
}

ComboClass::~ComboClass()
{
}
