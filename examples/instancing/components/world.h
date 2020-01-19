#pragma once

#include <array>
#include <map>
#include "column.h"
#include "position.h"
#include "../geocoordinate.h"
#include "entityx/entityx.h"
#include <glm/glm/vec3.hpp>

struct World {
    struct EntityAndCoord {
        entityx::Entity entity;
        GeoCoordinate geo_coordinate;

        EntityAndCoord(entityx::Entity a_entity, GeoCoordinate a_geo_coordinate) :
            entity(a_entity), geo_coordinate(a_geo_coordinate) {

        }

        bool operator<(const EntityAndCoord &other) {
          return geo_coordinate < other.geo_coordinate;
        }

        bool operator==(const EntityAndCoord &other) {
          return geo_coordinate == other.geo_coordinate;
        }
    };

    glm::vec3 column_calculation_position;
    // columns are not added remove very often so std map is ok
    std::map<GeoCoordinate, EntityAndCoord> columns;
};

