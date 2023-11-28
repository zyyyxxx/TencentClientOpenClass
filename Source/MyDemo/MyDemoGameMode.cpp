// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyDemoGameMode.h"
#include "MyDemoCharacter.h"
#include "UObject/ConstructorHelpers.h"

class AMyDemoGameState;

AMyDemoGameMode::AMyDemoGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AMyDemoGameMode::InitGameState()
{
	Super::InitGameState();
	if (AMyDemoGameState* MyDemoGameState = Cast<AMyDemoGameState>(GameState))
	{
		MyDemoGameState->LoadSaveGame();
	}
}
