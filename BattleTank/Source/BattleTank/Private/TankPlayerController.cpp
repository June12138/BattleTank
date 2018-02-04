// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

//get crosshair world location in 3d
bool ATankPlayerController::GetCrosshairHitLocation(FVector& HitLocation) {
	FHitResult HitResult;
	FVector2D ScreenLocation;
	FVector CrosshairWorldLocation;//doesn't do anything, to be discarded
	FVector CrosshairWorldDirection;
	GetCrosshairScreenLocation(ScreenLocation);
	DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CrosshairWorldLocation, CrosshairWorldDirection);
	if (GetWorld()->LineTraceSingleByChannel(HitResult,
		PlayerCameraManager->GetCameraLocation(),
		PlayerCameraManager->GetCameraLocation()+(CrosshairWorldDirection*300000),
		ECollisionChannel::ECC_Visibility)) {
		HitLocation = HitResult.Location;
		return true;
	}
	return false;
}
//Get crosshair 2d screen location
void ATankPlayerController::GetCrosshairScreenLocation(FVector2D& ScreenLocation) {
	int32 X, Y;
	GetViewportSize(X, Y);
	ScreenLocation = FVector2D(X*0.5, Y*0.333333);
}
ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}
void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	ATank* ControlledTank = GetControlledTank();
	if (ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("player controller begin play %s"), *ControlledTank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Player controlled tank not found"));
	}
}
void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	if (GetCrosshairHitLocation(CrosshairHitLocation)) {
		UE_LOG(LogTemp, Warning, TEXT("Crosshair hit at:%s"), *CrosshairHitLocation.ToString());
	}
}