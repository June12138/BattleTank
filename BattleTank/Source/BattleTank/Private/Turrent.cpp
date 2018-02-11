// Fill out your copyright notice in the Description page of Project Settings.

#include "Turrent.h"

void UTurrent::RotateTurrent(float RelativeRotationDegrees)
{
	RelativeRotationDegrees = FMath::Clamp<float>(RelativeRotationDegrees, -1, 1);
	auto Degrees = RelativeRotationDegrees * MaxRotationSpeed * GetWorld()->DeltaTimeSeconds;
	auto NewRotation = RelativeRotation.Yaw + Degrees;
	SetRelativeRotation(FRotator(0.0, NewRotation, 0.0));
}
