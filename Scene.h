#pragma once
#include "Camera.h"
#include "Object.h"
#include <iostream>
#include <list>
#include <stdlib.h>

class Scene{
private:

    float angle = 90;

    void clearScreen(){
        system("cls");
    }
    
public:
    Camera* camera;
    std::list<Object*> objects;

    Scene(Camera* camera){
        this->camera = camera;
    }

    void addObject(Object* object){
        objects.push_back(object);
    }

    void RenderScene(){
        
        std::string shot = "";
        
        for (int i = 0; i < camera->resolution.y; i++){
            for (int j = 0; j < camera->resolution.x; j++){


                shot.append("@");
            }
            shot.append("\n");
        }

        clearScreen();
        std::cout << shot;
    }

};