// Copyright Epic Games, Inc. All Rights Reserved.

#include "Puzzle1GameMode.h"
#include "Puzzle1Character.h"
#include "UObject/ConstructorHelpers.h"

APuzzle1GameMode::APuzzle1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
