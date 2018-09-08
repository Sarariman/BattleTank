// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TankAimingComponent.generated.h"

//Enum for firing state
UENUM()
enum class EFiringState: uint8
{
	Reloading,
	Aiming,
	Locked
};

// Forward declaration
class UTankBarrel;
class UTankTurret;

//Holds Barrel's properties and elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	


	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialise(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);
	
	void AimAt(FVector OutHitLocation);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "State")	///Component can now be called in Blueprint
		EFiringState FiringState = EFiringState::Locked;

private:
	// Sets default values for this component's properties
	UTankAimingComponent();

	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Firing") ///COPY from Tank.h
	float LaunchSpeed = 4000;	/// TODO find sensible default value

	void MoveBarrelTowards(FVector AimDirection);
};
