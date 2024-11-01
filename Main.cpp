#include <numbers>

#include "gl/glew.h"

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>

#include <ShaderProgram/ShaderProgram.h>

#include "stb_image_write.h"

#include "CameraController.h"

#pragma region Constants

constexpr float SQRT2_INV = std::numbers::sqrt2_v<float> / 2.f;
constexpr float SQRT3_INV = std::numbers::sqrt3_v<float> / 3.f;
constexpr float PI = std::numbers::pi_v<float>;
constexpr float PHI = std::numbers::phi_v<float>;
constexpr float PHI_INV = PHI - 1.f;

glm::vec3 right {1, 0, 0};
glm::vec3 up {0, 1, 0};
glm::vec3 backwards {0, 0, 1};

#pragma region Colours
glm::vec3 red {1, 0, 0};
glm::vec3 green {0, 1, 0};
glm::vec3 blue {0, 0, 1};
glm::vec3 orange {1, .5f, 0};
glm::vec3 purple {1, 0, 1};
glm::vec3 yellow {1, 1, 0};

glm::vec3 white {1, 1, 1};
glm::vec3 grey {.5f, .5f, .5f};
#pragma endregion

#pragma endregion

struct Vertex
{
    glm::vec3 position;
    glm::vec3 colour;
};

#include "Tetrahedron.h"
#include "Cube.h"
#include "Octahedron.h"
#include "Dodecahedron.h"
#include "Icosahedron.h"
#include "Sphere.h"

CameraController controller (Camera (), 1, PI / 6);

void KeyCallback (GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS)
        controller.OnKeyPress (key);
    else if (action == GLFW_RELEASE)
        controller.OnKeyRelease (key);
}

int main ()
{
    glfwInit ();
    GLFWwindow* window = glfwCreateWindow (1024, 1024, "OpenGL", nullptr, nullptr);
    glfwMakeContextCurrent (window);
    glfwSetKeyCallback (window, KeyCallback);
    glewInit ();

#pragma region Axes

    int32_t xScale = 4;
    int32_t yScale = 4;
    int32_t zScale = 4;

    std::vector<Vertex> axes
    {
        {(float)(-xScale) * right, white}, {(float)(xScale) * right, white},
        {(float)(-yScale) * up, white}, {(float)(yScale) * up, white},
        {(float)(-zScale) * backwards, white}, {(float)(zScale) * backwards, white}
    };

    std::vector<Vertex> axisPoints {{{0, 0, 0}, white}};

    for (int32_t i = 1; i <= xScale; ++i)
    {
        axisPoints.emplace_back ((float)(-i) * right, red);
        axisPoints.emplace_back ((float)i * right, red);
    }
    for (int32_t i = 1; i <= yScale; ++i)
    {
        axisPoints.emplace_back ((float)(-i) * up, green);
        axisPoints.emplace_back ((float)i * up, green);
    }
    for (int32_t i = 1; i <= zScale; ++i)
    {
        axisPoints.emplace_back ((float)(-i) * backwards, blue);
        axisPoints.emplace_back ((float)i * backwards, blue);
    }

#pragma endregion

    std::vector<Vertex> points (axisPoints);
    std::vector<Vertex> lines (axes);
    std::vector<Vertex> triangles;
    std::vector<uint16_t> triangleIndices;
    Sphere sphere (90, blue);

    glm::mat4 tetrahedronTranslation = glm::translate (-2.f * right);
    glm::mat4 cubeTranslation = glm::translate (-1.f * right);
    glm::mat4 octahedronTranslation = glm::translate (glm::vec3 ());
    glm::mat4 dodecahedronTranslation = glm::translate (right);
    glm::mat4 icosahedronTranslation = glm::translate (2.f * right);

#pragma region GL setup

    GLuint tetrahedronVAO, tetrahedronVBO;
    GLuint cubeVAO, cubeVBO, cubeEBO;
    GLuint octahedronVAO, octahedronVBO;
    GLuint dodecahedronVAO, dodecahedronVBO, dodecahedronEBO;
    GLuint icosahedronVAO, icosahedronVBO;
    GLuint sphereVAO, sphereVBO, sphereEBO;

    GLuint pointVAO, pointVBO;
    GLuint lineVAO, lineVBO;
    GLuint triangleVAO, triangleVBO, triangleEBO;

    glGenVertexArrays (1, &tetrahedronVAO);
    glGenVertexArrays (1, &cubeVAO);
    glGenVertexArrays (1, &octahedronVAO);
    glGenVertexArrays (1, &dodecahedronVAO);
    glGenVertexArrays (1, &icosahedronVAO);
    glGenVertexArrays (1, &sphereVAO);

    glGenVertexArrays (1, &pointVAO);
    glGenVertexArrays (1, &lineVAO);
    glGenVertexArrays (1, &triangleVAO);

    glGenBuffers (1, &tetrahedronVBO);
    glGenBuffers (1, &cubeVBO);
    glGenBuffers (1, &cubeEBO);
    glGenBuffers (1, &octahedronVBO);
    glGenBuffers (1, &dodecahedronVBO);
    glGenBuffers (1, &dodecahedronEBO);
    glGenBuffers (1, &icosahedronVBO);
    glGenBuffers (1, &sphereVBO);
    glGenBuffers (1, &sphereEBO);

    glGenBuffers (1, &pointVBO);
    glGenBuffers (1, &lineVBO);
    glGenBuffers (1, &triangleVBO);
    glGenBuffers (1, &triangleEBO);

    glBindVertexArray (tetrahedronVAO);
    glBindBuffer (GL_ARRAY_BUFFER, tetrahedronVBO);
    glBufferData (GL_ARRAY_BUFFER, sizeof (Vertex) * tetrahedronVertices.size (), tetrahedronVertices.data (), GL_STATIC_DRAW);
    glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, sizeof (Vertex), 0);
    glEnableVertexAttribArray (0);
    glVertexAttribPointer (1, 3, GL_FLOAT, GL_FALSE, sizeof (Vertex), (void*)sizeof (glm::vec3));
    glEnableVertexAttribArray (1);

    glBindVertexArray (cubeVAO);
    glBindBuffer (GL_ARRAY_BUFFER, cubeVBO);
    glBufferData (GL_ARRAY_BUFFER, sizeof (Vertex) * cubeVertices.size (), cubeVertices.data (), GL_STATIC_DRAW);
    glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, sizeof (Vertex), 0);
    glEnableVertexAttribArray (0);
    glVertexAttribPointer (1, 3, GL_FLOAT, GL_FALSE, sizeof (Vertex), (void*)sizeof (glm::vec3));
    glEnableVertexAttribArray (1);
    glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, cubeEBO);
    glBufferData (GL_ELEMENT_ARRAY_BUFFER, sizeof (uint16_t) * cubeIndices.size (), cubeIndices.data (), GL_STATIC_DRAW);

    glBindVertexArray (octahedronVAO);
    glBindBuffer (GL_ARRAY_BUFFER, octahedronVBO);
    glBufferData (GL_ARRAY_BUFFER, sizeof (Vertex) * octahedronVertices.size (), octahedronVertices.data (), GL_STATIC_DRAW);
    glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, sizeof (Vertex), 0);
    glEnableVertexAttribArray (0);
    glVertexAttribPointer (1, 3, GL_FLOAT, GL_FALSE, sizeof (Vertex), (void*)sizeof (glm::vec3));
    glEnableVertexAttribArray (1);

    glBindVertexArray (dodecahedronVAO);
    glBindBuffer (GL_ARRAY_BUFFER, dodecahedronVBO);
    glBufferData (GL_ARRAY_BUFFER, sizeof (Vertex) * dodecahedronVertices.size (), dodecahedronVertices.data (), GL_STATIC_DRAW);
    glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, sizeof (Vertex), 0);
    glEnableVertexAttribArray (0);
    glVertexAttribPointer (1, 3, GL_FLOAT, GL_FALSE, sizeof (Vertex), (void*)sizeof (glm::vec3));
    glEnableVertexAttribArray (1);
    glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, dodecahedronEBO);
    glBufferData (GL_ELEMENT_ARRAY_BUFFER, sizeof (uint16_t) * dodecahedronIndices.size (), dodecahedronIndices.data (), GL_STATIC_DRAW);

    glBindVertexArray (icosahedronVAO);
    glBindBuffer (GL_ARRAY_BUFFER, icosahedronVBO);
    glBufferData (GL_ARRAY_BUFFER, sizeof (Vertex) * icosahedronVertices.size (), icosahedronVertices.data (), GL_STATIC_DRAW);
    glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, sizeof (Vertex), 0);
    glEnableVertexAttribArray (0);
    glVertexAttribPointer (1, 3, GL_FLOAT, GL_FALSE, sizeof (Vertex), (void*)sizeof (glm::vec3));
    glEnableVertexAttribArray (1);

    glBindVertexArray (pointVAO);
    glBindBuffer (GL_ARRAY_BUFFER, pointVBO);
    glBufferData (GL_ARRAY_BUFFER, sizeof (Vertex) * points.size (), points.data (), GL_STATIC_DRAW);
    glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, sizeof (Vertex), 0);
    glEnableVertexAttribArray (0);
    glVertexAttribPointer (1, 3, GL_FLOAT, GL_FALSE, sizeof (Vertex), (void*)sizeof (glm::vec3));
    glEnableVertexAttribArray (1);

    glBindVertexArray (lineVAO);
    glBindBuffer (GL_ARRAY_BUFFER, lineVBO);
    glBufferData (GL_ARRAY_BUFFER, sizeof (Vertex) * lines.size (), lines.data (), GL_STATIC_DRAW);
    glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, sizeof (Vertex), 0);
    glEnableVertexAttribArray (0);
    glVertexAttribPointer (1, 3, GL_FLOAT, GL_FALSE, sizeof (Vertex), (void*)sizeof (glm::vec3));
    glEnableVertexAttribArray (1);

    glBindVertexArray (triangleVAO);
    glBindBuffer (GL_ARRAY_BUFFER, triangleVBO);
    glBufferData (GL_ARRAY_BUFFER, sizeof (Vertex) * triangles.size (), triangles.data (), GL_STATIC_DRAW);
    glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, sizeof (Vertex), 0);
    glEnableVertexAttribArray (0);
    glVertexAttribPointer (1, 3, GL_FLOAT, GL_FALSE, sizeof (Vertex), (void*)sizeof (glm::vec3));
    glEnableVertexAttribArray (1);
    glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, triangleEBO);
    glBufferData (GL_ELEMENT_ARRAY_BUFFER, sizeof (uint16_t) * triangleIndices.size (), triangleIndices.data (), GL_STATIC_DRAW);

    glBindVertexArray (sphereVAO);
    glBindBuffer (GL_ARRAY_BUFFER, sphereVBO);
    glBufferData (GL_ARRAY_BUFFER, sizeof (Vertex) * sphere.vertices.size (), sphere.vertices.data (), GL_STATIC_DRAW);
    glVertexAttribPointer (0, 3, GL_FLOAT, GL_FALSE, sizeof (Vertex), 0);
    glEnableVertexAttribArray (0);
    glVertexAttribPointer (1, 3, GL_FLOAT, GL_FALSE, sizeof (Vertex), (void*)sizeof (glm::vec3));
    glEnableVertexAttribArray (1);
    glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, sphereEBO);
    glBufferData (GL_ELEMENT_ARRAY_BUFFER, sizeof (uint16_t) * sphere.indices.size (), sphere.indices.data (), GL_STATIC_DRAW);

    glEnable (GL_DEPTH_TEST);
    glEnable (GL_PRIMITIVE_RESTART);
    glPrimitiveRestartIndex (0xFFFF);
    glPointSize (8.f);

    std::unique_ptr<ShaderProgram> shader = ShaderProgram::CreateBasicShaderProgram ("Shaders/shader");
    shader->UseProgram ();

#pragma endregion

    float time = glfwGetTime ();

    do
    {
        float dt = glfwGetTime () - time;
        time += dt;
        controller.UpdateCamera (dt);

        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glm::mat4 transform
            = glm::ortho (-4.f, 4.f, -4.f, 4.f, -16.f, 16.f)
            * glm::lookAt (glm::vec3 {0, 4, 4}, {0, 0, 0}, up)
            * glm::rotate (PI / 6, up);
        shader->SetUniformMat4 ("transform", transform);

        glBindVertexArray (pointVAO);
        glDrawArrays (GL_POINTS, 0, points.size ());

        glBindVertexArray (lineVAO);
        glDrawArrays (GL_LINES, 0, lines.size ());

        glBindVertexArray (triangleVAO);
        glDrawElements (GL_TRIANGLES, triangleIndices.size (), GL_UNSIGNED_SHORT, 0);

        glBindVertexArray (sphereVAO);
        glDrawElements (GL_TRIANGLES, sphere.indices.size (), GL_UNSIGNED_SHORT, 0);

#ifdef FILE
        std::vector<unsigned char> frame (3 * 1024 * 1024);
        glReadPixels (0, 0, 1024, 1024, GL_RGB, GL_UNSIGNED_BYTE, frame.data ());
        stbi_flip_vertically_on_write (true);
        stbi_write_png ("Output/output.png", 1024, 1024, 3, frame.data (), 3 * 1024);
        break;
#endif

        glfwSwapBuffers (window);
        glfwWaitEventsTimeout (1.0 / 120.0);
    } while (!glfwWindowShouldClose (window));

    glfwDestroyWindow (window);
    return 0;
}
