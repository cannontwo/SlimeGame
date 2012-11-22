#include "CCamera.h"

CCamera CCamera::CameraControl;

CCamera::CCamera() {
    X = Y = 0;

    TargetX = TargetY = NULL;

    TargetMode = TARGET_MODE_NORMAL;
}

void CCamera::OnMove(int MoveX, int MoveY) {
    X += MoveX;
    Y += MoveY;
}

int CCamera::GetX() {
    if(*TargetX - (WWIDTH / 2) > 0) {
        if(*TargetX + (WWIDTH / 2) < MAP_WIDTH * TILE_SIZE) {
            if(TargetX != NULL) {
                if(TargetMode == TARGET_MODE_CENTER) {
                    return *TargetX - (WWIDTH / 2);
                }

                return *TargetX;
            }
            return X;
        }
        return 0;
    }
    return 0;
}

int CCamera::GetY() {
    if (*TargetY - (WHEIGHT / 2) < 180) {
        if(TargetY != NULL) {
            if(TargetMode == TARGET_MODE_CENTER) {
                return *TargetY - (WHEIGHT / 2);
            }

            return *TargetY;
        }
        return Y;
    }
    return 180;
}

void CCamera::SetPos(int X, int Y) {
    this->X = X;
    this->Y = Y;
}

void CCamera::SetTarget(float* X, float* Y) {
    TargetX = X;
    TargetY = Y;
}
