// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* HeadMesh{nullptr};
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BodyMesh{nullptr};
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* FaceMesh{nullptr};

	UPROPERTY(EditAnywhere)
	TArray<UMaterial*> BodyMaterials;
	UPROPERTY(EditAnywhere)
	TArray<UMaterial*> HeadMaterials;
	UPROPERTY(EditAnywhere)
	TArray<UMaterial*> FaceMaterials;

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
