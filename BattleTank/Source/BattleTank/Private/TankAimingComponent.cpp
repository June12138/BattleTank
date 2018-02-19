// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"

void UTankAimingComponent::SetBarrel(UTankBarrel* BarrelToSet) {
	Barrel = BarrelToSet;
}

void UTankAimingComponent::SetTurrent(UTurrent* TurrentToSet) {
	Turrent = TurrentToSet;
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection) {
	auto BarrelRotation = Barrel->GetForwardVector().Rotation();
	auto TargetRotation = AimDirection.Rotation();
	auto DeltaRotation = TargetRotation - BarrelRotation;
	Barrel->ElevateBarrel(DeltaRotation.Pitch);
}

void UTankAimingComponent::MoveTurrent(FVector AimDirection) {
	auto TurrentRotation = Turrent->GetForwardVector().Rotation();
	auto TargetRotation = AimDirection.Rotation();
	auto DeltaRotation = TargetRotation - TurrentRotation;
	Turrent->RotateTurrent(DeltaRotation.Yaw);
}

void UTankAimingComponent::AimAt(FVector EndVector, float LaunchSpeed) {
	//UE_LOG(LogTemp, Warning, TEXT("%s Aiming at %s"), *GetOwner()->GetName(), *EndVector.ToString());
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool HaveAimingSolution = UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, EndVector, LaunchSpeed, false,0.0,0.0,ESuggestProjVelocityTraceOption::DoNotTrace);
	auto AimDirection = OutLaunchVelocity.GetSafeNormal();
	if (HaveAimingSolution) {
		//  move turret and barrel to aim at the location
		MoveBarrel(OutLaunchVelocity);
		MoveTurrent(OutLaunchVelocity);
	}
}

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

