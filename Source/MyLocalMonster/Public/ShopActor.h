// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "MyLocalMonster/MonsterAvatar.h"

#include <vector>

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ShopActor.generated.h"

//Outfits:
// 0 = Default
// 1 = Devil
// 2 = FireMachine
// 3 = Bandage
// 4 = Mushroom

UCLASS()
class MYLOCALMONSTER_API AShopActor : public AActor
{
	GENERATED_BODY()

	struct FOutfitHead
	{
		int Index{0};
		int Price{50};
	};
	struct FOutfitFace
	{
		int Index{0};
		int Price{50};
	};
	struct FOutfitBody
	{
		int Index{0};
		int Price{50};
	};
	
public:	
	// Sets default values for this actor's properties
	AShopActor();
	
	std::vector<FOutfitHead> HeadArr;
	std::vector<FOutfitBody> BodyArr;
	std::vector<FOutfitFace> FaceArr;


	UFUNCTION(BlueprintCallable)
	int GetIndex(int Arr, int Index);
	UFUNCTION(BlueprintCallable)
	int GetPrice(int Arr, int Index);
	UFUNCTION(BlueprintCallable)
	void UpdatePrice(int Arr, int Index, int Price);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	AMonsterAvatar* MonsterAvatar{nullptr};

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
