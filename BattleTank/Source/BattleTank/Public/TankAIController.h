// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"


UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;	///MUST be public for inheritance

	virtual void Tick(float DeltaTime) override;

private:

	float AcceptanceRadius = 3000; ///How close AITank can get to the player
};