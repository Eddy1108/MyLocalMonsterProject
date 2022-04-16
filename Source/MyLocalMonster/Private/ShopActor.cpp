// Fill out your copyright notice in the Description page of Project Settings.


#include "ShopActor.h"

#include "Kismet/GameplayStatics.h"

//Outfits:
// 0 = Default
// 1 = Devil
// 2 = FireMachine
// 3 = Bandage
// 4 = Mushroom

// Sets default values
AShopActor::AShopActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
//Arr: 0 = Head, 1 = Face, 2 = Body
int AShopActor::GetIndex(int Arr, int Index)
{
	switch (Arr)
	{
		case 0:
			return HeadArr[Index].Index;
			
		case 1:
			return FaceArr[Index].Index;
			
		case 2:
			return BodyArr[Index].Index;
			
		default:
			return 0;
		
	}
}

//Arr: 0 = Head, 1 = Face, 2 = Body
int AShopActor::GetPrice(int Arr, int Index)
{
	switch (Arr)
	{
	case 0:
		return HeadArr[Index].Price;
			
	case 1:
		return FaceArr[Index].Price;
			
	case 2:
		return BodyArr[Index].Price;
			
	default:
		return 0;
		
	}
}

void AShopActor::UpdatePrice(int Arr, int Index, int Price)
{
	switch (Arr)
	{
	case 0:
		HeadArr[Index].Price = Price;

		break;
	case 1:
		FaceArr[Index].Price = Price;

		break;
	case 2:
		BodyArr[Index].Price = Price;
			
	default:
		break;
		
	}
}

// Called when the game starts or when spawned
void AShopActor::BeginPlay()
{
	Super::BeginPlay();

	MonsterAvatar = Cast<AMonsterAvatar>(UGameplayStatics::GetActorOfClass(GetWorld(), AMonsterAvatar::StaticClass()));


	HeadArr.push_back(FOutfitHead{0, 0});
	HeadArr.push_back(FOutfitHead{1, 0});
	HeadArr.push_back(FOutfitHead{2, 10});
	HeadArr.push_back(FOutfitHead{3, 20});
	HeadArr.push_back(FOutfitHead{4, 30});

	FaceArr.push_back(FOutfitFace{0, 0});
	FaceArr.push_back(FOutfitFace{1, 0});
	FaceArr.push_back(FOutfitFace{2, 10});
	FaceArr.push_back(FOutfitFace{3, 20});
	FaceArr.push_back(FOutfitFace{4, 30});

	BodyArr.push_back(FOutfitBody{0,0});
	BodyArr.push_back(FOutfitBody{1,0});
	BodyArr.push_back(FOutfitBody{2,10});
	BodyArr.push_back(FOutfitBody{3,20});
	BodyArr.push_back(FOutfitBody{4,30});
	
}

// Called every frame
void AShopActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

