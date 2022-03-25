// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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
	

	UPROPERTY(EditAnywhere)
	int UsedFace{0};
	UPROPERTY(EditAnywhere)
	int UsedHead{0};
	UPROPERTY(EditAnywhere)
	int UsedBody{0};

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

	void ChangePart();
	void ChangeFace(float index);
	void ChangeHead(float index);
	void ChangeBody(float index);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
