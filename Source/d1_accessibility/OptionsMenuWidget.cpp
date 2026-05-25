// Fill out your copyright notice in the Description page of Project Settings.


#include "OptionsMenuWidget.h"

void UOptionsMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if (BackButton)
	{
		BackButton->OnClicked.AddDynamic(this,&UOptionsMenuWidget::CloseMenu);
	}

}

void UOptionsMenuWidget::CloseMenu()
{
	RemoveFromParent();
}
