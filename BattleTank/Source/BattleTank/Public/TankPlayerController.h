// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

///Responsible for helping the player aim


// Forward declaration
class ATank;
class UTankAimingComponent;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	UFUNCTION(BlueprintCallable, Category = "Setup")
		ATank * GetControlledTank() const;

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimCompRef);

public:
	virtual void BeginPlay() override;	/// MUST be public for inheritance
										
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	// Start the tank moving the barrel so that a shot would hit
	// Where the crosshair intersects the world
	void AimTowardsCrosshair();

	// Return an Out parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;	///Mutate or change an FVector, Passing a reference to FVector

	UPROPERTY(EditDefaultsOnly)
		float CrosshairXLocation = 0.5f;	/// Remember widget anchor
	UPROPERTY(EditDefaultsOnly)
		float CrosshairYLocation = 0.3f;	/// Remember widget anchor
	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000;		/// 10Km

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const;
};
