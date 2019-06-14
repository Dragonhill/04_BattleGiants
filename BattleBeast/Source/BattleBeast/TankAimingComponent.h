// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "TankBarrel.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//Forward Declaration instead of using #include
class UTankBarrel;
class UTankTurret;

// Holds params for barrels properties and elevate
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLEBEAST_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()


public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelRefernce(UTankBarrel *BarrelToset);

	void SetTurretReference(UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);

		
private:
	UTankBarrel* Barrel = nullptr;

	UTankTurret* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
};
