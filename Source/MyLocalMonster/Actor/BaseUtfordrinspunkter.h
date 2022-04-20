// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseUtfordrinspunkter.generated.h"

class UStaticMeshComponent;
UCLASS()
class MYLOCALMONSTER_API ABaseUtfordrinspunkter : public AActor
{
	GENERATED_BODY()
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* StaticMeshComponent { nullptr };
public:	
	// Sets default values for this actor's properties
	ABaseUtfordrinspunkter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
