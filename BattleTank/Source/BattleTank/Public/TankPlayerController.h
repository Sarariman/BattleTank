// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;	/// MUST be public for inheritance
										
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	ATank* GetControlledTank() const;

	// Start the tank moving the barrel so that a shot would hit
	// Where the crosshair intersects the world
	void AimTowardsCrosshair();

	// Return an Out parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;	///Mutate or change an FVector, Passing a reference to FVector

	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5f;	/// Remember widget anchor

	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.3f;	/// Remember widget anchor

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
};
