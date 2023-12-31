// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyDemoGameState.h"
#include "MyDemoGameMode.generated.h"

UCLASS(minimalapi)
class AMyDemoGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMyDemoGameMode();

	virtual void InitGameState() override;
};



