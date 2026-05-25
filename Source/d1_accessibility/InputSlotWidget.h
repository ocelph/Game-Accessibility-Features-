// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "InputSlotWidget.generated.h"

class URebindWidget;
/**
 * 
 */
UCLASS()
class D1_ACCESSIBILITY_API UInputSlotWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UButton* Button;

public:
	// ExposeOnSpawn lets a variable appear as an input pin when you create the object/widget
	// allows passing of data when the widget is created
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"))
	FName KeyMappingName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"))
    	URebindWidget* RebindWidget;

	
	// meta = (BindWidget) automatically connects a C++ variable to a widget in your Blueprint UI hierarchy. 
	// When the widget is created, Unreal automatically finds widgets with those exact names in the Blueprint and assigns them.
	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextBlock;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ButtonTextBlock;
	
	
	UFUNCTION()
	void OnButtonClicked();
};
