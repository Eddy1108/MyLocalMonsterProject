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

	TestFlipBook = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("TestFlipBook"));
	TestFlipBook->SetupAttachment(RootComponent);
	
}

// Called when the game starts or when spawned
void AMonsterAvatar::BeginPlay()
{
	Super::BeginPlay();

	ChangePart();

	HeadFlipBook->SetPlayRate(0);
	FaceFlipBook->SetPlayRate(0);
	BodyFlipBook->SetPlayRate(0);
	
}

void AMonsterAvatar::ChangePart()
{

	ChangeBody(UsedBody);
	ChangeHead(UsedHead);
	ChangeFace(UsedFace);
}

void AMonsterAvatar::ChangeFace(float index)
{
    UsedFace = index;
	
	FaceFlipBook->SetPlayRate(1);
    FaceFlipBook->SetPlaybackPositionInFrames(UsedFace, true);
	FaceFlipBook->SetPlayRate(0);

	UE_LOG(LogTemp, Warning, TEXT("Changed Face to: %d"), index);

}

void AMonsterAvatar::ChangeHead(float index)
{
	UsedHead = index;

	HeadFlipBook->SetPlayRate(1);
	HeadFlipBook->SetPlaybackPositionInFrames(UsedHead, true);
	HeadFlipBook->SetPlayRate(0);

	UE_LOG(LogTemp, Warning, TEXT("Changed Head to: %d"), index);
}

void AMonsterAvatar::ChangeBody(float index)
{
	UsedBody = index;

	BodyFlipBook->SetPlayRate(1);
	BodyFlipBook->SetPlaybackPositionInFrames(UsedBody, true);
	BodyFlipBook->SetPlayRate(0);

	UE_LOG(LogTemp, Warning, TEXT("Changed Body to: %d"), index);
}

// Called every frame
void AMonsterAvatar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	
	//ChangePart();

}

