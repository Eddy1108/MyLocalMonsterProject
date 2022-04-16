// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include <vector>

#include "Paper2DClasses.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MonsterAvatar.generated.h"

//Outfits:
// 0 = Default
// 1 = Devil
// 2 = FireMachine
// 3 = Bandage
// 4 = Mushroom


UCLASS()
class MYLOCALMONSTER_API AMonsterAvatar : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMonsterAvatar();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UPaperFlipbookComponent* BodyFlipBook{nullptr};
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UPaperFlipbookComponent* HeadFlipBook{nullptr};
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UPaperFlipbookComponent* FaceFlipBook{nullptr};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int UsedFace{0};
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int UsedHead{0};
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int UsedBody{0};

	std::vector<int> unlockedHead;
	std::vector<int> unlockedFace;
	std::vector<int> unlockedBody;

	
	UFUNCTION(BlueprintCallable)
	void ChangeFace(float index);
	UFUNCTION(BlueprintCallable)
	void ChangeHead(float index);
	UFUNCTION(BlueprintCallable)
	void ChangeBody(float index);

	UFUNCTION(BlueprintCallable)
	int GetUnlockedHeadSize();
	UFUNCTION(BlueprintCallable)
	int GetUnlockedFaceSize();
	UFUNCTION(BlueprintCallable)
	int GetUnlockedBodySize();

	UFUNCTION(BlueprintCallable)
	int GetUnlockedFace();
	UFUNCTION(BlueprintCallable)
	int GetUnlockedHead();
	UFUNCTION(BlueprintCallable)
	int GetUnlockedBody();

	UFUNCTION(BlueprintCallable)
	bool AddUnlockFace(int item);
	UFUNCTION(BlueprintCallable)
	bool AddUnlockHead(int item);
	UFUNCTION(BlueprintCallable)
	bool AddUnlockBody(int item);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void ChangePart();

	bool IsUnlockedHead(int index);
	bool IsUnlockedFace(int index);
	bool IsUnlockedBody(int index);
	
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
