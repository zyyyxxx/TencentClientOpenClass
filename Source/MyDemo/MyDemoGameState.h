// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyDemoRankItemDataObject.h"
#include "GameFramework/GameStateBase.h"
#include "MyDemoGameState.generated.h"

/**
 * 
 */
UCLASS()
class MYDEMO_API AMyDemoGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	AMyDemoGameState();

	UFUNCTION(BlueprintCallable)
	bool AddPlayerRankList(UMyDemoRankItemDataObject* RankItemData);

	UFUNCTION(BlueprintCallable)
	UMyDemoRankItemDataObject* GetPlayerRankList(int Index);

	UFUNCTION(BlueprintCallable)
	int GetPlayerRankNum();
protected:
	
	UPROPERTY(EditDefaultsOnly , BlueprintReadOnly , Category="Rank")
	TArray<UMyDemoRankItemDataObject*> PlayerRankList;
	
};
