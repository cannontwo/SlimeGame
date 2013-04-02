#ifndef __CAPPSTATEEND_H__
    #define __CAPPSTATEEND_H__

#include <vector>
#include "CAppState.h"

#include "CArea.h"
#include "CCamera.h"
#include "CEntity.h"
#include "CSurface.h"

#include "CAppStateManager.h"


class CAppStateEnd : public CAppState {
    static std::vector<CAppStateMessage*> MessageList;

    private:
        static CAppStateEnd Instance;

        bool Win;

        SDL_Surface* Surf_End;

        SDL_Surface* Surf_Back;

        SDL_Surface* Surf_QuitButton;

        SDL_Surface* Surf_RestartButton;

        SDL_Surface* Surf_Message;

        SDL_Surface* Surf_MenuButton;

    private:
        CAppStateEnd();

        bool LButtonDownCheck(int mX, int mY, SDL_Surface* Surf_Button, int x, int y);

    public:
        void OnActivate();

        void OnDeactivate();

        void OnLoop();

        void OnRender(SDL_Surface* Surf_Display);

    public:
        static CAppStateEnd* GetInstance();

        void OnLButtonDown(int mX, int mY);

        void OnReceiveMessage(CAppStateMessage* Message);
};

#endif
