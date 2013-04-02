#include "CAppStateEnd.h"

#include "CAppStateManager.h"

CAppStateEnd CAppStateEnd::Instance;

std::vector<CAppStateMessage*> CAppStateEnd::MessageList;

CAppStateEnd::CAppStateEnd() {
    Surf_Message = NULL;
    Surf_Back = NULL;
    Surf_RestartButton = NULL;
    Surf_QuitButton = NULL;
    Surf_MenuButton = NULL;
}

void CAppStateEnd::OnActivate() {
     for(int i = 0; i < MessageList.size(); i++) {
        if(MessageList[i]->boolMessage == true) {
            Surf_Message = CSurface::OnLoad("images/win.png");
        } else if(MessageList[i]->boolMessage == false) {
            Surf_Message = CSurface::OnLoad("images/lose.png");
        }
     }
     Surf_QuitButton = CSurface::OnLoad("images/quit_button.png");
     Surf_RestartButton = CSurface::OnLoad("images/restart_button.png");
     Surf_Back = CSurface::OnLoad("images/background.png");
     Surf_MenuButton = CSurface::OnLoad("images/menu_button.png");
}

void CAppStateEnd::OnDeactivate() {
    if(Surf_Back) {
        SDL_FreeSurface(Surf_Back);
    }
}

void CAppStateEnd::OnLoop() {
    return;
}

void CAppStateEnd::OnRender(SDL_Surface* Surf_Display) {
    if(Surf_Message) {
        CSurface::OnDraw(Surf_Back,Surf_Message,0,-200);
    }
    if(Surf_RestartButton) {
        CSurface::OnDraw(Surf_Back, Surf_RestartButton, (WWIDTH / 2) - (Surf_RestartButton->w / 2), 200 + ((WHEIGHT / 2) - (2 * Surf_RestartButton->h)));
    }
    if(Surf_MenuButton) {
        CSurface::OnDraw(Surf_Back, Surf_MenuButton, (WWIDTH / 2) - (Surf_MenuButton->w / 2), 200 + (WHEIGHT / 2));
    }
    if(Surf_QuitButton) {
        CSurface::OnDraw(Surf_Back, Surf_QuitButton, (WWIDTH / 2) - (Surf_QuitButton->w / 2), 200 + ((WHEIGHT / 2) + (2 * Surf_QuitButton->h)));
    }
    if(Surf_Back) {
        CSurface::OnDraw(Surf_Display, Surf_Back, 0, 0);
    }
}

CAppStateEnd* CAppStateEnd::GetInstance() {
    return &Instance;
}

void CAppStateEnd::OnLButtonDown(int mX, int mY) {
        if(LButtonDownCheck(mX,mY,Surf_RestartButton, (WWIDTH / 2) - (Surf_RestartButton->w / 2), 200 + ((WHEIGHT / 2) - (2 * Surf_RestartButton->h)))) {
            CAppStateManager::SetActiveAppState(APPSTATE_GAME);
        }
        if(LButtonDownCheck(mX,mY,Surf_QuitButton, (WWIDTH / 2) - (Surf_QuitButton->w / 2), 200 + ((WHEIGHT / 2) + (2 * Surf_QuitButton->h)))) {
            SDL_Quit();
        }
        if(LButtonDownCheck(mX,mY,Surf_MenuButton, (WWIDTH / 2) - (Surf_MenuButton->w / 2), 200 + (WHEIGHT / 2))) {
            CAppStateManager::SetActiveAppState(APPSTATE_MAINMENU);
        }

}

void CAppStateEnd::OnReceiveMessage(CAppStateMessage* Message) {
    MessageList.push_back(Message);
    return;
}

bool CAppStateEnd::LButtonDownCheck(int mX, int mY, SDL_Surface* Surf_Button, int x, int y) {
    if (mX < x + (Surf_Button->w)) {
            if (mX > x) {
                if (mY < y + (Surf_Button->h)) {
                    if(mY > y) {
                        return true;
                    }
                    return false;
                }
                return false;
            }
            return false;
        }
        return false;
}

