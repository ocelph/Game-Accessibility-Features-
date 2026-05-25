// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
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
};
