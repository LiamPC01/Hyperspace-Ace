// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "Engine/Engine.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AMyCharacter::CountDown, 1.f, true, 0.0);

	ActorDestination = GetActorLocation();

	bIsPlayer = true;

}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	ActorLocation = GetActorLocation();

	if (ForwardSpeed < 50.f)
	{
		ForwardSpeed += 0.05f; // Increasing speed of player every tick
	}

	if (ForwardSpeed <= 0)
	{
		bIsPlayer = false;
	}


	MoveForward();

	// Moving actor left & right
	SetActorLocation(FMath::VInterpTo(ActorLocation, ActorDestination, DeltaTime, InterpSpeed));

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("MoveLeft", IE_Pressed, this, &AMyCharacter::MoveLeft);
	PlayerInputComponent->BindAction("MoveRight", IE_Pressed, this, &AMyCharacter::MoveRight);
}

void AMyCharacter::MoveLeft()
{
	if (Lane != 1)
	{
		ActorDestination.Y -= 200;
		Lane -= 1;
		
	}
}

void AMyCharacter::MoveRight()
{
	if (Lane != 3)
	{
		ActorDestination.Y += 200;
		Lane += 1;
		
	}
}

void AMyCharacter::MoveForward()
{
	// Moving actor forward every frame
	ActorLocation.X += ForwardSpeed;
	ActorDestination.X += ForwardSpeed;
	SetActorLocation(ActorLocation);
}

void AMyCharacter::DecSpeed()
{
	
	ForwardSpeed -= 25.f; // ForwardSpeed must be 25 or higher to destroy a block

}

void AMyCharacter::CountDown()
{
	Seconds += 1;
	Score -= 1;
}






