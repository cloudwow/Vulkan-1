#pragma once

#include <array>

struct BlockNode {
    enum CHILD_POSITION {
        TOP_NORTH_WEST = 0,
        TOP_NORTH_EAST = 1,
        TOP_SOUTH_EAST = 2,
        TOP_SOUTH_WEST = 3,
        BOTTOM_NORTH_WEST = 4,
        BOTTOM_NORTH_EAST = 5,
        BOTTOM_SOUTH_EAST = 6,
        BOTTOM_SOUTH_WEST = 7
    };

    BlockNode(BlockNode
              *a_parent) :
        parent(a_parent) {}

    void setChild(BlockNode *a_child, CHILD_POSITION position) {
      children[position] = a_child;
    }

    BlockNode *parent;
    std::array<BlockNode *, 8> children;
};


