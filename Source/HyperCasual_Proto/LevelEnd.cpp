// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelEnd.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values
ALevelEnd::ALevelEnd()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Creating UBoxComponent
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox->SetBoxExtent(FVector(100.f, 300.f, 100.f)); // Setting size of UBoxComponent
	CollisionBox->SetCollisionProfileName("Trigger"); // "Trigger" because the box is for triggering a function when hit
	RootComponent = CollisionBox;

	// Runs appropriate functions when overlap begins and ends
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ALevelEnd::OnOverlapBegin);
	CollisionBox->OnComponentEndOverlap.AddDynamic(this, &ALevelEnd::OnOverlapEnd);

}

// Called when the game starts or when spawned
void ALevelEnd::BeginPlay()
{
	Super::BeginPlay();

	// Casting to MyCharacter, accessing using UGameplayStatics.
	MyCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

}

// Called every frame
void ALevelEnd::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALevelEnd::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, "Overlap Begin");

}

void ALevelEnd::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, "Overlap End");
}



