// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyDemoPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class MYDEMO_API AMyDemoPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	virtual bool InputTouch(uint32 Handle, ETouchType::Type Type, const FVector2D& TouchLocation, float Force, FDateTime DeviceTimestamp, uint32 TouchpadIndex) override;
protected:
	FVector2D PrevTouchLocation;
};
