// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "TankAimingComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTurrent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UTankAimingComponent* TankAimingComponent = nullptr;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void AimAt(FVector EndLocation);
	UStaticMeshComponent* StaticMesh;
	UFUNCTION(BluePrintCallable, Category = Setup)
		void SetBarrelReference(UTankBarrel* BarrelToSet);
	UFUNCTION(BluePrintCallable, Category = Setup)
		void SetTurrentReference(UTurrent* TurrentToSet);
	//speed of the projectile
	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 100000.0;
};
