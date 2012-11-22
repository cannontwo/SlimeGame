#ifndef _CPLAYER_H_
    #define _CPLAYER_H_

#include "CEntity.h"
#include "CBullet.h"

class CPlayer : public CEntity {
    public:
        CPlayer();

        bool OnLoad(char* File, int Width, int Height, int MaxFrames);

        void OnLoop();

        void OnRender(SDL_Surface* Surf_Display);

        void OnCleanup();

        void OnAnimate();

        bool OnCollision(CEntity* Entity);

        void Shoot(int mX, int mY);

    public:

        CBullet* Bullet;

        int HitTimes;

        CEntity* NewColEntity;
        CEntity* OldColEntity;
};

#endif
