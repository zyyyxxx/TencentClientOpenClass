// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDemoRankItemDataObject.h"



void UMyDemoRankItemDataObject::SetNameAndCredit(FString InName, int InRankCredit)
{
	PlayerName = InName;
	RankCredit = InRankCredit;
}

bool UMyDemoRankItemDataObject::operator<(const UMyDemoRankItemDataObject& OtherObject) const
{
	return RankCredit < OtherObject.RankCredit;
}
