#pragma once

#include <glm/mat4x4.hpp>

struct Camera
{
    float x, y, z;
    float yaw, pitch;
    float cosYaw, sinYaw, cosPitch, sinPitch;

    glm::mat4 positionMatrix;
    glm::mat4 orientationMatrix;
    glm::mat4 viewMatrix;

    Camera ();
    Camera (float x, float y, float z, float yaw, float pitch);

    void UpdateView ();
    void TranslateRelative (glm::vec3 dPosition);
    void TranslateRelative (float dx, float dy, float dz);
    void Rotate (float dYaw, float dPitch);
};
