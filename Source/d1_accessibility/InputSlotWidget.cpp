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
		// equivalent to validated get
		UE_LOG(LogTemp, Warning, TEXT("Button clicked for mapping: %s"), *KeyMappingName.ToString());

		// later:
		// RebindWidget->StartRebinding(KeyMappingName);
	}
}
