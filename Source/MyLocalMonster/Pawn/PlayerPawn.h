// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UStaticMeshComponent;
class UFloatingPawnMovement;

UCLASS()
class MYLOCALMONSTER_API APlayerPawn : public APawn
{
private:
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* StaticMeshComponent { nullptr };
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringArm { nullptr };
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* CameraComp { nullptr };
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MovementComponent", meta = (AllowPrivateAccess = "true"))
	UFloatingPawnMovement* MovementComponent { nullptr };
public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void Scroll(float Value);
	void Sprint();
	void Walk();
	
	void ExitGame();
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Variables", meta = (AllowPrivateAccess = "true"))
	float SprintSpeed{400};
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Variables", meta = (AllowPrivateAccess = "true"))
	float WalkSpeed{0};
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
