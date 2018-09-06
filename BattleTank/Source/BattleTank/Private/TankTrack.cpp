// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"


void UTankTrack::SetThrottle(float Throttle)
{
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s: Throttle: %f"), *Name, Throttle);


	//Clamp the actual throttle value so that player can't overdrive
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent()); ///The Tank, scene component can't have force, go to PrimitiveComponent

	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);


}

