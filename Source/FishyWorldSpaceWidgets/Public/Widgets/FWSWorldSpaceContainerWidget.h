// By hzFishy - 2025 - Do whatever you want with it.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Data/FWSCoreTypes.h"
#include "FWSWorldSpaceContainerWidget.generated.h"
class UOverlaySlot;


struct FFWSWorldSpaceContainerEntry
{
	FFWSWorldSpaceContainerEntry(const FFWSWorldSpaceSubsystemParams& InParams);
	
	FFWSWorldSpaceSubsystemParams Params;

	TWeakObjectPtr<UOverlaySlot> OverlaySlot;
};


/**
 * Contains widgets displayed in screen space from target data.
 * Widgets are automatically removed if invalid.
 * 
 * This is meant to be unique by player.
 */
UCLASS(ClassGroup=FishyWorldSpaceWidgets)
class FISHYWORLDSPACEWIDGETS_API UFWSWorldSpaceContainerWidget : public UUserWidget
{
	GENERATED_BODY()


	/*----------------------------------------------------------------------------
		Properties
	----------------------------------------------------------------------------*/
protected:
	TArray<FFWSWorldSpaceContainerEntry> ManagedEntries;


	/*----------------------------------------------------------------------------
		Defaults
	----------------------------------------------------------------------------*/
protected:
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;


	/*----------------------------------------------------------------------------
		Core
	----------------------------------------------------------------------------*/
public:
	void AddWidget(const FFWSWorldSpaceSubsystemParams& Params);
	
protected:
	virtual void TickEntries();
	
	UFUNCTION(BlueprintImplementableEvent, DisplayName="Add Widget To Container")
	UOverlaySlot* K2_AddWidgetToContainer(UUserWidget* Widget);
};
