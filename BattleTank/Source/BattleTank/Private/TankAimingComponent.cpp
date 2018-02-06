// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"

void UTankAimingComponent::SetBarrel(UStaticMeshComponent* BarrelToSet) {
	Barrel = BarrelToSet;
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection) {
	auto BarrelRotation = Barrel->GetForwardVector().Rotation();
	auto TargetRotation = AimDirection.Rotation();
	auto DeltaRotation = TargetRotation - BarrelRotation;
}

void UTankAimingComponent::AimAt(FVector EndVector, float LaunchSpeed) {
	//UE_LOG(LogTemp, Warning, TEXT("%s Aiming at %s"), *GetOwner()->GetName(), *EndVector.ToString());
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool HaveAimingSolution = UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, EndVector, LaunchSpeed, false,0.0,0.0,ESuggestProjVelocityTraceOption::DoNotTrace);
	auto AimDirection = OutLaunchVelocity.GetSafeNormal();
	if (HaveAimingSolution) {
		MoveBarrel(OutLaunchVelocity);
		DrawDebugLine(GetWorld(), Barrel->GetComponentLocation(), OutLaunchVelocity, FColor(255, 0, 0), false, 0.0, 0.0, 10.0);
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

