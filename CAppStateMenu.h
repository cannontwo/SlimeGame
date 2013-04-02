#ifndef __CAPPSTATEMENU_H__
    #define __CAPPSTATEMENU_H__

#include "CAppState.h"
#include "CSurface.h"

#include "CAppStateMessage.h"

class CAppStateMenu : public CAppState {
    private:
        static CAppStateMenu Instance;

        SDL_Surface* Surf_QuitButton;

        SDL_Surface* Surf_ResumeButton;

        SDL_Surface* Surf_OptionsButton;

        SDL_Surface* Surf_MenuButton;

        SDL_Surface* Surf_Transition;

    private:
        CAppStateMenu();

        bool LButtonDownCheck(int mX, int mY, SDL_Surface* Surf_Button, int x, int y);

    public:
        void OnLButtonDown(int mX, int mY);

        void OnActivate();

        void OnDeactivate();

        void OnLoop();

        void OnRender(SDL_Surface* Surf_Display);

        void OnReceiveMessage(CAppStateMessage* Message);

    public:
        static CAppStateMenu* GetInstance();
};

#endif

