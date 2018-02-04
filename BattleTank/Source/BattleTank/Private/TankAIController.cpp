// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const{
	return Cast<ATank>(GetPawn());
}
ATank* ATankAIController::GetPlayerTank() const {
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	//Find controlled tank
	ControlledTank = GetControlledTank();
	//Find player tank
	PlayerTank = GetPlayerTank();
	//Check controlled tank
	if (ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI controlled tank:%s"),*ControlledTank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Controlled Tank not found"));
	}
	//Check player tank
	if (PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("Player tank:%s"), *PlayerTank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Player tank not found"));
	}
}
void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	ControlledTank->AimAt(PlayerTank->GetActorLocation());
}