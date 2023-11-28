// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MyDemoSaveGame.generated.h"

/**
 * 
 */

USTRUCT()
struct FSaveData
{
	GENERATED_BODY()
 
public:
	
	UPROPERTY()
	TArray<uint8> ByteData;
};


UCLASS()
class MYDEMO_API UMyDemoSaveGame : public USaveGame
{
	GENERATED_BODY()
public:
	UPROPERTY()
	FSaveData SaveData;
};
