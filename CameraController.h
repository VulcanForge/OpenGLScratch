#pragma once

#include "Camera.h"

struct CameraController
{
    Camera camera;

    float xSpeed, ySpeed, zSpeed;
    float yawSpeed, pitchSpeed;
    float fullSpeed;
    float fullRotationSpeed;

    CameraController (Camera camera, float fullSpeed, float fullRotationSpeed);

    void UpdateCamera (float dt);
    void OnKeyPress (int key);
    void OnKeyRelease (int key);
};
