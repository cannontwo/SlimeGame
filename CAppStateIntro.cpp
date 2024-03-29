#include "CAppStateIntro.h"

#include "CAppStateManager.h"

CAppStateIntro CAppStateIntro::Instance;

CAppStateIntro::CAppStateIntro() {
    Surf_Logo = NULL;
}

void CAppStateIntro::OnActivate() {
    // Load Simple Logo
    Surf_Logo = CSurface::OnLoad("images/splash.png");

    StartTime = SDL_GetTicks();
}

void CAppStateIntro::OnDeactivate() {
    if(Surf_Logo) {
        SDL_FreeSurface(Surf_Logo);
    }
}

void CAppStateIntro::OnLoop() {
    if(StartTime + 3000 < SDL_GetTicks()) {
        CAppStateManager::SetActiveAppState(APPSTATE_MAINMENU);
    }
}

void CAppStateIntro::OnRender(SDL_Surface* Surf_Display) {
    if(Surf_Logo) {
        CSurface::OnDraw(Surf_Display, Surf_Logo, 0, 0);
    }
}

CAppStateIntro* CAppStateIntro::GetInstance() {
    return &Instance;
}

void CAppStateIntro::OnReceiveMessage(CAppStateMessage* Message) {
}

void CAppStateIntro::OnLButtonDown(int mX, int mY) {
    CAppStateManager::SetActiveAppState(APPSTATE_MAINMENU);
}
