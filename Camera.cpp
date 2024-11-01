#include "Camera.h"

#include <numbers>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>

constexpr glm::vec3 right (1, 0, 0);
constexpr glm::vec3 up (0, 1, 0);

void Camera::UpdateView ()
{
    glm::vec3 position (x, y, z);
    positionMatrix = glm::translate (-position);
    glm::mat4 yawMatrix = glm::rotate (-yaw, up);
    glm::mat4 pitchMatrix = glm::rotate (-pitch, right);
    orientationMatrix = pitchMatrix * yawMatrix;
    viewMatrix = orientationMatrix * positionMatrix;
}

void Camera::TranslateRelative (glm::vec3 dPosition)
{
    return TranslateRelative (dPosition.x, dPosition.y, dPosition.z);
}

void Camera::TranslateRelative (float dx, float dy, float dz)
{
    x += (cosYaw * dx + sinYaw * (sinPitch * dy + cosPitch * dz));
    y += (cosPitch * dy - sinPitch * dz);
    z += (-sinYaw * dx + cosYaw * (sinPitch * dy + cosPitch * dz));

    UpdateView ();
}

constexpr float PI = std::numbers::pi_v<float>;

void Camera::Rotate (float dYaw, float dPitch)
{
    yaw = fmod (yaw + dYaw + PI, 2 * PI) - PI;
    pitch += dPitch;

    if (pitch < -PI / 2)
        pitch = -PI / 2;
    else if (pitch > PI / 2)
        pitch = PI / 2;

    cosYaw = cos (yaw);
    sinYaw = sin (yaw);
    cosPitch = cos (pitch);
    sinPitch = sin (pitch);
    UpdateView ();
}

Camera::Camera ()
    : Camera (0, 0, 0, 0, 0)
{}

Camera::Camera (float x, float y, float z, float yaw, float pitch)
    : x (x), y (y), z (z), yaw (yaw), pitch (pitch)
{
    cosYaw = cos (yaw);
    sinYaw = sin (yaw);
    cosPitch = cos (pitch);
    sinPitch = sin (pitch);
    UpdateView ();
}
