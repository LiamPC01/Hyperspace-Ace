// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class HYPERCASUAL_PROTO_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	float Lane = 2;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void MoveLeft();

	UFUNCTION()
		void MoveRight();

	UFUNCTION()
		void MoveForward();

	UFUNCTION()
		void DecSpeed();

	UPROPERTY(EditAnywhere, Category = "Movement")
		float InterpSpeed = 10;

	UPROPERTY(EditAnywhere, Category = "Movement")
		FVector ActorLocation;

	UPROPERTY(EditAnywhere, Category = "Movement")
		FVector ActorDestination;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
		float ForwardSpeed = 20.f;

	UPROPERTY()
		float PeakSpeed = 0;









};
