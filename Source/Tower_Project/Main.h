// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InputActionValue.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Main.generated.h"

UCLASS()
class TOWER_PROJECT_API AMain : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMain();

	//Camera
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Arm")
	class USpringArmComponent* Arm;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Camera")
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Point")
	class USceneComponent* Point;

	USceneComponent* Root;

	// Conteroler
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Main Player Controller")
	class AMain_Player_Controller* M_P_C;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ATower")
	class AActor* ATower;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Inpute
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	class UInputMappingContext* InputMapping;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
