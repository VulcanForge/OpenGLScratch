#include "CameraController.h"

#include <GL/glew.h>

#include <GLFW/glfw3.h>

CameraController::CameraController (Camera camera, float fullSpeed, float fullRotationSpeed)
    : camera (camera), xSpeed (0), ySpeed (0), zSpeed (0), yawSpeed (0), pitchSpeed (0),
    fullSpeed (fullSpeed), fullRotationSpeed (fullRotationSpeed)
{}

void CameraController::UpdateCamera (float dt)
{
    camera.Rotate (yawSpeed * dt, pitchSpeed * dt);
    camera.TranslateRelative (xSpeed * dt, ySpeed * dt, zSpeed * dt);
}

void CameraController::OnKeyPress (int key)
{
    switch (key)
    {
        case GLFW_KEY_W:
            zSpeed -= fullSpeed;
            break;
        case GLFW_KEY_S:
            zSpeed += fullSpeed;
            break;
        case GLFW_KEY_A:
            xSpeed -= fullSpeed;
            break;
        case GLFW_KEY_D:
            xSpeed += fullSpeed;
            break;
        case GLFW_KEY_SPACE:
            ySpeed += fullSpeed;
            break;
        case GLFW_KEY_LEFT_SHIFT:
            ySpeed -= fullSpeed;
            break;
        case GLFW_KEY_LEFT:
            yawSpeed += fullRotationSpeed;
            break;
        case GLFW_KEY_RIGHT:
            yawSpeed -= fullRotationSpeed;
            break;
        case GLFW_KEY_UP:
            pitchSpeed += fullRotationSpeed;
            break;
        case GLFW_KEY_DOWN:
            pitchSpeed -= fullRotationSpeed;
            break;
        case GLFW_KEY_F:
            glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
            break;
    }
}

void CameraController::OnKeyRelease (int key)
{
    switch (key)
    {
        case GLFW_KEY_W:
            zSpeed += fullSpeed;
            break;
        case GLFW_KEY_S:
            zSpeed -= fullSpeed;
            break;
        case GLFW_KEY_A:
            xSpeed += fullSpeed;
            break;
        case GLFW_KEY_D:
            xSpeed -= fullSpeed;
            break;
        case GLFW_KEY_SPACE:
            ySpeed -= fullSpeed;
            break;
        case GLFW_KEY_LEFT_SHIFT:
            ySpeed += fullSpeed;
            break;
        case GLFW_KEY_LEFT:
            yawSpeed -= fullRotationSpeed;
            break;
        case GLFW_KEY_RIGHT:
            yawSpeed += fullRotationSpeed;
            break;
        case GLFW_KEY_UP:
            pitchSpeed -= fullRotationSpeed;
            break;
        case GLFW_KEY_DOWN:
            pitchSpeed += fullRotationSpeed;
            break;
        case GLFW_KEY_F:
            glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
            break;
    }
}
