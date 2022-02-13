// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyCameraActor.generated.h"

class AMyCharacter;

UCLASS()
class HYPERCASUAL_PROTO_API AMyCameraActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyCameraActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void DecSpeedCam();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
		float CamForwardSpeed = 20.f;




};
