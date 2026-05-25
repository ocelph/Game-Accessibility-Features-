// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class d1_accessibility : ModuleRules
{
	public d1_accessibility(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"d1_accessibility",
			"d1_accessibility/Variant_Platforming",
			"d1_accessibility/Variant_Platforming/Animation",
			"d1_accessibility/Variant_Combat",
			"d1_accessibility/Variant_Combat/AI",
			"d1_accessibility/Variant_Combat/Animation",
			"d1_accessibility/Variant_Combat/Gameplay",
			"d1_accessibility/Variant_Combat/Interfaces",
			"d1_accessibility/Variant_Combat/UI",
			"d1_accessibility/Variant_SideScrolling",
			"d1_accessibility/Variant_SideScrolling/AI",
			"d1_accessibility/Variant_SideScrolling/Gameplay",
			"d1_accessibility/Variant_SideScrolling/Interfaces",
			"d1_accessibility/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
