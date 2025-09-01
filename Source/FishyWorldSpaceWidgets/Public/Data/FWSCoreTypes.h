// By hzFishy - 2025 - Do whatever you want with it.

#pragma once

#include "FWSCoreTypes.generated.h"


USTRUCT(BlueprintType, DisplayName="World Space Subsystem Params")
struct FISHYWORLDSPACEWIDGETS_API FFWSWorldSpaceSubsystemParams
{
	GENERATED_BODY()

	FFWSWorldSpaceSubsystemParams();
	
	/** The widget that we will move around */
	UPROPERTY(BlueprintReadWrite, Category = "FishyWorldSpaceWidgets")
	TWeakObjectPtr<UUserWidget> TargetUserWidget;
	
	/** If valid we use this scene component location instead of TargetLocation */
	UPROPERTY(BlueprintReadWrite, Category = "FishyWorldSpaceWidgets")
	TWeakObjectPtr<USceneComponent> TargetSceneComponent;
	
	/** See TargetSceneComponent */
	UPROPERTY(BlueprintReadWrite, Category = "FishyWorldSpaceWidgets")
	FVector TargetLocation;

	/** If TargetSceneComponent is stale remove */
	UPROPERTY(BlueprintReadWrite, Category = "FishyWorldSpaceWidgets")
	bool bRemoveIfInvalidatedTargetSceneComponent;

	/** Return the final target location we will use */
	FVector GetFinalTargetLocation() const;
};
