// By hzFishy - 2025 - Do whatever you want with it.

#include "FishyWorldSpaceWidgets.h"

#define LOCTEXT_NAMESPACE "FFishyWorldSpaceWidgetsModule"

void FFishyWorldSpaceWidgetsModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FFishyWorldSpaceWidgetsModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FFishyWorldSpaceWidgetsModule, FishyWorldSpaceWidgets)