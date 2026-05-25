// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/CheckBox.h"
#include "Components/ComboBoxString.h"
#include "Components/Slider.h"
#include "Types/SlateEnums.h"
#include "OptionsMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class D1_ACCESSIBILITY_API UOptionsMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
	UPROPERTY(meta=(BindWidget))
	UButton* BackButton;
	
	// Widget’s NativeConstruct will be called when we add it to the viewport
	virtual void NativeConstruct() override;
	
	UFUNCTION()
	void CloseMenu();
	
	// UComboBoxString is a dropdown
	UPROPERTY(meta=(BindWidget))
	UComboBoxString* ColourDeficiencyType;
	
	// the slider will manage how severe the colour deficiency is,
	UPROPERTY(meta=(BindWidget))
	USlider* ColourDeficiencySeveritySlider;
	
	// the check box will be used for adding a correction or not
	UPROPERTY(meta=(BindWidget))
	UCheckBox* ColourCorrectionOnCheckBox;
	
	bool bCorrectionIsOn = false;
	int ColourDeficiencyIndex = 0;
	float ColourDeficiencySeverity = 0;
	
	// bind all of the input events to functions to update the variables
	void UpdateColourDeficiency();
	
	UFUNCTION()
	void SeverityUpdate(float Value);
	
	UFUNCTION()
	void ToggleCorrectionOn(bool Value);
	
	UFUNCTION()
	void DeficiencyTypeUpdate(FString Value, ESelectInfo::Type NewType);
};
