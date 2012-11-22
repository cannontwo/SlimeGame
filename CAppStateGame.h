#ifndef __CAPPSTATEGAME_H__
    #define __CAPPSTATEGAME_H__

#include "CAppState.h"

#include "CArea.h"
#include "CCamera.h"
#include "CEntity.h"
#include "CSurface.h"

#include "CAppStateManager.h"
#include "CAppStateEnd.h"
#include "CPlayer.h"
#include "CEnemy.h"

#include "CAppStateMessage.h"

class CAppStateGame : public CAppState {
    private:
        static CAppStateGame Instance;

        CPlayer    Player;

        CEnemy     Archer;

        bool FirstTime;

    private:
        CAppStateGame();

    public:
        void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);

        void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);

        void OnLButtonDown(int mX, int mY);

       void OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle);

    public:
        void OnActivate();

        void OnDeactivate();

        void OnLoop();

        void OnRender(SDL_Surface* Surf_Display);

        CPlayer GetPlayer();

    public:
        static CAppStateGame* GetInstance();
};

#endif
