// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCameraActor.h"


// Sets default values
AMyCameraActor::AMyCameraActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;



}

// Called when the game starts or when spawned
void AMyCameraActor::BeginPlay()
{
	Super::BeginPlay();

	

}

// Called every frame
void AMyCameraActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector ActorLocation = GetActorLocation();
	ActorLocation.X += 20.f;
	SetActorLocation(ActorLocation);

}


