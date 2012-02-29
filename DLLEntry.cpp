#include "Alembic.h"
#include "AlembicDefinitions.h"
#include "iparamm2.h"

extern ClassDesc2* GetAlembicExporterDesc();
extern ClassDesc* GetAlembicXFormModifierDesc();
extern ClassDesc* GetAlembicPolyMeshModifierDesc();
extern ClassDesc* GetAlembicCameraModifierDesc();

HINSTANCE hInstance;

BOOL WINAPI DllMain(HINSTANCE hinstDLL,ULONG fdwReason,LPVOID lpvReserved)
{
   if( fdwReason == DLL_PROCESS_ATTACH )
   {
      hInstance = hinstDLL;
      DisableThreadLibraryCalls(hInstance);
   }

   return (TRUE);
}

#define MAX_DLL_EXPORT extern "C" __declspec( dllexport )

MAX_DLL_EXPORT const TCHAR* LibDescription()
{
   return "Exocortex Alembic for 3DS Max";
}

//TODO: Must change this number when adding a new class
MAX_DLL_EXPORT int LibNumberClasses()
{
   return 4;
}

MAX_DLL_EXPORT ClassDesc* LibClassDesc(int i)
{
   switch(i) {
      case 0: return GetAlembicExporterDesc();
	  case 1: return GetAlembicXFormModifierDesc();
	  case 2: return GetAlembicPolyMeshModifierDesc();
      case 3: return GetAlembicCameraModifierDesc();

      default: return 0;
   }
}

MAX_DLL_EXPORT ULONG LibVersion()
{
   return VERSION_3DSMAX;
}

// Let the plug-in register itself for deferred loading
MAX_DLL_EXPORT ULONG CanAutoDefer()
{
   return 0;
}