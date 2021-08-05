// This code implementation is the intellectual property of
// the GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: RichTbVisManager.cc,v 1.3 2003/10/10 16:59:29 abuckley Exp $
// GEANT4 tag $Name:  $
//
//
// John Allison 24th January 1998.

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

#include "RichTbVisManager.hh"

// Supported drivers...

//#ifdef G4VIS_USE_DAWN
//#include "G4FukuiRenderer.hh"
//#endif

//#ifdef G4VIS_USE_DAWNFILE
//#include "G4DAWNFILE.hh"
//#endif

//#ifdef G4VIS_USE_OPACS
//#include "G4Wo.hh"
//#include "G4Xo.hh"
//#endif

//#ifdef G4VIS_USE_OPENGLX
#include "G4OpenGLImmediateX.hh"
#include "G4OpenGLStoredX.hh"
//#endif

//#ifdef G4VIS_USE_OPENGLWIN32
//#include "G4OpenGLImmediateWin32.hh"
//#include "G4OpenGLStoredWin32.hh"
//#endif

//#ifdef G4VIS_USE_OPENGLXM
//#endif

 //#ifdef G4VIS_USE_OIX
// #include "G4OpenInventorX.hh"
 //#endif

//#ifdef G4VIS_USE_OIWIN32
//#include "G4OpenInventorWin32.hh"
//#endif

//ifdef G4VIS_USE_VRML
//#include "G4VRML1.hh"
//#include "G4VRML2.hh"
//endif

//ifdef G4VIS_USE_VRMLFILE
//#include "G4VRML1File.hh"
//#include "G4VRML2File.hh"
//endif

//ifdef G4VIS_USE_RAYTRACER
//#include "G4RayTracer.hh"
//endif
//#ifdef G4VIS_USE
//#include "G4VisExecutive.hh"
//#endif




//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

RichTbVisManager* RichTbVisManager::RichTbVisManagerInstance=0;

RichTbVisManager::RichTbVisManager()
{

  //RegisterGraphicsSystems();
  
  // visualization manager
  // G4VisManager* visManagerE = new G4VisExecutive;
  //  visManagerE->Initialize();

    
}


RichTbVisManager::~RichTbVisManager()
{
    ;
}
RichTbVisManager* RichTbVisManager::getRichTbVisManagerInstance()
{
  if(RichTbVisManagerInstance == 0 ) {
    RichTbVisManagerInstance = new RichTbVisManager();
    
  }
  return RichTbVisManagerInstance;
  
  
}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....

void RichTbVisManager::RegisterGraphicsSystems()
{

  //#ifdef G4VIS_USE_DAWN
  //  RegisterGraphicsSystem(new G4FukuiRenderer);
    //#endif

    //#ifdef G4VIS_USE_DAWNFILE
  //  RegisterGraphicsSystem(new G4DAWNFILE);
    //#endif

  //#ifdef G4VIS_USE_OPACS
  //      RegisterGraphicsSystem(new G4Wo);
  //  RegisterGraphicsSystem(new G4Xo);
  //#endif

    //#ifdef G4VIS_USE_OPENGLX
    //#endif

  //#ifdef G4VIS_USE_OPENGLWIN32
  //  RegisterGraphicsSystem(new G4OpenGLImmediateWin32);
  //  RegisterGraphicsSystem(new G4OpenGLStoredWin32);
  //#endif

    //#ifdef G4VIS_USE_OPENGLXM
    //#endif

  //#ifdef G4VIS_USE_OIX
    //  RegisterGraphicsSystem (new G4OpenInventorX);
  //#endif

  //#ifdef G4VIS_USE_OIWIN32
  //  RegisterGraphicsSystem(new G4OpenInventorWin32);
  //#endif

    //#ifdef G4VIS_USE_VRML
  // RegisterGraphicsSystem(new G4VRML1);
  //  RegisterGraphicsSystem(new G4VRML2);
    //#endif

    //#ifdef G4VIS_USE_VRMLFILE
  // RegisterGraphicsSystem(new G4VRML1File);
  //  RegisterGraphicsSystem(new G4VRML2File);
    //#endif

    //#ifdef G4VIS_USE_RAYTRACER
  // RegisterGraphicsSystem(new G4RayTracer);
    //#endif

    //#ifdef G4VIS_USE
    //#endif



  //    if (fVerbose > 0) {
  //      G4cout << "\nYou have successfully chosen to use the following graphics systems." << G4endl;
  //      PrintAvailableGraphicsSystems();
  //  }
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo....
