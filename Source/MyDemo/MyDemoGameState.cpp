// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDemoGameState.h"

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
