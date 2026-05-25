// Fill out your copyright notice in the Description page of Project Settings.


#include "InputSlotWidget.h"
#include "RebindWidget.h"

void UInputSlotWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	if (Button)
	{
		Button->OnClicked.AddDynamic(this,&UInputSlotWidget::OnButtonClicked);
	}
}

void UInputSlotWidget::OnButtonClicked()
{
	if (RebindWidget)
	{
		RebindWidget->OnKeyButton(this);
	}
}
