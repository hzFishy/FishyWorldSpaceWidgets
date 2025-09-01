// By hzFishy - 2025 - Do whatever you want with it.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FWSWorldSpaceContainerWidgetGetter.generated.h"
class UFWSWorldSpaceContainerWidget;


UINTERFACE(DisplayName="World Space Container Widget Getter")
class UFWSWorldSpaceContainerWidgetGetter : public UInterface
{
	GENERATED_BODY()
};


/**
 * Implement in the HUD to get the UFWSWorldSpaceContainerWidget instance
 */
class FISHYWORLDSPACEWIDGETS_API IFWSWorldSpaceContainerWidgetGetter
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="FishyWorldSpaceWidgets")
	UFWSWorldSpaceContainerWidget* GetWorldSpaceContainerWidget() const;
};
