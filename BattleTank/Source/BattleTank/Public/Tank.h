// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "TankAimingComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Projectile.h"
#include "TankBarrel.h"
#include "TankMovementComponent.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTurrent;
class UTankMovementComponent;

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
	UFUNCTION(BluePrintCallable, Category = Input)
		void Fire();
	//speed of the projectile
	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 100000.0;
	UPROPERTY(EditAnywhere)
		UClass * ProjectileBlueprint;
private:
	double LastFireTime = 0.0;
	UPROPERTY(EditAnywhere)
		double ReloadTimeSeconds = 3.0;
	//Local tank barrel pointer
	UTankBarrel* Barrel = nullptr;
protected:
	UPROPERTY(BlueprintReadOnly)
	UTankMovementComponent* TankMovementComponent = nullptr;
};
