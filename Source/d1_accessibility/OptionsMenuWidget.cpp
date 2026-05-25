// Fill out your copyright notice in the Description page of Project Settings.


#include "OptionsMenuWidget.h"

#include "Blueprint/WidgetBlueprintLibrary.h"

void UOptionsMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if (BackButton)
	{
		BackButton->OnClicked.AddDynamic(this,&UOptionsMenuWidget::CloseMenu);
	}
	
	// CHECKBOX 
	if (ColourCorrectionOnCheckBox)
	{
		ColourCorrectionOnCheckBox->OnCheckStateChanged.AddDynamic(this, &UOptionsMenuWidget::ToggleCorrectionOn);
	}
	
	// SLIDER
	if (ColourDeficiencySeveritySlider)
	{
		ColourDeficiencySeveritySlider->OnValueChanged.AddDynamic(this, &UOptionsMenuWidget::SeverityUpdate);
	}
	
	// DROPDOWN
	if (ColourDeficiencyType)
	{
		ColourDeficiencyType->ClearOptions();

		ColourDeficiencyType->AddOption(TEXT("Normal Vision"));
		ColourDeficiencyType->AddOption(TEXT("Deuteranope"));
		ColourDeficiencyType->AddOption(TEXT("Protanope"));
		ColourDeficiencyType->AddOption(TEXT("Tritanope"));

		ColourDeficiencyType->SetSelectedIndex(0);

		ColourDeficiencyType->OnSelectionChanged.AddDynamic(this, &UOptionsMenuWidget::DeficiencyTypeUpdate);
	}



}

void UOptionsMenuWidget::CloseMenu()
{
	RemoveFromParent();
}

void UOptionsMenuWidget::UpdateColourDeficiency()
{
	//  check what type of colour deficiency we want to use based on the dropdown,
	//  then call the WidgetBlueprintLibrary to call the function to set the Colour Deficiency type, severity, and correction toggle
	EColorVisionDeficiency VisionDeficiency;
	switch (ColourDeficiencyIndex)
	{
	case 0 :
		VisionDeficiency = EColorVisionDeficiency::NormalVision;
		break;
	case 1 :
		VisionDeficiency = EColorVisionDeficiency::Deuteranope;
		break;
	case 2 :
		VisionDeficiency = EColorVisionDeficiency::Protanope;
		break;
	case 3 :
		VisionDeficiency = EColorVisionDeficiency::Tritanope;
		break;
	default:
		VisionDeficiency = EColorVisionDeficiency::NormalVision;
		break;
	}
	
	if (bCorrectionIsOn)
	{
		UWidgetBlueprintLibrary::SetColorVisionDeficiencyType(VisionDeficiency, ColourDeficiencySeverity, bCorrectionIsOn, true);
	}
	
}

void UOptionsMenuWidget::SeverityUpdate(float Value)
{
	ColourDeficiencySeverity = Value;
	UpdateColourDeficiency();
}

void UOptionsMenuWidget::ToggleCorrectionOn(bool Value)
{
	bCorrectionIsOn = Value;
	UpdateColourDeficiency();
}

void UOptionsMenuWidget::DeficiencyTypeUpdate(FString Value, ESelectInfo::Type NewType)
{
	ColourDeficiencyIndex = ColourDeficiencyType->GetSelectedIndex();
	UpdateColourDeficiency();
}
