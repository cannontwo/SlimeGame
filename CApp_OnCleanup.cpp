#include "CApp.h"

void CApp::OnCleanup() {
    CAppStateManager::SetActiveAppState(APPSTATE_NONE);

    SDL_FreeSurface(Surf_Display);
    SDL_Quit();
}

