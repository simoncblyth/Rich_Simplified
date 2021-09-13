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
// $Id: G4OpAbsorption.hh,v 1.7 2001/08/31 16:43:32 gum Exp $
// GEANT4 tag $Name: geant4-07-00 $
//
////////////////////////////////////////////////////////////////////////
// Optical Photon Absorption Class Definition
////////////////////////////////////////////////////////////////////////
//
// File:        RichTbG4OpAbsorption.hh
// Description: Discrete Process -- Bulk absorption of Optical Photons
// Version:     1.0
// Created:     1996-05-21
// Author:      Juliet Armstrong
// Updated:     1999-10-29 add method and class descriptors
//              1997-04-09 by Peter Gumplinger
//              > new physics/tracking scheme
//              1998-08-25 by Stefano Magni
//              > Change process to use G4MaterialPropertiesTables
// mail:        gum@triumf.ca
//              magni@mi.infn.it
//
////////////////////////////////////////////////////////////////////////

#ifndef RichTbG4OpAbsorption_h
#define RichTbG4OpAbsorption_h 1

////////////
// Includes
/////////////

#include "globals.hh"
#include "templates.hh"
#include "Randomize.hh"
#include "G4Step.hh"
#include "G4VDiscreteProcess.hh"
#include "G4DynamicParticle.hh"
#include "G4Material.hh"
#include "G4OpticalPhoton.hh"

// Class Description:
// Discrete Process -- Bulk absorption of Optical Photons.
// Class inherits publicly from G4VDiscreteProcess
// Class Description - End:

/////////////////////
// Class Definition
/////////////////////

class RichTbG4OpAbsorption : public G4VDiscreteProcess 
{

private:

        //////////////
        // Operators
        //////////////

        // RichTbG4OpAbsorption& operator=(const RichTbG4OpAbsorption &right);

public: // Without description

        ////////////////////////////////
        // Constructors and Destructor
        ////////////////////////////////

        RichTbG4OpAbsorption(const G4String& processName = "OpAbsorption");

        // RichTbG4OpAbsorption(const RichTbG4OpAbsorption &right);

	~RichTbG4OpAbsorption();

	////////////
	// Methods
        ////////////

public: // With description

        G4bool IsApplicable(const G4ParticleDefinition& aParticleType);
        // Returns true -> 'is applicable' only for an optical photon.

	G4double GetMeanFreePath(const G4Track& aTrack,
				 G4double ,
				 G4ForceCondition* );
        // Returns the absorption length for bulk absorption of optical
        // photons in media with a specified attenuation length. 

	G4VParticleChange* PostStepDoIt(const G4Track& aTrack,
 				        const G4Step&  aStep);
        // This is the method implementing bulk absorption of optical 
        // photons.

};

////////////////////
// Inline methods
////////////////////

inline
G4bool RichTbG4OpAbsorption::IsApplicable(const G4ParticleDefinition& aParticleType)
{
   return ( &aParticleType == G4OpticalPhoton::OpticalPhoton() );
}

#endif /* RichTbG4OpAbsorption_h */
