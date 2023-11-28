// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyDemoRankItemDataObject.h"
#include "MyDemoSaveGame.h"
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
	/**
	 * 
	 */
	AMyDemoGameState();

	UFUNCTION(BlueprintCallable)
	bool AddPlayerRankList(UMyDemoRankItemDataObject* RankItemData);

	UFUNCTION(BlueprintCallable)
	UMyDemoRankItemDataObject* GetPlayerRankList(int Index);

	UFUNCTION(BlueprintCallable)
	int GetPlayerRankNum();

	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	void WriteSaveGame();
	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	void LoadSaveGame();
	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	void ResetSaveGame();

	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	void SetNameAndCredit(FString InName, int InCredit);
	
protected:
	UPROPERTY(EditDefaultsOnly , BlueprintReadOnly , Category="Rank" , SaveGame)
	FString Name;
	UPROPERTY(EditDefaultsOnly , BlueprintReadOnly , Category="Rank" , SaveGame)
	int Credit;
	
	UPROPERTY(EditDefaultsOnly , BlueprintReadOnly , Category="Rank")
	TArray<UMyDemoRankItemDataObject*> PlayerRankList;

	FString SlotName = "SaveGame01";//保存位置
 
	UPROPERTY()
	UMyDemoSaveGame* CurrentSaveGame;
	
};
