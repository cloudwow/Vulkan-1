#pragma once

struct Position {
    Position(float x = 0.0f, float y = 0.0f, float z = 0.0f) : position_vec3(x,y,z) {}
    Position(const glm::vec3& a_position_vec3) : position_vec3(a_position_vec3) {}

    glm::vec3 position_vec3;
};
