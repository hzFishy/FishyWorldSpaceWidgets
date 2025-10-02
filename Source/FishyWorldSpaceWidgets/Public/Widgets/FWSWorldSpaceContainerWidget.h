// By hzFishy - 2025 - Do whatever you want with it.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Data/FWSCoreTypes.h"
#include "FWSWorldSpaceContainerWidget.generated.h"
class UOverlaySlot;


struct FISHYWORLDSPACEWIDGETS_API FFWSWorldSpaceContainerEntry
{
	FFWSWorldSpaceContainerEntry(const FFWSWorldSpaceSubsystemParams& InParams);
	
	FFWSWorldSpaceSubsystemParams Params;

	TWeakObjectPtr<UOverlaySlot> OverlaySlot;
};


/**
 * Contains widgets displayed in screen space from target data.
 * Widgets are automatically removed if invalid.
 * 
 * This is meant to be unique for one player.
 * 
 * You MUST implement K2_AddWidgetToContainer with an Overlay.
 */
UCLASS(ClassGroup=FishyWorldSpaceWidgets, DisplayName="World Space Container Widget", Abstract)
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

	/** This uses overlay slots */
	UFUNCTION(BlueprintImplementableEvent, DisplayName="Add Widget To Container")
	UOverlaySlot* K2_AddWidgetToContainer(UUserWidget* Widget);
};
