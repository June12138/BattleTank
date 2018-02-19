// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	//Find controlled tank
	ControlledTank = Cast<ATank>(GetPawn());
	//Find player tank
	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
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
	ControlledTank->Fire();
	MoveToActor(PlayerTank, AcceptedRadius,true,true,true,0,true);
}