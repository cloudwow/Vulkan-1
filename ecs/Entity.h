#pragma once

class Entity {
public:
    Entity(long id) : _id(id) {}

    long getId() {
      return _id;
    }

private:
    long _id;
};
