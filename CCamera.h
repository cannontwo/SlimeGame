#ifndef _CCAMERA_H_
    #define _CCAMERA_H_

#include <SDL.h>

#include "Define.h"

enum {
    TARGET_MODE_NORMAL = 0,
    TARGET_MODE_CENTER
};

class CCamera {
    public:
        static CCamera CameraControl;

    private:
        float X;
        float Y;

        float* TargetX;
        float* TargetY;

    public:
        int TargetMode;

    public:
        CCamera();

    public:
        void OnMove(int MoveX, int MoveY);

    public:
        int GetX();
        int GetY();

    public:
        void SetPos(int X, int Y);

        void SetTarget(float* X, float* Y);
};

#endif
