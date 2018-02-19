// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "Track.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"

void UTankMovementComponent::IntendMoveForward(float Throw) {
	GetOwner()->GetVelocity();
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) {
	auto TankName = GetOwner()->GetName();
	auto ForwardVector = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();
	auto DotProduct = FVector::DotProduct(ForwardVector, AIForwardIntention);
	auto CrossProduct = FVector::CrossProduct(ForwardVector, AIForwardIntention);
	UE_LOG(LogTemp, Warning, TEXT("Dot product: %f"), DotProduct);
	IntendMoveForward(DotProduct);
	IntendMoveRight(CrossProduct.Z);
}

void UTankMovementComponent::IntendMoveRight(float Throw) {
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::Init(UTrack* LeftTrackToSet, UTrack* RightTrackToSet) {
	if (!LeftTrackToSet || !RightTrackToSet) { return; }
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}