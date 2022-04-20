// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseUtfordrinspunkter.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
ABaseUtfordrinspunkter::ABaseUtfordrinspunkter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	StaticMeshComponent=CreateDefaultSubobject<UStaticMeshComponent>("Static mesh");
	RootComponent = StaticMeshComponent;
}

// Called when the game starts or when spawned
void ABaseUtfordrinspunkter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseUtfordrinspunkter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

