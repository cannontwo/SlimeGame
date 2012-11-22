#ifndef _CENEMY_H_
    #define _CENEMY_H_


#include <vector>

#include "CEntity.h"
#include "CBullet.h"

#include "CPlayer.h"

class CEnemy : public CEntity {

    public:
        CEnemy();

        bool OnLoad(char* File, int Width, int Height, int MaxFrames);

        void OnLoop();

        void OnRender(SDL_Surface* Surf_Display);

        void OnCleanup();

        void OnAnimate();

        bool OnCollision(CEntity* Entity);

        void Shoot(int x, int y);

        void SetPlayer(CPlayer tPlayer);

    private:
        CBullet* Bullet;

        CPlayer* Target;

        int StartTime;
};

#endif
