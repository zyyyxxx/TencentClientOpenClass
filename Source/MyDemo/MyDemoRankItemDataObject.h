// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyDemoRankItemDataObject.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class MYDEMO_API UMyDemoRankItemDataObject : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void SetNameAndCredit(FString InName , int InRankCredit);
	
	bool operator<(const UMyDemoRankItemDataObject& OtherObject) const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RankItem")
	FString PlayerName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RankItem")
	int RankCredit = 0;
};
