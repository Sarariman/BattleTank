// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	/// Find Tank possessed by player

}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = GetPlayerTank();
	auto ControlledTank = GetControlledTank();

	if (PlayerTank)
	{
		// Move towards the player

		MoveToActor(PlayerTank, AcceptanceRadius);

		// Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		// Fire
		ControlledTank->Fire();
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}


///ALTERNATE BELOW

/*

// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "GameFramework/Actor.h"



void ATankAIController::BeginPlay()
{
Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
Super::Tick(DeltaTime);

auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
auto ControlledTank = Cast<ATank>(GetPawn());

if (PlayerTank)
{
// Move towards the player

// Aim towards the player
ControlledTank->AimAt(PlayerTank->GetActorLocation());

// Fire
ControlledTank->Fire();
}
}

*/


///LOGGING
/*/// Find Tank possessed by player
auto PlayerTank = GetPlayerTank();
if (!PlayerTank)
{
	UE_LOG(LogTemp, Warning, TEXT("AIController can't find PlayerTank!"));
}
else
{
	UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerTank->GetName()));
}
/// UE_LOG(LogTemp, Warning, TEXT("AIController begin play!"))

*/