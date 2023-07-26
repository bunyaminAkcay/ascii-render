#pragma once
#include <string>

class Vector3f{
public:
    float x,y,z;
    Vector3f(){
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }

    Vector3f(float x, float y, float z){
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vector3f operator+(const Vector3f anotherVector){
        Vector3f sumOfVec = Vector3f(this->x + anotherVector.x, this->y + anotherVector.y, this->z + anotherVector.z);
        return sumOfVec;
    }

    Vector3f operator-(const Vector3f anotherVector){
        Vector3f diffOfVec = Vector3f(this->x - anotherVector.x, this->y - anotherVector.y, this->z - anotherVector.z);
        return diffOfVec;
    }

    Vector3f operator-(){
        Vector3f minusVec = Vector3f(-this->x, -this->y, -this->z);
        return minusVec;
    }

    Vector3f operator*(Vector3f anotherVector){
        return Vector3f(( this->y * anotherVector.z - this->z * anotherVector.y), ( this->z * anotherVector.x - this->x * anotherVector.z ), ( this->x * anotherVector.y - this->y * anotherVector.x));
    }

    Vector3f operator*(float scaler){
        return Vector3f(this->x * scaler, this->y * scaler, this->z * scaler);
    }
    Vector3f operator*(int scaler){
        return Vector3f(this->x * (float) scaler, this->y * (float) scaler, this->z * (float) scaler);
    }

    std::string toString(){
        std::string str = "Vector3f("+std::to_string(this->x)+ "," +std::to_string(this->y)+","+ std::to_string(this->z)+")";
        return str;
    }

};