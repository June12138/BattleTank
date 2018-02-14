// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"

void UTankBarrel::ElevateBarrel(float DegreesPerSecond) {
	float Time = GetWorld()->GetTimeSeconds();
	auto RelativeSpeed = FMath::Clamp<float>(DegreesPerSecond, -1.0, 1.0);
	auto ElevationChange = RelativeSpeed *GetWorld()->DeltaTimeSeconds * MaxDegreesPerSecond;
	auto NewRawElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(NewRawElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(Elevation, 0.0, 0.0));
}