#pragma once

std::vector<glm::vec3> cube
{
    {-1, -1, -1},
    {-1, -1, 1},
    {-1, 1, -1},
    {-1, 1, 1},
    {1, -1, -1},
    {1, -1, 1},
    {1, 1, -1},
    {1, 1, 1}
};

std::vector<Vertex> cubeVertices
{
    {cube[0], red}, {cube[1], red}, {cube[2], red}, {cube[3], red},
    {cube[4], red}, {cube[5], red}, {cube[6], red}, {cube[7], red},
    {cube[0], blue}, {cube[1], blue}, {cube[4], blue}, {cube[5], blue},
    {cube[2], blue}, {cube[3], blue}, {cube[6], blue}, {cube[7], blue},
    {cube[0], yellow}, {cube[2], yellow}, {cube[4], yellow}, {cube[6], yellow},
    {cube[1], yellow}, {cube[3], yellow}, {cube[5], yellow}, {cube[7], yellow},
};

std::vector<uint16_t> cubeIndices
{
    0, 1, 3, 2, 0xFFFF,
    4, 5, 7, 6, 0xFFFF,
    8, 9, 11, 10, 0xFFFF,
    12, 13, 15, 14, 0xFFFF,
    16, 17, 19, 18, 0xFFFF,
    20, 21, 23, 22, 0xFFFF
};

glm::mat4 cubeScale = glm::scale (glm::vec3 (.5f));
