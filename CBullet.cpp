#include "CBullet.h"

#include <cmath>

CBullet::CBullet() {

    AccelX = 0;
    AccelY = 0;

    SpeedX = 0;
    SpeedY = 0;

    MaxSpeedX = 0;
    MaxSpeedY = 0;

    int empty[2] = {0,0};

    Position = empty;
    Direction = empty;
}

CBullet::CBullet(CVector position, CVector speed, CVector acceleration, CVector direction) {
    OnLoad(("./images/bullet.png"),16,16,0);

    Attack = 10;

   X = position.X;
   Y = position.Y;

   AccelX = acceleration.X;
   AccelY = acceleration.Y;

   SpeedX = speed.X;
   SpeedY = speed.Y;

   Direction = direction;

   Flags = ENTITY_FLAG_GHOST;

   float radians = atan2(Direction.X - X, Direction.Y - Y);

   SpeedX = sin(radians) * 20;
   SpeedY = cos(radians) * 20;

   StartTime = SDL_GetTicks();
}

bool CBullet::OnLoad(char* File, int Width, int Height, int MaxFrames) {
    if(CEntity::OnLoad(File, Width, Height, MaxFrames) == false) {
        return false;
    }

    return true;
}

void CBullet::OnLoop(){
    if(StartTime + 1000 < SDL_GetTicks()) {
        Dead = true;
    }

   if(X > MAP_WIDTH * TILE_SIZE || X < 0){
      Dead = true;
   }

   CEntity::OnLoop();

}

void CBullet::OnRender(SDL_Surface* Surf_Display) {
    CEntity::OnRender(Surf_Display);
}

void CBullet::OnCleanup() {
    Dead = true;
}

void CBullet::OnAnimate() {
    if(SpeedX != 0) {
        Anim_Control.MaxFrames = 0;
    }else{
        Anim_Control.MaxFrames = 0;
    }

    CEntity::OnAnimate();
}

bool CBullet::OnCollision(CEntity* Entity) {
    if (Type == ENTITY_TYPE_PROJECTILE_PLAYER && Entity->Type == ENTITY_TYPE_ENEMY) {
        OnCleanup();
    } else if(Type == ENTITY_TYPE_PROJECTILE_ENEMY && Entity->Type == ENTITY_TYPE_PLAYER) {
        OnCleanup();
    }
    return true;
}

