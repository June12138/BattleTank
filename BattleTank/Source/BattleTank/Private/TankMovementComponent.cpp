// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "Track.h"

void UTankMovementComponent::IntendMoveForward(float Throw) {
	UE_LOG(LogTemp, Warning, TEXT("Intended throw: %f"), Throw);
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::Init(UTrack* LeftTrackToSet, UTrack* RightTrackToSet) {
	if (!LeftTrackToSet || !RightTrackToSet) { return; }
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}