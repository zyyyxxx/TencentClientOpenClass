// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDemoPlayerController.h"

bool AMyDemoPlayerController::InputTouch(uint32 Handle, ETouchType::Type Type, const FVector2D& TouchLocation,
	float Force, FDateTime DeviceTimestamp, uint32 TouchpadIndex)
{
	if (Type == ETouchType::Began) {
		PrevTouchLocation = TouchLocation;
	}else if (Type == ETouchType::Moved)
	{
		const int DeltaX = int(TouchLocation.X - PrevTouchLocation.X);
		const int DeltaY = int(TouchLocation.Y - PrevTouchLocation.Y);

		this->AddYawInput(DeltaX * 0.5f);
		this->AddPitchInput(DeltaY * 0.5f);
		
		

		PrevTouchLocation = TouchLocation;
	}
	return Super::InputTouch(Handle, Type, TouchLocation, Force, DeviceTimestamp, TouchpadIndex);
}
