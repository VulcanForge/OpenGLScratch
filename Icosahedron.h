#pragma once

std::vector<glm::vec3> icosahedron
{
    {0, -1, -PHI},
    {0, -1, PHI},
    {0, 1, -PHI},
    {0, 1, PHI},
    {-PHI, 0, -1},
    {-PHI, 0, 1},
    {PHI, 0, -1},
    {PHI, 0, 1},
    {-1, -PHI, 0},
    {-1, PHI, 0},
    {1, -PHI, 0},
    {1, PHI, 0}
};

std::vector<Vertex> icosahedronVertices
{
    {icosahedron[0], red}, {icosahedron[2], red}, {icosahedron[4], red},
    {icosahedron[0], blue}, {icosahedron[2], blue}, {icosahedron[6], blue},
    {icosahedron[1], red}, {icosahedron[3], red}, {icosahedron[5], red},
    {icosahedron[1], blue}, {icosahedron[3], blue}, {icosahedron[7], blue},
    {icosahedron[4], red}, {icosahedron[5], red}, {icosahedron[8], red},
    {icosahedron[4], blue}, {icosahedron[5], blue}, {icosahedron[9], blue},
    {icosahedron[6], red}, {icosahedron[7], red}, {icosahedron[10], red},
    {icosahedron[6], blue}, {icosahedron[7], blue}, {icosahedron[11], blue},
    {icosahedron[8], red}, {icosahedron[10], red}, {icosahedron[0], red},
    {icosahedron[8], blue}, {icosahedron[10], blue}, {icosahedron[1], blue},
    {icosahedron[9], red}, {icosahedron[11], red}, {icosahedron[2], red},
    {icosahedron[9], blue}, {icosahedron[11], blue}, {icosahedron[3], blue},
    {icosahedron[0], yellow}, {icosahedron[4], yellow}, {icosahedron[8], yellow},
    {icosahedron[0], yellow}, {icosahedron[6], yellow}, {icosahedron[10], yellow},
    {icosahedron[1], yellow}, {icosahedron[5], yellow}, {icosahedron[8], yellow},
    {icosahedron[1], yellow}, {icosahedron[7], yellow}, {icosahedron[10], yellow},
    {icosahedron[2], yellow}, {icosahedron[4], yellow}, {icosahedron[9], yellow},
    {icosahedron[2], yellow}, {icosahedron[6], yellow}, {icosahedron[11], yellow},
    {icosahedron[3], yellow}, {icosahedron[5], yellow}, {icosahedron[9], yellow},
    {icosahedron[3], yellow}, {icosahedron[7], yellow}, {icosahedron[11], yellow}
};

glm::mat4 icosahedronScale = glm::scale (glm::vec3 (.5f));
