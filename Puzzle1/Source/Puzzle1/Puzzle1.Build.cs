// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Puzzle1 : ModuleRules
{
	public Puzzle1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
