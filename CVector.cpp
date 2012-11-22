#include "CVector.h"

CVector::CVector() {
    X = 0;
    Y = 0;
}

CVector::CVector(int x, int y) {
    X = x;
    Y = y;
}


CVector::CVector(float xf, float yf) {
    X = xf;
    Y = yf;
}


CVector CVector::operator= (int coords[2]) {
    CVector temp;
    temp.X = coords[0];
    temp.Y = coords[1];
    return (temp);
}
