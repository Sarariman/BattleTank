// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeSpeed)
{

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto RotationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	
	///NO CLAMP
	///auto Rotation = FMath::Clamp<float>(Rotation, MinDegreesPerSecond, MaxRotationDegrees);

	SetRelativeRotation(FRotator(0, Rotation, 0));
}


