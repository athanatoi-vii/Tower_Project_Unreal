// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Main_Player_Controller.generated.h"

/**
 * 
 */
UCLASS()
class TOWER_PROJECT_API AMain_Player_Controller : public APlayerController
{
	GENERATED_BODY()
	
public:

	AMain_Player_Controller();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "B Show Mous")
	bool B_Show_Mous;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "B Puse Mous")
	bool B_Puse_Menu;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tower")
	class AActor* Tower;
};
