#ifndef _CVECTOR_H_
    #define _CVECTOR_H_

class CVector {
    public:
        float X;
        float Y;

        CVector();

        CVector(int x, int y);

        CVector(float xf, float yf);

        CVector operator = (int coords[2]);

};

#endif
