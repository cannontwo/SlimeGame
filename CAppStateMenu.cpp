#include "CAppStateMenu.h"

#include "CAppStateManager.h"

CAppStateMenu CAppStateMenu::Instance;


CAppStateMenu::CAppStateMenu() {
    Surf_Transition = NULL;
    Surf_QuitButton = NULL;
    Surf_ResumeButton = NULL;
    Surf_OptionsButton = NULL;
    Surf_MenuButton = NULL;
}

void CAppStateMenu::OnActivate() {
    Surf_Transition = CSurface::OnLoad("images/transition.png");
    Surf_QuitButton = CSurface::OnLoad("images/quit_button.png");
    Surf_ResumeButton = CSurface::OnLoad("images/resume_button.png");
    Surf_OptionsButton = CSurface::OnLoad("images/options_button.png");
    Surf_MenuButton = CSurface::OnLoad("images/menu_button.png");
}

void CAppStateMenu::OnDeactivate() {
    if(Surf_Transition) {
        SDL_FreeSurface(Surf_Transition);
    }
}

void CAppStateMenu::OnLoop() {

}

void CAppStateMenu::OnRender(SDL_Surface* Surf_Display) {
    if(Surf_ResumeButton) {
        CSurface::OnDraw(Surf_Transition, Surf_ResumeButton, (WWIDTH / 2) - (Surf_ResumeButton->w / 2), (WHEIGHT / 2) - (Surf_ResumeButton->h * 2));
    }
    if(Surf_QuitButton) {
        CSurface::OnDraw(Surf_Transition, Surf_QuitButton, (WWIDTH / 2) - (Surf_QuitButton->w / 2), (WHEIGHT / 2) - (Surf_QuitButton->h));
    }
    if(Surf_OptionsButton) {
        CSurface::OnDraw(Surf_Transition, Surf_OptionsButton, (WWIDTH / 2) - (Surf_OptionsButton->w / 2), (WHEIGHT / 2));
    }
    if(Surf_MenuButton) {
        CSurface::OnDraw(Surf_Transition, Surf_MenuButton, (WWIDTH / 2) - (Surf_MenuButton->w / 2), (WHEIGHT / 2) + (Surf_MenuButton->h));
    }
    if(Surf_Transition) {
        CSurface::OnDraw(Surf_Display, Surf_Transition, 0, 0);
    }
}

CAppStateMenu* CAppStateMenu::GetInstance() {
    return &Instance;
}

void CAppStateMenu::OnLButtonDown(int mX, int mY) {
        if(LButtonDownCheck(mX,mY,Surf_ResumeButton, (WWIDTH / 2) - (Surf_ResumeButton->w / 2), (WHEIGHT / 2) - (Surf_ResumeButton->h * 2))) {
            CAppStateManager::SetActiveAppState(APPSTATE_GAME);
        }
        if(LButtonDownCheck(mX,mY,Surf_QuitButton, (WWIDTH / 2) - (Surf_QuitButton->w / 2), (WHEIGHT / 2) - (Surf_QuitButton->h))) {
            SDL_Quit();
        }
        if(LButtonDownCheck(mX,mY,Surf_OptionsButton, (WWIDTH / 2) - (Surf_OptionsButton->w / 2), (WHEIGHT / 2))) {
        }
        if(LButtonDownCheck(mX,mY,Surf_MenuButton, (WWIDTH / 2) - (Surf_MenuButton->w / 2), (WHEIGHT / 2) + (Surf_MenuButton->h))) {
            CAppStateManager::SetActiveAppState(APPSTATE_MAINMENU);
        }
}

bool CAppStateMenu::LButtonDownCheck(int mX, int mY, SDL_Surface* Surf_Button,int x, int y) {
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

void CAppStateMenu::OnReceiveMessage(CAppStateMessage* Message) {
}
