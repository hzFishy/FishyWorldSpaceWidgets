// By hzFishy - 2025 - Do whatever you want with it.

#pragma once

#include "Data/FWSCoreTypes.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "FWSWorldSpaceLocalSubsystem.generated.h"


/**
 * Manages the world space widgets
 */
UCLASS()
class FISHYWORLDSPACEWIDGETS_API UFWSWorldSpaceLocalSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()

	/*----------------------------------------------------------------------------
		Properties
	----------------------------------------------------------------------------*/
protected:
	TWeakObjectPtr<APlayerController> PlayerController;


	/*----------------------------------------------------------------------------
		Defaults
	----------------------------------------------------------------------------*/
protected:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	
	virtual void PlayerControllerChanged(APlayerController* NewPlayerController) override;


	/*----------------------------------------------------------------------------
		Core
	----------------------------------------------------------------------------*/
public:
	UFUNCTION(BlueprintPure, Category="FishyWorldSpaceWidgets")
	APlayerController* GetPlayerController() const;
	
	/** Add the given widget to the tracking system, PlayerController needs to be valid */
	UFUNCTION(BlueprintCallable, Category="FishyWorldSpaceWidgets")
	virtual void AddWorldSpaceWidget(const FFWSWorldSpaceSubsystemParams& Params);
};
