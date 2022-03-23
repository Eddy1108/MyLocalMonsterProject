// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterAvatar.h"

// Sets default values
AMonsterAvatar::AMonsterAvatar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	
	HeadMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HeadMesh"));
	HeadMesh->SetupAttachment(RootComponent);

	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMesh"));
	BodyMesh->SetupAttachment(RootComponent);

	FaceMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FaceMesh"));
	FaceMesh->SetupAttachment(RootComponent);
	
}

// Called when the game starts or when spawned
void AMonsterAvatar::BeginPlay()
{
	Super::BeginPlay();

	ChangePart();
	
}

void AMonsterAvatar::ChangePart()
{
	if (UsedFace < FaceMaterials.Num())
		FaceMesh->SetMaterial(0, FaceMaterials[UsedFace]);

	if (UsedHead < HeadMaterials.Num())
		HeadMesh->SetMaterial(0, HeadMaterials[UsedHead]);

	if (UsedBody < BodyMaterials.Num())
		BodyMesh->SetMaterial(0, BodyMaterials[UsedBody]);
	
	
	
}

void AMonsterAvatar::ChangeFace(float index)
{
	UsedFace = index;

	if (UsedFace < FaceMaterials.Num())
		FaceMesh->SetMaterial(0, FaceMaterials[UsedFace]);
}

void AMonsterAvatar::ChangeHead(float index)
{
	UsedHead = index;
	
	if (UsedHead < HeadMaterials.Num())
		HeadMesh->SetMaterial(0, HeadMaterials[UsedHead]);
}

void AMonsterAvatar::ChangeBody(float index)
{
	UsedBody = index;
	
	if (UsedBody < BodyMaterials.Num())
		BodyMesh->SetMaterial(0, BodyMaterials[UsedBody]);
}

// Called every frame
void AMonsterAvatar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UE_LOG(LogTemp, Warning, TEXT("Used Face: %d, FaceMaterials: %d"), UsedFace, FaceMaterials.Num());
	
	ChangePart();

}

