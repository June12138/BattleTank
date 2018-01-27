// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "PawnMovement.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UPawnMovement : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPawnMovement();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
private:
	void MoveForward();
	void MoveBackward();
	void RotateClockwise();
	void RotateAntiClockwise();
	UInputComponent* InputComponent = nullptr;
};
