#include "worldcolumnssystem.h"
#include <glm/geometric.hpp>
#include <glm/vector_relational.hpp>
#include "../components/world.h"
#include "../components/column.h"
#include "../components/camera.h"
#include "../events/cameramovedevent.h"

WorldColumnSystem::WorldColumnSystem() : lastProcessedCenterCoordinate(INT32_MIN, INT32_MIN) {
}

void WorldColumnSystem::configure(entityx::EventManager &event_manager) {
  event_manager.subscribe<CameraMovedEvent>(*this);
}

void
WorldColumnSystem::update(entityx::EntityManager &es, entityx::EventManager &events, TimeDelta dt) {
  if (_cameraNeedsProcessing) {
    ComponentHandle<World> world_position;
    ComponentHandle<Column> column_position;

    es.each<World>([dt, this, &es](Entity entity, World &world) {


        float derp = glm::distance(_unprocessedCameraEvent.camera->position,
                                   world.column_calculation_position);
        if (derp < 2.0) {
          return; // return from lambda
        }
        //  columns might need adding or removing
        int cam_latitude = _unprocessedCameraEvent.camera->position.y + 0.5;
        int cam_longitude = _unprocessedCameraEvent.camera->position.x + 0.5;
        int center_column_y = (cam_latitude % 64) * 64 + 32;
        int center_column_x = (cam_longitude % 64) * 64 + 32;
        GeoCoordinate newCenter(center_column_y, center_column_x);
        if (newCenter != lastProcessedCenterCoordinate) {
          for (std::pair<GeoCoordinate, World::EntityAndCoord> element : world.columns) {
            if (element.first.distanceSquaredFrom(newCenter) > 1024) {
              es.destroy(element.second.entity.id());
            }
          }
        }
        for (int x = -16; x < 16; x++) {
          for (int y = -16; y < 16; y++) {
            GeoCoordinate candidate(center_column_y + y * 64, center_column_x + x * 64);
            if (candidate.distanceSquaredFrom(newCenter) > 1024) {
              ComponentHandle<Column> targetColumn;
              if (world.columns.find( candidate ) == world.columns.end()) {
                targetColumn = es.component<Column>(world.columns[candidate].entity.id());
              } else {
                entityx::Entity columnEntity= es.create();
                targetColumn= columnEntity.assign<Column>(candidate);
                world.columns[candidate] = World::EntityAndCoord(columnEntity,candidate);
              }
              // something to do here?
            }
          }
        }
        if (newCenter != lastProcessedCenterCoordinate) {
          for (std::pair<GeoCoordinate, World::EntityAndCoord> element : world.columns) {
            if (element.first.distanceSquaredFrom(newCenter) > 1024) {
              es.remove((element.second.entity.id());
              ComponentHandle<Column> column = es.component<Column>(element.second.entity.id());
            }
          }
        }
    });
    _cameraNeedsProcessing = false;
  }

}

void WorldColumnSystem::receive(const CameraMovedEvent &event) {
  _unprocessedCameraEvent = event;
  _cameraNeedsProcessing = true;
}