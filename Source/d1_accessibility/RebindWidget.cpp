// Fill out your copyright notice in the Description page of Project Settings.


#include "RebindWidget.h"
#include "UserSettings/EnhancedInputUserSettings.h"
#include "EnhancedInputSubsystems.h"
#include "Components/TextBlock.h"

void URebindWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if (BackButton)
	{
		BackButton->OnClicked.AddDynamic(this,&URebindWidget::CloseMenu);
	}
	
	AddInputRows();
}

void URebindWidget::CloseMenu()
{
	RemoveFromParent();
}

FReply URebindWidget::NativeOnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{
	// validates ActiveInputSlot (is true)
	if (ActiveInputSlot)
	{
		FKey PressedKey = InKeyEvent.GetKey();
		RebindKey(PressedKey);
        
		// Tells Slate the input was consumed so other window layers ignore it
		return FReply::Handled();
	}

	return Super::NativeOnKeyDown(MyGeometry, InKeyEvent);
}

void URebindWidget::RebindKey(FKey NewKey)
{
	// Active Input Slot check
	if (!ActiveInputSlot) return;
	
	// Make Map Player Key Args 
	FMapPlayerKeyArgs Args;
	Args.MappingName = ActiveInputSlot->KeyMappingName; 
	Args.Slot = EPlayerMappableKeySlot::First;        
	Args.NewKey = NewKey;
	
	
	APlayerController* PlayerController = GetOwningPlayer();
	if (!PlayerController) return;
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
	if (!Subsystem) return;
	
	UEnhancedInputUserSettings* Settings = Subsystem->GetUserSettings();
	if (!Settings) return;
	     

	// Map Player Key node
	FGameplayTagContainer FailureReason;		// we dont use the value but if the rebind fails, Unreal Engine will use it to give errors
	Settings->MapPlayerKey(Args, FailureReason);  // rebind process

	
	if (ActiveInputSlot->ButtonTextBlock)
	{
		FText KeyDisplayName = NewKey.GetDisplayName();
		ActiveInputSlot->ButtonTextBlock->SetText(KeyDisplayName);
	}
	
	Settings->SaveSettings();
	ActiveInputSlot = nullptr;
}


void URebindWidget::AddInputRows()
{
	// Get Owning Player
	APlayerController* PlayerController = GetOwningPlayer();

	if (!PlayerController) return;

	// Get Enhanced Input Local Player Subsystem
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());

	if (!Subsystem) return;

	// Get Enhanced Input User Settings - stores remappable keys and saved bindings
	UEnhancedInputUserSettings* Settings = Subsystem->GetUserSettings();

	if (!Settings) return;

	// Get Active Key Profile - profile contains all mappings currently active for the player
	UEnhancedPlayerMappableKeyProfile* Profile = Settings->GetActiveKeyProfile();

	if (!Profile) return;
	
	
	// Get all mapping names
	// GetPlayerMappingRows() returns a TMap<FName, FKeyMappingRow>. But we only need the names
	TArray<FName> MappingNames;
	Profile->GetPlayerMappingRows().GetKeys(MappingNames);

	// if (GEngine)
	// {
	// 	int32 Size = MappingNames.Num();
	//
	// 	GEngine->AddOnScreenDebugMessage(
	// 		-1,
	// 		5.0f,
	// 		FColor::Cyan,
	// 		FString::Printf(TEXT("MappingNames size: %d"), Size)
	// 	);
	// }
	
	for (FName Name : MappingNames)
	{
		// Create Input Slot Widget
		UInputSlotWidget* InputSlot = CreateWidget<UInputSlotWidget>(GetWorld(),InputSlotWidgetClass);

		if (!InputSlot) continue;

		// Pass mapping name into Input Slot Widget 
		InputSlot->KeyMappingName = Name;
		InputSlot->RebindWidget = this;

		// Make Map Player Key Args - Find the first keyboard slot for this action
		FMapPlayerKeyArgs Args;
		Args.MappingName = Name;
		Args.Slot = EPlayerMappableKeySlot::First;

		// Find mapping
		FPlayerKeyMapping* KeyMapping = Profile->FindKeyMapping(Args);

		if (!KeyMapping) return;
		
		// Set action - Jump
		if (InputSlot->TextBlock)
		{
			InputSlot->TextBlock->SetText(KeyMapping->GetDisplayName());
		}

		// Set key - Space Bar
		if (InputSlot->ButtonTextBlock)
		{
			InputSlot->ButtonTextBlock->SetText(KeyMapping->GetCurrentKey().GetDisplayName());
		}
		
		GEngine->AddOnScreenDebugMessage(
			-1,
			5.0f,
			FColor::Green,
			FString::Printf(
			TEXT("%s: %s"),
			*KeyMapping->GetDisplayName().ToString(),
			*KeyMapping->GetCurrentKey().GetDisplayName().ToString()
		)
		);
		
		VBox->AddChild(InputSlot);
		
	}
	
	// int32 Count = VBox->GetChildrenCount();
	// GEngine->AddOnScreenDebugMessage(
	// 	-1,
	// 	5.0f,
	// 	FColor::Cyan,
	// 	FString::Printf(TEXT("VBox children: %d"), Count)
	// );
	
}

void URebindWidget::OnKeyButton(UInputSlotWidget* InputSlot)
{
	ActiveInputSlot = InputSlot;
	SetKeyboardFocus();
}

