#include "CAppStateEnd.h"

#include "CAppStateManager.h"

CAppStateEnd CAppStateEnd::Instance;

std::vector<CAppStateMessage*> CAppStateEnd::MessageList;

CAppStateEnd::CAppStateEnd() {
    Surf_End = NULL;
}

void CAppStateEnd::OnActivate() {
     for(int i = 0; i < MessageList.size(); i++) {
        char Buffer[255];
        sprintf(Buffer,"Player Health: %d", MessageList.size());
        SDL_WM_SetCaption(Buffer,Buffer);

        if(MessageList[i]->boolMessage == true) {
            Surf_End = CSurface::OnLoad("images/win.png");
        } else if(MessageList[i]->boolMessage == false) {
            Surf_End = CSurface::OnLoad("images/lose.png");
        }
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

void CAppStateEnd::OnReceiveMessage(CAppStateMessage Message) {
    MessageList.push_back(&Message);
}
