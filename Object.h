#include <list>
#include "Vector2f.h"
#include "Surface.h"

class Object{
public:
    std::list<Surface> surfaces;

    Object(std::list<Surface> surfaces){
        this->surfaces = surfaces;
    }
};