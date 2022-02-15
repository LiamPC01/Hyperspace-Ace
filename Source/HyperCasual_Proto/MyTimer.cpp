// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTimer.h"

#define PrintString(String) GEngine->AddOnScreenDebugMessage(-1,1.0f, FColor::White,String)

// Sets default values
AMyTimer::AMyTimer()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyTimer::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(TimerHandle, this, &AMyTimer::TimerFunction, 3.0f, true, 0.5f);
}

// Called every frame
void AMyTimer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyTimer::TimerFunction()
{
	// Track number of times call function
	CallTracker--;
	// if calltracker is zero then print A and clear the timer to stop it looping other print B
	CallTracker == 0 ? PrintString("Finished Looping"), GetWorldTimerManager().ClearTimer(TimerHandle) : PrintString("Timer Called");
	// print the number of loops the tracker has remaining
	PrintString(FString::Printf(TEXT("Calls Remaining: %d"), CallTracker));
}

