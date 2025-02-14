// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "Components/StaticMeshComponent.h"
#include "CoreMinimal.h"
#include "Engine/World.h"
#include "BattleBeast.h"
#include "TankAimingComponent.h"

void ATank::SetBarrelRefernce(UTankBarrel * BarrelToset)
{
	TankAimingComponent->SetBarrelRefernce(BarrelToset);
	Barrel = BarrelToset;
	UE_LOG(LogTemp, Warning, TEXT("Barrel Set!!!!"));
	if (!Barrel) {
		UE_LOG(LogTemp, Warning, TEXT("Barrel is not valid!!!!"));
	}
}

void ATank::SetTurretReference(UTankTurret* TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimingComponent = CreateAbstractDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
	
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector HitLocation)
{
	auto OurTankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s"), *OurTankName, *HitLocation.ToString());
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void ATank::Fire()
{
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f: Tank fires"), Time);

	// TODO - this is failing!!!!!!
	if (!Barrel) 
	{ 
		UE_LOG(LogTemp, Warning, TEXT("Boom Failed!!!!"));
		return; 
	}

	// Spawn a projectile at the socket location on the barrel
	GetWorld()->SpawnActor<AProjectile>(
		ProjectileBlueprint,
		Barrel->GetSocketLocation(FName("Projectile")),
		Barrel->GetSocketRotation(FName("Projectile"))
		);
	UE_LOG(LogTemp, Warning, TEXT("Boom!!!!"));
}

