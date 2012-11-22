#ifndef __CAPPSTATEEND_H__
    #define __CAPPSTATEEND_H__

#include "CAppState.h"

#include "CArea.h"
#include "CCamera.h"
#include "CEntity.h"
#include "CSurface.h"

#include "CAppStateManager.h"


class CAppStateEnd : public CAppState {
    private:
        static CAppStateEnd Instance;

        bool Win;

        SDL_Surface* Surf_End;

    private:
        CAppStateEnd();

    public:
        void OnActivate();

        void OnDeactivate();

        void OnLoop();

        void OnRender(SDL_Surface* Surf_Display);

    public:
        static CAppStateEnd* GetInstance();

        void OnLButtonDown(int mX, int mY);
};

#endif
