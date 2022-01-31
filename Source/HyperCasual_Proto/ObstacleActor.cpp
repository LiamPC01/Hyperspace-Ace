// Fill out your copyright notice in the Description page of Project Settings.


#include "ObstacleActor.h"
#include "Components/BoxCOmponent.h"
#include "Engine/Engine.h"

// Sets default values
AObstacleActor::AObstacleActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Creating UBoxComponent
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox->SetBoxExtent(FVector(32.f, 32.f, 32.f)); // Setting size of UBoxComponent
	CollisionBox->SetCollisionProfileName("Trigger"); // "Trigger" because the box is for triggering a function when hit
	RootComponent = CollisionBox;

	// Runs appropriate functions when overlap begins and ends
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AObstacleActor::OnOverlapBegin);
	CollisionBox->OnComponentEndOverlap.AddDynamic(this, &AObstacleActor::OnOverlapEnd);
}

// Called when the game starts or when spawned
void AObstacleActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AObstacleActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AObstacleActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, "Overlap Begin");
}

void AObstacleActor::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, "Overlap End");
}

