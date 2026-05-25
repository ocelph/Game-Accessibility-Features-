// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputSlotWidget.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/VerticalBox.h"
#include "RebindWidget.generated.h"

/**
 * 
 */
UCLASS()
class D1_ACCESSIBILITY_API URebindWidget : public UUserWidget
{
	GENERATED_BODY()
	
	// Widget’s NativeConstruct will be called when we add it to the viewport
	virtual void NativeConstruct() override;
	
	
	// BACK BUTTON
	UPROPERTY(meta=(BindWidget))
	UButton* BackButton;
	
	UFUNCTION()
	void CloseMenu();
	
	
	// Vertical Box that will contain the input action rows
	UPROPERTY(meta = (BindWidget))
	UVerticalBox* VBox;
	
	// CREATE ALL INPUT ROWS
	void AddInputRows();
	
public:
	// INPUT SLOT CLASS
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category = "UI")
	TSubclassOf<UInputSlotWidget> InputSlotWidgetClass;

	

	
};
