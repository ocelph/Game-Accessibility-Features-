// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuGameMode.h"
#include "Blueprint/UserWidget.h"


void AMainMenuGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	if (MainMenuClass)
	{
		//  create a new User Widget of our MainMenuClass, and make it be managed by our Game Instance
		UUserWidget* MainMenu = Cast<UUserWidget>(CreateWidget(GetGameInstance(), MainMenuClass));

		// set the Input Mode to only be UI, and turn the mouse cursor on
		GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeUIOnly());
		GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(true);
		
		MainMenu->AddToViewport();
	}

}
