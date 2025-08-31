// By hzFishy - 2025 - Do whatever you want with it.


#include "Subsystems/FWSWorldSpaceLocalSubsystem.h"
#include "FWSWorldSpaceContainerWidgetGetter.h"
#include "GameFramework/HUD.h"
#include "Widgets/FWSWorldSpaceContainerWidget.h"

	
	/*----------------------------------------------------------------------------
		Defaults
	----------------------------------------------------------------------------*/
void UFWSWorldSpaceLocalSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UFWSWorldSpaceLocalSubsystem::PlayerControllerChanged(APlayerController* NewPlayerController)
{
	Super::PlayerControllerChanged(NewPlayerController);

	PlayerController = NewPlayerController;
}

	
	/*----------------------------------------------------------------------------
		Core
	----------------------------------------------------------------------------*/
APlayerController* UFWSWorldSpaceLocalSubsystem::GetPlayerController() const
{
	return PlayerController.Get();
}

void UFWSWorldSpaceLocalSubsystem::AddWorldSpaceWidget(const FFWSWorldSpaceSubsystemParams& Params)
{
	if (PlayerController.IsValid() && IsValid(PlayerController->GetHUD()))
	{
		if (PlayerController->GetHUD()->Implements<UFWSWorldSpaceContainerWidgetGetter>())
		{
			if (auto* Container = IFWSWorldSpaceContainerWidgetGetter::Execute_GetWorldSpaceContainerWidget(PlayerController->GetHUD()))
			{
				Container->AddWidget(Params);
			}
		}
	}
}
