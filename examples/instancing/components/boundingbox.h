//
// Created by david on 1/18/20.
//

#pragma once

struct BoundingBox{
    float top;
    float bottom;
    float left;
    float right;

    boundingBox( float a_top, float a_bottom, float a_left, float a_right )
        : top( a_top ), bottom( a_bottom )
        , left( a_left ), right( a_right )
    {}
};