// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RebindWidget.h"
#include "Components/Button.h"
#include "A11yMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class D1_ACCESSIBILITY_API UA11yMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
	// Widget’s NativeConstruct will be called when we add it to the viewport
	virtual void NativeConstruct() override;
	
	
	// RESUME
	UPROPERTY(meta=(BindWidget))
	UButton* ResumeButton;
	
	UFUNCTION()
	void CloseMenu();
	
	
	// REBIND
	UPROPERTY(meta = (BindWidget))
	UButton* RebindButton;
	
	UPROPERTY(EditAnywhere, Category = UI)
	TSubclassOf<URebindWidget> RebindWidgetClass;
	
	UFUNCTION()
	void OpenRebindMenu();
	
};
