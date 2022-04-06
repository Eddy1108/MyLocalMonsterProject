// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyLocalMonster/MonsterAvatar.h"
#include "Test_HUD.generated.h"

/**
 * 
 */
UCLASS()
class MYLOCALMONSTER_API ATest_HUD : public AHUD
{
	GENERATED_BODY()

	public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AMonsterAvatar* MonsterAvatar{nullptr};

	UFUNCTION(BlueprintCallable)
	void PrintTests();
	
};
