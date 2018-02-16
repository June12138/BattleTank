// Fill out your copyright notice in the Description page of Project Settings.

#include "Track.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"
#include "Runtime/Engine/Classes/Components/SceneComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"

void UTrack::SetThrottle(float Throttle) {
	UE_LOG(LogTemp, Warning, TEXT("Throttle: %f"), Throttle);
	auto DrivingForce = Throttle * MaxForce * GetForwardVector();
	FVector ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	if (TankRoot) {
		TankRoot->AddForceAtLocation(DrivingForce, ForceLocation);
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("Root component not found!"));
	}
}