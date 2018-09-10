// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

float ATank::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser)
{
	int32 DamagePoint = FMath::RoundToInt(DamageAmount);	/// DamageAmount is float, so it's rounded here
	
	int32 DamageToApply = FMath::Clamp(DamagePoint, 0, CurrentHealth);
	
	//UE_LOG(LogTemp, Warning, TEXT("DamageAmount: %f	DamageToApply: %i"), DamageAmount, DamageToApply);

	CurrentHealth -= DamageToApply;
	if (CurrentHealth <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tank died!"))
	}
	return DamageToApply;
}
