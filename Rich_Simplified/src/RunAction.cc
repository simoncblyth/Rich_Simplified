#include <cassert>

#ifdef WITH_OPTICKS
#include "G4TransportationManager.hh"
#include "G4Opticks.hh"
#endif

#include "RunAction.hh"

RunAction::RunAction(Ctx* ctx_) 
    :   
    G4UserRunAction(),
    ctx(ctx_)
{
}
void RunAction::BeginOfRunAction(const G4Run*)
{
    startTime = clock();
}
void RunAction::EndOfRunAction(const G4Run*)
{
    endTime = clock();
}

double RunAction::getTime()
{
    return (double)(endTime - startTime) / CLOCKS_PER_SEC;
}
