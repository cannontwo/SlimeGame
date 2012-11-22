#ifndef __CAPPSTATEMANAGER_H__
    #define __CAPPSTATEMANAGER_H__

#include "CAppState.h"
#include <vector>
#include "CAppStateMessage.h"

enum {
    // Add your Other App States Here
    APPSTATE_MENU,
    APPSTATE_NONE,
    APPSTATE_INTRO,
    APPSTATE_GAME,
    APPSTATE_END

};

class CAppStateManager {
    public:
        static std::vector<CAppStateMessage*>    MessageList;

    private:
        static CAppState* ActiveAppState;


    public:
        static void OnEvent(SDL_Event* Event);

        static void OnLoop();

        static void OnRender(SDL_Surface* Surf_Display);

    public:
        static void SetActiveAppState(int AppStateID);

        static CAppState* GetActiveAppState();

        static void SendMessage(int AppStateID, CAppStateMessage Message);
};

#endif
