#pragma once
#include "Vector3f.h"


class Surface{
private:

    Vector3f normal;

public:

    Vector3f p1, p2, p3;
    

    Surface(Vector3f p1, Vector3f p2, Vector3f p3){
        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
        this->normal = (p1 - p2) * (p1-p3);
    }

    Vector3f getNormal(){
        return normal;
    }

};