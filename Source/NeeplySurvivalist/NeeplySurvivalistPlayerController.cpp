// Copyright Epic Games, Inc. All Rights Reserved.


#include "NeeplySurvivalistPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "NeeplySurvivalistCameraManager.h"

ANeeplySurvivalistPlayerController::ANeeplySurvivalistPlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = ANeeplySurvivalistCameraManager::StaticClass();
}

void ANeeplySurvivalistPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
}
