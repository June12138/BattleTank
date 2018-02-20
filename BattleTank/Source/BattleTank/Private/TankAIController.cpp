// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
	//Find controlled tank
	ControlledTank = Cast<ATank>(GetPawn());
	//Find player tank
	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	ControlledTank->AimAt(PlayerTank->GetActorLocation());
	ControlledTank->Fire();
	MoveToActor(PlayerTank, AcceptedRadius,true,true,true,0,true);
}