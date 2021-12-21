// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

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

	ActorDestination = GetActorLocation();
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ActorLocation = GetActorLocation();



	// Moving actor forward every frame
	ActorLocation.X += 10.f;
	ActorDestination.X += 10.f;
	SetActorLocation(ActorLocation);

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
		UE_LOG(LogTemp, Warning, TEXT("Lane %f"), Lane);
	}
}

void AMyCharacter::MoveRight()
{
	if (Lane != 3)
	{
		ActorDestination.Y += 200;
		Lane += 1;
		UE_LOG(LogTemp, Warning, TEXT("Lane %f"), Lane);
	}
}





