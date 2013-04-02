#include "CAppStateGame.h"

#include "CAppStateMessage.h"


CAppStateGame CAppStateGame::Instance;

std::vector<CAppStateMessage*>     CAppStateManager::MessageList;

CAppStateGame::CAppStateGame() {
    FirstTime = true;
}

void CAppStateGame::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
    switch(sym) {
        case SDLK_LEFT: {
            Player.MoveRight = false;
            Player.MoveLeft = true;
            break;
        }

        case SDLK_RIGHT: {
            Player.MoveLeft = false;
            Player.MoveRight = true;
            break;
        }

        case SDLK_SPACE: {
            Player.Jump();
            break;
        }

        case SDLK_UP: {
            Player.Jump();
            break;
        }

        case SDLK_ESCAPE: {
            CAppStateManager::SetActiveAppState(APPSTATE_MENU);
            break;
        }

        case SDLK_a: {
            Player.MoveRight = false;
            Player.MoveLeft = true;
            break;
        }

        case SDLK_d: {
            Player.MoveLeft = false;
            Player.MoveRight = true;
            break;
        }

        case SDLK_w: {
            Player.Jump();
            break;
        }

        default: {
        }
    }
}

void CAppStateGame::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
    switch(sym) {
        case SDLK_LEFT: {
            Player.MoveLeft = false;
            break;
        }

        case SDLK_RIGHT: {
            Player.MoveRight = false;
            break;
        }

        case SDLK_a: {
            Player.MoveLeft = false;
            break;
        }

        case SDLK_d: {
            Player.MoveRight = false;
            break;
        }

        default: {
        }
    }
}

void CAppStateGame::OnLButtonDown(int mX, int mY) {
    Player.Shoot(mX, mY);
}

void CAppStateGame::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle) {
}

void CAppStateGame::OnActivate() {
    if(CArea::AreaControl.OnLoad("./maps/1.area") == false) {
        return;
    }

    if(Player.OnLoad("./images/player.png", 64, 64, 1) == false) {
        return;
    }

    if(Archer.OnLoad("./images/archer.png",64,64,1) == false) {
        return;
    }

    if (FirstTime) {
        Player.Y = (MAP_HEIGHT - 10) * TILE_SIZE;
        FirstTime = false;
        Player.X = rand() % 1184 + 32;
        Archer.X = rand() % 1184 + 32;
    }

    if(Archer.Dead || Player.Dead) {
        FirstTime = true;
        Archer.Dead = false;
        Player.Dead = false;
        Archer.Health = 100;
        Player.Health = 100;
        Player.MoveLeft = Player.MoveRight = false;
    }
    if (FirstTime) {
        Player.X = rand() % 1216 + 32;
        Archer.X = rand() % 1216 + 32;
    }

    Archer.SetPlayer(Player);


    CEntity::EntityList.push_back(&Archer);
    CEntity::EntityList.push_back(&Player);

    CCamera::CameraControl.TargetMode = TARGET_MODE_CENTER;
    CCamera::CameraControl.SetTarget(&Player.X, &Player.Y);
}

void CAppStateGame::OnDeactivate() {
    CArea::AreaControl.OnCleanup();

    for(int i = 0;i < CEntity::EntityList.size();i++) {
        if(!CEntity::EntityList[i]) continue;

        CEntity::EntityList[i]->OnCleanup();
    }

    CEntity::EntityList.clear();
}

void CAppStateGame::OnLoop() {
    for(int i = 0;i < CEntity::EntityList.size();i++) {
        if(!CEntity::EntityList[i]) continue;

        CEntity::EntityList[i]->OnLoop();

        if (CEntity::EntityList[i]->Type == ENTITY_TYPE_ENEMY) {
            if(!Player.Dead) {
                CEntity::EntityList[i]->Shoot(Player.X + (Player.Width / 2),Player.Y + (Player.Height / 2));
            }
        }
    }

    //Collision Events
    for(int i = 0;i < CEntityCol::EntityColList.size();i++) {
        CEntity* EntityA = CEntityCol::EntityColList[i].EntityA;
        CEntity* EntityB = CEntityCol::EntityColList[i].EntityB;

        if(EntityA == NULL || EntityB == NULL) continue;

        if(EntityA->Dead == true || EntityB->Dead == true) continue;

        if(EntityA->OnCollision(EntityB)) {
            EntityB->OnCollision(EntityA);
        }
    }

    CEntityCol::EntityColList.clear();

    if (Player.Dead) {
        WinMessage.boolMessage = false;
        CAppStateManager::SendMessage(APPSTATE_END, &WinMessage);
        CAppStateManager::SetActiveAppState(APPSTATE_END);
    }
 //   if (Archer.Dead) {
 //      WinMessage.boolMessage = true;
 //       CAppStateManager::SendMessage(APPSTATE_END,&WinMessage);
 //       CAppStateManager::SetActiveAppState(APPSTATE_END);
 //   }
    if(Player.Money > 0) {
        WinMessage.boolMessage = true;
        CAppStateManager::SendMessage(APPSTATE_END,&WinMessage);
        CAppStateManager::SetActiveAppState(APPSTATE_END);
    }
        for(std::vector<CEntity*>::iterator it = CEntity::EntityList.begin(); it != CEntity::EntityList.end();) {
        if(!(*it)) continue;
        if((*it)->Dead == true) {
                (*it)->OnCleanup();
                delete (*it);
                it = CEntity::EntityList.erase(it);
        }
        else {
                it++;
        }
    }

    char Buffer[255];
    sprintf(Buffer,"Player Health: %d  |||  Enemy Health: %d ||| Money: %d", Player.Health, Archer.Health, Player.Money);
    SDL_WM_SetCaption(Buffer,Buffer);
}

void CAppStateGame::OnRender(SDL_Surface* Surf_Display) {
    SDL_Rect Rect;
    Rect.x = 0;
    Rect.y = 0;
    Rect.w = WWIDTH;
    Rect.h = WHEIGHT;

    SDL_FillRect(Surf_Display, &Rect, 0);

    CArea::AreaControl.OnRender(Surf_Display, -CCamera::CameraControl.GetX(), -CCamera::CameraControl.GetY());

    for(int i = 0;i < CEntity::EntityList.size();i++) {
        if(!CEntity::EntityList[i]) continue;

        CEntity::EntityList[i]->OnRender(Surf_Display);
    }
}

CAppStateGame* CAppStateGame::GetInstance() {
    return &Instance;
}

CPlayer CAppStateGame::GetPlayer() {
    return Player;
}

void CAppStateGame::OnReceiveMessage(CAppStateMessage* Message) {
}
