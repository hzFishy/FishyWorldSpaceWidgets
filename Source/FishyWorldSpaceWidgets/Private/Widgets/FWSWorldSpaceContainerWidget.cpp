// By hzFishy - 2025 - Do whatever you want with it.


#include "Widgets/FWSWorldSpaceContainerWidget.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Components/OverlaySlot.h"


FFWSWorldSpaceContainerEntry::FFWSWorldSpaceContainerEntry(const FFWSWorldSpaceSubsystemParams& InParams)
{
	Params = InParams;
}

	
	/*----------------------------------------------------------------------------
		Defaults
	----------------------------------------------------------------------------*/
void UFWSWorldSpaceContainerWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	TickEntries();
}

	
	/*----------------------------------------------------------------------------
		Core
	----------------------------------------------------------------------------*/
void UFWSWorldSpaceContainerWidget::AddWidget(const FFWSWorldSpaceSubsystemParams& Params)
{
	if (!ensureAlways(Params.TargetUserWidget.IsValid())) { return; }
	
	FFWSWorldSpaceContainerEntry NewEntry(Params);
	NewEntry.OverlaySlot = K2_AddWidgetToContainer(Params.TargetUserWidget.Get());
	ManagedEntries.Add(NewEntry);
}

void UFWSWorldSpaceContainerWidget::TickEntries()
{
	for (int i = ManagedEntries.Num() - 1; i >= 0; i--)
	{
		const auto& Entry = ManagedEntries[i];

		// tick if:
		// - Widget valid
		// - Widget visible
		// - If we have a not null target scene component it must be valid

		// remove if:
		// - widget invalid
		// - bRemoveIfInvalidatedTargetSceneComponent true and TargetSceneComponent stale
		
		bool bRemoveEntry = !Entry.Params.TargetUserWidget.IsValid();
		if (!bRemoveEntry)
		{
			// dont check for validity if this was never set
			if (!Entry.Params.TargetSceneComponent.IsExplicitlyNull())
			{
				bRemoveEntry = Entry.Params.bRemoveIfInvalidatedTargetSceneComponent && Entry.Params.TargetSceneComponent.IsStale();
			}

			if (!bRemoveEntry)
			{
				if (Entry.Params.TargetUserWidget->IsVisible())
				{
					FVector2D FoundScreenPosition;
					const bool bValidProjection = UWidgetLayoutLibrary::ProjectWorldLocationToWidgetPosition(
						GetOwningPlayer(),
						Entry.Params.GetFinalTargetLocation(),
						FoundScreenPosition,
						false
					);
					
					if (bValidProjection)
					{
						const auto& Size = Entry.Params.TargetUserWidget->GetDesiredSize();
						FoundScreenPosition.X -= Size.X/2;
						FoundScreenPosition.Y -= Size.Y/2;
						
						FMargin Margin;
						Margin.Top = FoundScreenPosition.Y;
						Margin.Left = FoundScreenPosition.X;
						Margin.Bottom = -FoundScreenPosition.Y;
						Margin.Right = -FoundScreenPosition.X;

						// will update the widget position
						Entry.OverlaySlot->SetPadding(Margin);
					}
				}
			}
		}
		
		if (bRemoveEntry)
		{
			ManagedEntries.RemoveAt(i);
		}
	}
}
