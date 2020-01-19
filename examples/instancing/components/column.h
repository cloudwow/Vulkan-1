#pragma once

#include <array>
#include "blocknode.h"
#include "../geocoordinate.h"

struct Column {

    Column(const GeoCoordinate &coordinate)
        : geo_coordinate(coordinate) {
    }

    std::array<BlockNode *, 64> blockNodes;
    GeoCoordinate geo_coordinate;
};

