#include <iostream>
#include <list>
#include "Scene.h"
#include "Camera.h"
#include "Surface.h"
#include "Vector2f.h"
#include "Vector3f.h"

int main(){

    Camera camera = Camera(Vector2f(120, 60), Vector3f(1, 0, 1), Vector3f(-1, 0, -1));
    Surface surface1 = Surface(Vector3f(0, -0.5, 0), Vector3f(0, 0.5, 0), Vector3f(0, 0, 0.5));
    
    std::list<Surface> sl;
    sl.push_back(surface1);
    
    Object object1 = Object(sl);
    
    Scene scene = Scene(&camera);
    scene.addObject(&object1);
    scene.RenderScene();

    return 0;
}