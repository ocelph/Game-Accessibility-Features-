// Fill out your copyright notice in the Description page of Project Settings.


#include "OptionsMenuWidget.h"
#include "AccessibilityGameInstance.h"
#include "Blueprint/WidgetBlueprintLibrary.h"

void UOptionsMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if (BackButton)
	{
		BackButton->OnClicked.AddDynamic(this,&UOptionsMenuWidget::CloseMenu);
	}
	
	if (UAccessibilityGameInstance* GameInstance = Cast<UAccessibilityGameInstance>(GetGameInstance()))
	{
		ColourDeficiencyIndex = GameInstance->ColourDeficiencyIndex ;
	}
	
	// DROPDOWN
	if (ColourDeficiencyType)
	{
		ColourDeficiencyType->ClearOptions();

		ColourDeficiencyType->AddOption(TEXT("Normal Vision"));
		ColourDeficiencyType->AddOption(TEXT("Deuteranope"));
		ColourDeficiencyType->AddOption(TEXT("Protanope"));
		ColourDeficiencyType->AddOption(TEXT("Tritanope"));

		ColourDeficiencyType->SetSelectedIndex(ColourDeficiencyIndex);

		ColourDeficiencyType->OnSelectionChanged.AddDynamic(this, &UOptionsMenuWidget::DeficiencyTypeUpdate);
	}
	
}

void UOptionsMenuWidget::CloseMenu()
{
	RemoveFromParent();
}

void UOptionsMenuWidget::UpdateColourDeficiencyTint()
{
	//  check what type of colour deficiency we want to use based on the dropdown,
	
	if (!GlobalTintCollection)
	{
		return;
	}
	
	UMaterialParameterCollectionInstance* MPC = GetWorld()->GetParameterCollectionInstance(GlobalTintCollection);
	
	switch (ColourDeficiencyIndex)
	{
	case 0 : // Normal
		MPC->SetVectorParameterValue(
			TEXT("PlatformTint"),
			FLinearColor(FColor::FromHex(TEXT("#5262DA"))));

		MPC->SetVectorParameterValue(
			TEXT("WallTint"),
			FLinearColor(FColor::FromHex(TEXT("#FFFFFF"))));
		
		MPC->SetVectorParameterValue(
			TEXT("CharacterTint"),
			FLinearColor(FColor::FromHex(TEXT("#FFFFFF"))));
		break;

	
	case 1 : // Deuteranope;
		MPC->SetVectorParameterValue(
			TEXT("PlatformTint"),
			FLinearColor(FColor::FromHex(TEXT("#5316BFFF"))));

		MPC->SetVectorParameterValue(
			TEXT("WallTint"),
			FLinearColor(FColor::FromHex(TEXT("#F3C658FF"))));
		
		MPC->SetVectorParameterValue(
			TEXT("CharacterTint"),
			FLinearColor(FColor::FromHex(TEXT("#000000"))));
		break;
		
		
	case 2 : // Protanope;
		MPC->SetVectorParameterValue(
			TEXT("PlatformTint"),
			FLinearColor(FColor::FromHex(TEXT("#1AFF1AFF"))));

		MPC->SetVectorParameterValue(
			TEXT("WallTint"),
			FLinearColor(FColor::FromHex(TEXT("#002292FF"))));
		
		MPC->SetVectorParameterValue(
			TEXT("CharacterTint"),
			FLinearColor(FColor::FromHex(TEXT("#FFFFFF"))));
		break;
		
	case 3 : // Tritanope;
		MPC->SetVectorParameterValue(
			TEXT("PlatformTint"),
			FLinearColor(FColor::FromHex(TEXT("#174C10FF"))));

		MPC->SetVectorParameterValue(
			TEXT("WallTint"),
			FLinearColor(FColor::FromHex(TEXT("#FFFFFF"))));
		
		MPC->SetVectorParameterValue(
			TEXT("CharacterTint"),
			FLinearColor(FColor::FromHex(TEXT("#F9B0B7FF"))));
		break;
		
		
	default:
		MPC->SetVectorParameterValue(
			TEXT("PlatformTint"),
			FLinearColor(FColor::FromHex(TEXT("#5262DA"))));

		MPC->SetVectorParameterValue(
			TEXT("WallTint"),
			FLinearColor(FColor::FromHex(TEXT("#FFFFFF"))));
		
		MPC->SetVectorParameterValue(
			TEXT("CharacterTint"),
			FLinearColor(FColor::FromHex(TEXT("#FFFFFF"))));
		break;

	}
}


void UOptionsMenuWidget::DeficiencyTypeUpdate(FString Value, ESelectInfo::Type NewType)
{
	ColourDeficiencyIndex = ColourDeficiencyType->GetSelectedIndex();
	
	if (UAccessibilityGameInstance* GameInstance = Cast<UAccessibilityGameInstance>(GetGameInstance()))
	{
		 GameInstance->ColourDeficiencyIndex = ColourDeficiencyIndex;
	}
	
	UpdateColourDeficiencyTint();
}
