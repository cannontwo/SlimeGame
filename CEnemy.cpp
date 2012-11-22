#include "CEnemy.h"

CEnemy::CEnemy() {
    Health = 40;
    Attack = 10;
    Type = ENTITY_TYPE_ENEMY;
    StartTime = 0;
}

bool CEnemy::OnLoad(char* File, int Width, int Height, int MaxFrames) {
    if(CEntity::OnLoad(File, Width, Height, MaxFrames) == false) {
        return false;
    }
    return true;
}

void CEnemy::OnLoop() {
    CEntity::OnLoop();
}

void CEnemy::OnRender(SDL_Surface* Surf_Display) {
    CEntity::OnRender(Surf_Display);
}

void CEnemy::OnCleanup() {
    CEntity::OnCleanup();
}

void CEnemy::OnAnimate() {
    CEntity::OnAnimate();
}

bool CEnemy::OnCollision(CEntity* Entity) {
    if(Entity->Type == ENTITY_TYPE_PROJECTILE_PLAYER) {
        Health -= Entity->Attack;
    }
    return true;
}

void CEnemy::Shoot(int targetX, int targetY) {
    CVector position (X + (Width / 2), Y + (Height / 2));
    CVector direction (targetX, targetY);
    CVector speed (0,0);
    CVector acceleration (0,0);

    if(StartTime + 1000 < SDL_GetTicks()) {
        Bullet = new CBullet(position,speed,acceleration,direction);
        Bullet->Type = ENTITY_TYPE_PROJECTILE_ENEMY;

        EntityList.push_back(Bullet);
        StartTime = SDL_GetTicks();
    }
    return;

}

void CEnemy::SetPlayer(CPlayer tPlayer) {
    Target = &tPlayer;
}
