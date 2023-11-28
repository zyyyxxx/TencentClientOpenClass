// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDemoGameState.h"

#include "Kismet/GameplayStatics.h"
#include "Serialization/ObjectAndNameAsStringProxyArchive.h"

AMyDemoGameState::AMyDemoGameState()
{
}

bool AMyDemoGameState::AddPlayerRankList(UMyDemoRankItemDataObject* RankItemData)
{
	if(RankItemData)
	{
		PlayerRankList.Add(RankItemData);
		PlayerRankList.Sort();
		return true;
	}

	return false;
}

UMyDemoRankItemDataObject* AMyDemoGameState::GetPlayerRankList(int Index)
{
	return PlayerRankList[Index];
}

int AMyDemoGameState::GetPlayerRankNum()
{
	return PlayerRankList.Num();
}

void AMyDemoGameState::WriteSaveGame()
{
	FSaveData& SaveData = CurrentSaveGame->SaveData;
	FMemoryWriter MemWriter(SaveData.ByteData);
	
	FObjectAndNameAsStringProxyArchive Ar(MemWriter, true);
	Ar.ArIsSaveGame = true;
	Ar.ArNoDelta = true;
	this->Serialize(Ar);

	UGameplayStatics::SaveGameToSlot(CurrentSaveGame, SlotName, 0);
}

void AMyDemoGameState::LoadSaveGame()
{
	if (UGameplayStatics::DoesSaveGameExist(SlotName, 0))
	{
		CurrentSaveGame = Cast<UMyDemoSaveGame>(UGameplayStatics::LoadGameFromSlot(SlotName, 0));
		if (CurrentSaveGame == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to load SaveGame Data."));
			return;
		}
 
		UE_LOG(LogTemp, Log, TEXT("Loaded SaveGame Data."));
		
		FMemoryReader MemReader(CurrentSaveGame->SaveData.ByteData);
 
		FObjectAndNameAsStringProxyArchive Ar(MemReader, true);
		Ar.ArIsSaveGame = true;
		Ar.ArNoDelta = true;
		this->Serialize(Ar);
		
		
	}else{
		CurrentSaveGame = Cast<UMyDemoSaveGame>(UGameplayStatics::CreateSaveGameObject(UMyDemoSaveGame::StaticClass()));
		UE_LOG(LogTemp, Log, TEXT("Created New SaveGame Data."));
	}
	
}

void AMyDemoGameState::ResetSaveGame()
{
	UGameplayStatics::DeleteGameInSlot(SlotName, 0);
}

void AMyDemoGameState::SetNameAndCredit(FString InName, int InCredit)
{
	Name = InName;
	Credit = InCredit;
}
