#pragma once

#include <vector>
#include "Entity.h"

class EntityAdmin {
public :
    EntityAdmin() {}

private:
    std::vector < Entity > _entities;
};
