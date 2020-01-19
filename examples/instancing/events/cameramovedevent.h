#pragma once
#include "../components/camera.h"
struct CameraMovedEvent {
    CameraMovedEvent():camera(nullptr){}
    CameraMovedEvent(Camera* a_camera):camera(a_camera){}
    Camera* camera;
};

