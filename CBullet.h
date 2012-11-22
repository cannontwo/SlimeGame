#ifndef _CBULLET_H_
    #define _CBULLET_H_

#include "CEntity.h"
#include "CVector.h"

class CBullet : public CEntity {
    public:
        CBullet();

        CBullet(CVector position, CVector speed, CVector acceleration, CVector direction);

        bool OnLoad(char* File, int Width, int Height, int MaxFrames);

        void OnLoop();

        void OnRender(SDL_Surface* Surf_Display);

        void OnCleanup();

        void OnAnimate();

        bool OnCollision(CEntity* Entity);

        CVector Direction;
        CVector Position;

        int StartTime;
};

#endif

