// Fill out your copyright notice in the Description page of Project Settings.


#include "A11yMenuWidget.h"

void UA11yMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	if (ResumeButton)
	{
		ResumeButton->OnClicked.AddDynamic(this,&UA11yMenuWidget::CloseMenu);
	}
	
	if (RebindButton)
	{
		RebindButton->OnClicked.AddDynamic(this, &UA11yMenuWidget::OpenRebindMenu);
	}
}

void UA11yMenuWidget::CloseMenu()
{
	RemoveFromParent();
	GetWorld()->GetFirstPlayerController()->SetInputMode(FInputModeGameOnly());
	GetWorld()->GetFirstPlayerController()->SetShowMouseCursor(false);
}

void UA11yMenuWidget::OpenRebindMenu()
{
	if (RebindWidgetClass)
	{
		// URebindWidget* RebindWidget = Cast<URebindWidget>(CreateWidget(GetGameInstance(), RebindWidgetClass));  -- older version
		URebindWidget* RebindWidget = CreateWidget<URebindWidget>(GetWorld(),RebindWidgetClass);
		RebindWidget->AddToViewport();
	}
}
