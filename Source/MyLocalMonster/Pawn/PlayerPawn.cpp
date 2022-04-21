// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "MyLocalMonster/Actor/BaseUtfordrinspunkter.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	StaticMeshComponent=CreateDefaultSubobject<UStaticMeshComponent>("Static mesh");
	RootComponent = StaticMeshComponent;
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("Spring Arm");
	SpringArm->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("Camera Component");
	CameraComp->SetupAttachment(SpringArm);

	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>("Movement Component");
	// MovementComponent
	WalkSpeed = MovementComponent->MaxSpeed;
	SprintSpeed = WalkSpeed*10;
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerPawn::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerPawn::MoveRight);
	PlayerInputComponent->BindAxis("Scroll",this,&APlayerPawn::Scroll);

	PlayerInputComponent->BindAction("Sprint",IE_Pressed,this,&APlayerPawn::Sprint);
	PlayerInputComponent->BindAction("Sprint",IE_Released,this,&APlayerPawn::Walk);

}

void APlayerPawn::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator PlayerRotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, PlayerRotation.Yaw, 0);
		
		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void APlayerPawn::MoveRight(float Value)
{
	if ( (Controller != nullptr) && (Value != 0.0f)) 
	{
		// find out which way is right
		const FRotator PlayerRotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, PlayerRotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void APlayerPawn::Scroll(float Value)
{
	if(Value)
	{
		
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Value: GetMovementComponent()->GetName()")));

		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Value: %f"),Value));
		float x { SpringArm->TargetArmLength };
		if(Value > 0)
			x += (10*Value);
		else x -= (10* (Value*(-1)));
		
		SpringArm->TargetArmLength = x;
	}
}

void  APlayerPawn::Sprint()
{
	MovementComponent->MaxSpeed = SprintSpeed;
}
void  APlayerPawn::Walk()
{
	MovementComponent->MaxSpeed = WalkSpeed;
}