// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterAvatar.h"

// Sets default values
AMonsterAvatar::AMonsterAvatar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	

	BodyFlipBook = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("BodyFlipBook"));
	BodyFlipBook->SetupAttachment(RootComponent);
	HeadFlipBook = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("HeadFlipBook"));
	HeadFlipBook->SetupAttachment(RootComponent);
	FaceFlipBook = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("FaceFlipBook"));
	FaceFlipBook->SetupAttachment(RootComponent);
	
}

// Called when the game starts or when spawned
void AMonsterAvatar::BeginPlay()
{
	Super::BeginPlay();

	ChangePart();
	
}

void AMonsterAvatar::ChangePart()
{

	ChangeBody(UsedBody);
	ChangeHead(UsedHead);
}

void AMonsterAvatar::ChangeFace(float index)
{

}

void AMonsterAvatar::ChangeHead(float index)
{
	UsedHead = index;

	HeadFlipBook->SetPlaybackPositionInFrames(UsedHead, true);
}

void AMonsterAvatar::ChangeBody(float index)
{
	UsedBody = index;

	BodyFlipBook->SetPlaybackPositionInFrames(UsedBody, true);
}

// Called every frame
void AMonsterAvatar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	
	ChangePart();

}

