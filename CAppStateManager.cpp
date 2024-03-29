#include "CAppStateManager.h"

// Refer to your Other App States Here
#include "CAppStateMenu.h"
#include "CAppStateIntro.h"
#include "CAppStateGame.h"
#include "CAppStateEnd.h"
#include "CAppStateMainMenu.h"


CAppState* CAppStateManager::ActiveAppState = 0;

void CAppStateManager::OnEvent(SDL_Event* EventHolder) {
    if(ActiveAppState) ActiveAppState->OnEvent(EventHolder);
}

void CAppStateManager::OnLoop() {
    if(ActiveAppState) ActiveAppState->OnLoop();
}

void CAppStateManager::OnRender(SDL_Surface* Surf_Display) {
    if(ActiveAppState) ActiveAppState->OnRender(Surf_Display);
}

void CAppStateManager::SetActiveAppState(int AppStateID) {
    if(ActiveAppState) ActiveAppState->OnDeactivate();

    // Also, add your App State Here so that the Manager can switch to it
    if(AppStateID == APPSTATE_NONE)        ActiveAppState = 0;
    if(AppStateID == APPSTATE_INTRO)       ActiveAppState = CAppStateIntro::GetInstance();
    if(AppStateID == APPSTATE_GAME)        ActiveAppState = CAppStateGame::GetInstance();
    if(AppStateID == APPSTATE_MENU)        ActiveAppState = CAppStateMenu::GetInstance();
    if(AppStateID == APPSTATE_END)         ActiveAppState = CAppStateEnd::GetInstance();
    if(AppStateID == APPSTATE_MAINMENU)    ActiveAppState = CAppStateMainMenu::GetInstance();

    for(int i = 0; i < MessageList.size(); i++) {
        if(AppStateID == MessageList[i]->GetType()) {
            ActiveAppState->OnReceiveMessage(MessageList[i]);
        }
    }

    if(ActiveAppState) ActiveAppState->OnActivate();
}

CAppState* CAppStateManager::GetActiveAppState() {
    return ActiveAppState;
}

void CAppStateManager::SendMessage(int AppStateID, CAppStateMessage* Message) {
    Message->SetType(AppStateID);
    MessageList.push_back(Message);
}
