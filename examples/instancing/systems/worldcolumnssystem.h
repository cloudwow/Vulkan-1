#pragma once

#include "entityx/entityx.h"
#include "../components/column.h"
#include "../events/cameramovedevent.h"

using namespace entityx;
class WorldColumnSystem : public entityx::System<WorldColumnSystem>{
public:
    WorldColumnSystem();
    void configure(entityx::EventManager &event_manager) override;
    void update(entityx::EntityManager &es, entityx::EventManager &events, TimeDelta dt) override;
    void receive(const CameraMovedEvent &event);

private:
    bool _cameraNeedsProcessing = false;
    CameraMovedEvent _unprocessedCameraEvent;
    GeoCoordinate lastProcessedCenterCoordinate;

};


