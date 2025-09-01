// By hzFishy - 2025 - Do whatever you want with it.


#include "Subsystems/FWSWorldSpaceLocalSubsystem.h"
#include "Interfaces/FWSWorldSpaceContainerWidgetGetter.h"
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
		if (ensureAlways(PlayerController->GetHUD()->Implements<UFWSWorldSpaceContainerWidgetGetter>()))
		{
			auto* Container = IFWSWorldSpaceContainerWidgetGetter::Execute_GetWorldSpaceContainerWidget(PlayerController->GetHUD());
			if (ensureAlways(Container))
			{
				Container->AddWidget(Params);
			}
		}
	}
}
