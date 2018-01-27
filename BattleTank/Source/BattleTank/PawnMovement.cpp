// Fill out your copyright notice in the Description page of Project Settings.

#include "PawnMovement.h"
#include "GameFramework/Actor.h"

void UPawnMovement::MoveForward() {
	GetOwner()->SetActorRelativeLocation(FVector(0.0, 0.0, 0.0));
	UE_LOG(LogTemp, Warning, TEXT("Move forward"));
}
// Sets default values for this component's properties
UPawnMovement::UPawnMovement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPawnMovement::BeginPlay()
{
	Super::BeginPlay();
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent) {
		InputComponent->BindAction("MoveForward", IE_Pressed, this, &UPawnMovement::MoveForward);
	}
	// ...
	
}


// Called every frame
void UPawnMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

