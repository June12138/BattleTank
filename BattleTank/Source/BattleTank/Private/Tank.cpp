// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
//Set barrel to
void ATank::SetBarrelReference(UTankBarrel* BarrelToSet) {
	TankAimingComponent->SetBarrel(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::SetTurrentReference(UTurrent* TurrentToSet) {
	TankAimingComponent->SetTurrent(TurrentToSet);
}

void ATank::AimAt(FVector EndLocation) {
	TankAimingComponent->AimAt(EndLocation, LaunchSpeed);
}

void ATank::Fire() {
	UE_LOG(LogTemp, Warning, TEXT("Fire!!!"));
	bool IsReloaded = (GetWorld()->GetTimeSeconds() - LastFireTime) > ReloadTimeSeconds;
	if (IsReloaded && Barrel) {
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Barrel->GetSocketLocation(FName("Projectile")), Barrel->GetSocketRotation(FName("Projectile")));
		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = GetWorld()->GetTimeSeconds();
	}
}

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("TankAimingComponent"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	StaticMesh = FindComponentByClass<UStaticMeshComponent>();
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (StaticMesh) {
		SetActorLocation(StaticMesh->GetComponentLocation());
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("Static mesh not found!"));
	}
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

