// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include <Runtime\Core\Public\Misc\Filehelper.h>
#include "BFL_FileIO.generated.h"

/**
 * 
 */
UCLASS()
class MYLOCALMONSTER_API UBFL_FileIO : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		UFUNCTION(BlueprintCallable, Category = "FileIO")
		static FString LoadFileToString(FString filename);

		UFUNCTION(BlueprintCallable, Category = "FileIO")
		static TArray<FString> LoadFileToStringArray(FString filename);
};
