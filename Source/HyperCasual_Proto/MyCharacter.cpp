// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Lane = 2; 

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

//Moving the actor forward every frame
	FVector ActorLocation = GetActorLocation();
	ActorLocation.X += 10.f;
	SetActorLocation(ActorLocation);

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
		FVector ActorLocation = GetActorLocation();
		ActorLocation.Y -= 200.f;
		SetActorLocation(ActorLocation);
		Lane -= 1;
		UE_LOG(LogTemp, Warning, TEXT("Lane %f"), Lane);
	}
}

void AMyCharacter::MoveRight()
{
	if (Lane != 3)
	{
		FVector ActorLocation = GetActorLocation();
		ActorLocation.Y += 200.f;
		SetActorLocation(ActorLocation);
		Lane += 1;
		UE_LOG(LogTemp, Warning, TEXT("Lane %f"), Lane);
	}
}



