// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/CheckBox.h"
#include "Components/ComboBoxString.h"
#include "Components/Slider.h"
#include "Types/SlateEnums.h"
#include "Materials/MaterialParameterCollection.h"
#include "Materials/MaterialParameterCollectionInstance.h"
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
	
	int ColourDeficiencyIndex;
	
	// bind all of the input events to functions to update the variables
	void UpdateColourDeficiencyTint();
	
	UFUNCTION()
	void DeficiencyTypeUpdate(FString Value, ESelectInfo::Type NewType);
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Accessibility")
	UMaterialParameterCollection* GlobalTintCollection;
};
