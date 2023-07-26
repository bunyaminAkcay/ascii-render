#pragma once
#include "Vector3f.h"
#include "Vector2f.h"
#include "string"

class Camera{
public:
    Vector3f position;
    Vector3f direction;
    Vector2f resolution;
    
    Camera(Vector2f resolution, Vector3f position, Vector3f direction){
        this->position = position;
        this->direction = direction;
        this->resolution = resolution;
    }
};