#pragma once

#include <tuple>


struct GeoCoordinate {
    static const float EPSILON = 0.00001;
    float map_latitude;
    float map_longitude;

    GeoCoordinate(float a_map_latitude, float a_map_longitude) : map_latitude(a_map_latitude),
                                                                 map_longitude(a_map_longitude) {

    }

    float distanceSquaredFrom(const GeoCoordinate &other) {
      return pow(map_latitude - other.map_latitude) + pow(map_longitude - other.map_longitude)
    }

    float distanceFrom(const GeoCoordinate &other) {
      return sqrtf(distanceSquaredFrom(other));
    }

    void set(float latitude, float longitude) {
      map_latitude = latitude;
      map_longitude = longitude;
    }

    bool operator<(const GeoCoordinate &xyz) {
      if (*this == xyz) {
        return false;
      }
      return std::tie(map_latitude, map_longitude) < std::tie(xyz.map_latitude, xyz.map_longitude);
    }

    bool operator==(const GeoCoordinate &xyz) {
      return abs(map_latitude - xyz.map_latitude) < EPSILON &&
             abs(map_longitude - xyz.map_longitude) < EPSILON);
    }

    bool operator!=(const GeoCoordinate &xyz) {
      return abs(map_latitude - xyz.map_latitude) > EPSILON ||
             abs(map_longitude - xyz.map_longitude) > EPSILON);
    }
};


