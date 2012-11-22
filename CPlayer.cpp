#include "CPlayer.h"

CPlayer::CPlayer() {
    Health = 100;
    Type = ENTITY_TYPE_PLAYER;
    HitTimes = 0;
}

bool CPlayer::OnLoad(char* File, int Width, int Height, int MaxFrames) {
    if(CEntity::OnLoad(File, Width, Height, MaxFrames) == false) {
        return false;
    }
    return true;
}

void CPlayer::OnLoop() {
    CEntity::OnLoop();
}

void CPlayer::OnRender(SDL_Surface* Surf_Display) {
    CEntity::OnRender(Surf_Display);
}

void CPlayer::OnCleanup() {
    CEntity::OnCleanup();
}

void CPlayer::OnAnimate() {
    if(SpeedX != 0) {
        Anim_Control.MaxFrames = 0;
    }else{
        Anim_Control.MaxFrames = 0;
    }

    CEntity::OnAnimate();
}

bool CPlayer::OnCollision(CEntity* Entity) {
    if(Entity->Type == ENTITY_TYPE_PROJECTILE_ENEMY) {
        Health -= Entity->Attack;
        HitTimes++;
    }
}

void CPlayer::Shoot(int mX, int mY) {
    CVector position (X + (Width / 2), Y + (Height / 2));
    CVector direction (mX+CCamera::CameraControl.GetX(), mY+CCamera::CameraControl.GetY());
    CVector speed (0,0);
    CVector acceleration (0,0);

    Bullet = new CBullet(position,speed,acceleration,direction);
    Bullet->Type = ENTITY_TYPE_PROJECTILE_PLAYER;

    EntityList.push_back(Bullet);
}
