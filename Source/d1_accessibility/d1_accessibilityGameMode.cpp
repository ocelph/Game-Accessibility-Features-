// Copyright Epic Games, Inc. All Rights Reserved.

#include "d1_accessibilityGameMode.h"

void Ad1_accessibilityGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	// This will fix our controls so that when we enter our game level, we can play as normal
	// This is to change the input mode we had changed in our MainMenu
	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeGameOnly());
	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(false);
}

Ad1_accessibilityGameMode::Ad1_accessibilityGameMode()
{
	// stub
}
