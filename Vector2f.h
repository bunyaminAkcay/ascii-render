#pragma once
#include <string>

class Vector2f{
public:
    float x,y;
    
    Vector2f(){
        this->x = 0;
        this->y = 0;
    }
    
    Vector2f(float x, float y){
        this->x = x;
        this->y = y;
    }

    Vector2f operator+(const Vector2f anotherVector){
        Vector2f sumOfVec = Vector2f(this->x + anotherVector.x, this->y + anotherVector.y);
        return sumOfVec;
    }

    Vector2f operator-(const Vector2f anotherVector){
        Vector2f diffOfVec = Vector2f(this->x - anotherVector.x, this->y - anotherVector.y);
        return diffOfVec;
    }

    Vector2f operator-(){
        Vector2f minusVec = Vector2f(-this->x, -this->y);
        return minusVec;
    }

    Vector2f operator*(float scaler){
        return Vector2f(this->x * scaler, this->y * scaler);
    }
    Vector2f operator*(int scaler){
        return Vector2f(this->x * (float) scaler, this->y * (float) scaler);
    }

    std::string toString(){
        std::string str = "Vector2f("+std::to_string(this->x)+ "," +std::to_string(this->y)+")";
        return str;
    }

};