// By hzFishy - 2025 - Do whatever you want with it.

#include "Data/FWSCoreTypes.h"


FFWSWorldSpaceSubsystemParams::FFWSWorldSpaceSubsystemParams():
	TargetLocation(FVector::ZeroVector),
	bRemoveIfInvalidatedTargetSceneComponent(true)
{}

FVector FFWSWorldSpaceSubsystemParams::GetFinalTargetLocation() const
{
	return TargetSceneComponent.IsValid() ? TargetSceneComponent->GetComponentLocation() : TargetLocation;
}
