#include "CApp.h"

void CApp::OnRender() {
    CAppStateManager::OnRender(Surf_Display);

    SDL_Flip(Surf_Display);
}
