// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

// Forward declaration
class UTankBarrel;
class UTankTurret;
class UTankTrack;
class UTankAimingComponent;
class UTankMovementComponent;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void AimAt(FVector OutHitLocation);

	UFUNCTION(BlueprintCallable) ///Category can be added
		void Fire();


protected:


	UPROPERTY(BlueprintReadOnly)	///Component can now be called in Blueprint
	UTankAimingComponent* TankAimingComponent = nullptr;	///Somewhere to store the pointer

	UPROPERTY(BlueprintReadOnly)	///Component can now be called in Blueprint
	UTankMovementComponent* TankMovementComponent = nullptr;///Somewhere to store the pointer

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		TSubclassOf<AProjectile> ProjectileBlueprint;	/// Can choose class from AProjectile

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float LaunchSpeed = 4000;	/// TODO find sensible default value

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
		float ReloadTimeInSeconds = 3;	/// Limit Firing Rate

	//Local Barrel reference for spawning projectile
	UTankBarrel* Barrel = nullptr;

	double LastFireTime = 0;			/// Limit Firing Rate

};
