// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "Turrent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTurrent : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	float MaxRotationSpeed = 10;
	void RotateTurrent(float RelativeRotation);
};
