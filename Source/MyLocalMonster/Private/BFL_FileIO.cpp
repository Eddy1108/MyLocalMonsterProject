// Fill out your copyright notice in the Description page of Project Settings.


#include "BFL_FileIO.h"
#include <Runtime\Core\Public\Misc\Paths.h>
#include <Runtime\Core\Public\HAL\PlatformFilemanager.h>

FString UBFL_FileIO::LoadFileToString(FString filename)
{
	FString directory = FPaths::ProjectContentDir();
	FString result;
	IPlatformFile& file = FPlatformFileManager::Get().GetPlatformFile();

	if (file.CreateDirectory(*directory))
	{
		FString myFile = directory + "/" + filename;
		FFileHelper::LoadFileToString(result, *myFile);
	}

	return result;
}

TArray<FString> UBFL_FileIO::LoadFileToStringArray(FString filename)
{
	FString directory = FPaths::ProjectContentDir();
	TArray<FString> result;
	IPlatformFile& file = FPlatformFileManager::Get().GetPlatformFile();

	if (file.CreateDirectory(*directory))
	{
		FString myFile = directory + "/" + filename;
		FFileHelper::LoadFileToStringArray(result, *myFile);
	}

	return result;
}
