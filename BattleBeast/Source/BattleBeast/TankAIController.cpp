// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "CoreMinimal.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "BattleBeast.h"

// Forward Declarations
class ATank;

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	//auto ControlledTank = GetControlledTank();
	//if (!ControlledTank)
	auto PlayerTank = GetPlayerTank();
	
	if (!PlayerTank)
	{
		//UE_LOG(LogTemp, Warning, TEXT("AIController not possesing a tank"));
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank"));
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("AIController possessing: %s"), *(ControlledTank->GetName()));
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerTank->GetName()));
	}
	
}

// Tick
	//Super
	//AimTowardscrosshair


void ATankAIController::Tick( float deltaTime)
{
	Super::Tick(deltaTime);

	if (GetPlayerTank())
	{
		// TODO Move towards the player

		// Aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		// Fire if ready
	}
}

void ATankAIController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; } // Note the !, very important
	return Cast<ATank>(PlayerPawn);
}
