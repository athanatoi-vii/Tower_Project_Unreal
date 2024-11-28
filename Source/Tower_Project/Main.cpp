// Fill out your copyright notice in the Description page of Project Settings.


#include "Main.h"
#include "GameFramework/Actor.h"
#include "Main_Player_Controller.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/World.h"
#include "Engine/Scene.h"

// Sets default values
AMain::AMain()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Point = CreateDefaultSubobject<USceneComponent>(TEXT("Point"));
	Point->SetupAttachment(RootComponent);

	Arm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Arm"));
	Arm->SetupAttachment(Point);
	Arm->TargetArmLength = 9000.f;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(Arm, TEXT("Camera"));
}

// Called when the game starts or when spawned
void AMain::BeginPlay()
{
	Super::BeginPlay();
	
	M_P_C = Cast<AMain_Player_Controller>(GetController());

	if (InputMapping && M_P_C)
	{
		if (UEnhancedInputLocalPlayerSubsystem* E_I_L_P_S = M_P_C->GetLocalPlayer()->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			E_I_L_P_S->AddMappingContext(InputMapping, 0);
		}
	}
}

// Called every frame
void AMain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMain::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
