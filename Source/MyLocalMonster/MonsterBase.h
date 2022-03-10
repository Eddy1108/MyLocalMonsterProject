// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MonsterBase.generated.h"

UCLASS()
class MYLOCALMONSTER_API AMonsterBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMonsterBase();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh{nullptr};

	UPROPERTY(VisibleAnywhere)
	int xpLevel{0};

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
