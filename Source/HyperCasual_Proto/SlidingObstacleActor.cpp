// Fill out your copyright notice in the Description page of Project Settings.


#include "SlidingObstacleActor.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values
ASlidingObstacleActor::ASlidingObstacleActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bGoingLeft = true;
	bGoingRight = false;

	// Creating UBoxComponent
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	CollisionBox->SetBoxExtent(FVector(32.f, 32.f, 32.f)); // Setting size of UBoxComponent
	CollisionBox->SetCollisionProfileName("Trigger"); // "Trigger" because the box is for triggering a function when hit
	RootComponent = CollisionBox;

	// Runs appropriate functions when overlap begins and ends
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ASlidingObstacleActor::OnOverlapBegin);
	CollisionBox->OnComponentEndOverlap.AddDynamic(this, &ASlidingObstacleActor::OnOverlapEnd);
}

// Called when the game starts or when spawned
void ASlidingObstacleActor::BeginPlay()
{
	Super::BeginPlay();

	// Casting to MyCharacter, accessing using UGameplayStatics.
	MyCharacter = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));



}

// Called every frame
void ASlidingObstacleActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Move();

}

void ASlidingObstacleActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Green, "Overlap Begin");
	if (MyCharacter && MyCharacter == OtherActor)
	{
		MyCharacter->DecSpeed(); // Casting to MyCharacter to decrease ForwardSpeed
		Destroy(false, true); // Destroy obstacle

	}
}

void ASlidingObstacleActor::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, "Overlap End");
}

void ASlidingObstacleActor::Move()
{
	if (bGoingLeft)
	{
		FVector ActorLocation = GetActorLocation();
		ActorLocation.Y -= 5.f;
		SetActorLocation(ActorLocation);
		ActorLocationY = ActorLocation.Y;
		if (ActorLocationY <= -200)
		{
			bGoingLeft = false;
			bGoingRight = true;
		}
	}
	else if (bGoingRight)
	{
		FVector ActorLocation = GetActorLocation();
		ActorLocation.Y += 5.f;
		SetActorLocation(ActorLocation);
		ActorLocationY = ActorLocation.Y;
		if (ActorLocationY >= 200)
		{
			bGoingLeft = true;
			bGoingRight = false;
		}
	}
}
