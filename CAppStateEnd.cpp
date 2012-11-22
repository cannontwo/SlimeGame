#include "CAppStateEnd.h"

#include "CAppStateManager.h"

CAppStateEnd CAppStateEnd::Instance;

CAppStateEnd::CAppStateEnd() {
    Surf_End = NULL;
}

void CAppStateEnd::OnActivate() {
    if (Win) {
        Surf_End = CSurface::OnLoad("win.png");
    } else {
        Surf_End = CSurface::OnLoad("lose.png");
    }
}

void CAppStateEnd::OnDeactivate() {
    if(Surf_End) {
        SDL_FreeSurface(Surf_End);
    }
}

void CAppStateEnd::OnLoop() {
}

void CAppStateEnd::OnRender(SDL_Surface* Surf_Display) {
    if(Surf_End) {
        CSurface::OnDraw(Surf_Display, Surf_End, 0, 0);
    }
}

CAppStateEnd* CAppStateEnd::GetInstance() {
    return &Instance;
}

void CAppStateEnd::OnLButtonDown(int mX, int mY) {
    SDL_Quit();
}
