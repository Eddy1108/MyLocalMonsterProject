// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "Paper2DClasses.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MonsterAvatar.generated.h"



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


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UPaperFlipbookComponent* TestFlipBook{nullptr};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int UsedFace{0};
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int UsedHead{0};
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int UsedBody{0};

	
	UFUNCTION(BlueprintCallable)
	void ChangeFace(float index);
	UFUNCTION(BlueprintCallable)
	void ChangeHead(float index);
	UFUNCTION(BlueprintCallable)
	void ChangeBody(float index);
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void ChangePart();
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
