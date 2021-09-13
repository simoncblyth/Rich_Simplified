//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
//
// $Id: RichTbPhotoElectron.h,v 1.1 2003/04/29 15:04:49 seaso Exp $
// GEANT4 tag $Name:  $
//
// 
// ------------------------------------------------------------
//      GEANT 4 class header file
//
//      History: first implementation, based on object model of
//      4-th April 1996, G.Cosmo
// ****************************************************************
//  Added particle definitions, H.Kurashige, 19 April 1996
//  Added SetCuts implementation for Electron, L.Urban, 30 May 1996
//  Added not static GetEnergyCuts() and GetLengthCuts(), G.Cosmo, 11 July 1996
// ----------------------------------------------------------------

// Each class inheriting from G4VLepton
// corresponds to a particle type; one and only one
// instance for each class is guaranteed.
// RichTbPhotoElectron created by SE 10-3-2003.
#ifndef RichTbPhotoElectron_h
#define RichTbPhotoElectron_h 1

#include "globals.hh"
#include "G4ios.hh"
//#include "Geant4/G4VLepton.hh"
#include "G4ParticleDefinition.hh"
class G4Positron;
// ######################################################################
// ###                         RICHPHOTOELECTRON                      ###
// ######################################################################

class RichTbPhotoElectron : public G4ParticleDefinition
{
  // friend class G4Positron;
 private:
   static RichTbPhotoElectron* theRichTbPhotoElectronInstance;

 private: //hide constructor as private

 public:
   virtual ~RichTbPhotoElectron(){}

   static RichTbPhotoElectron* Definition();
   static RichTbPhotoElectron* PhotoElectronDefinition();
   static RichTbPhotoElectron* PhotoElectron();

};

#endif











