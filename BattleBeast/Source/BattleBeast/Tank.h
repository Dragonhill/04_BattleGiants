// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;

UCLASS()
class BATTLEBEAST_API ATank : public APawn
{
	GENERATED_BODY()

public:

	void AimAt(FVector HitLoaction);

	UFUNCTION(Blueprintcallable, Category = Setup)
	void SetBarrelRefernce(UTankBarrel *BarrelToSet);

protected:
	UTankAimingComponent  *TankAimingComponent = nullptr;

private:	
	// Sets default values for this pawn's properties
	ATank();

	virtual void BeginPlay() override;

	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 100000; // TODO find sensible default

};
