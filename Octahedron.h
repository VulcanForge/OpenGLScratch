#pragma once

std::vector<glm::vec3> octahedron
{
    {-1, 0, 0},
    {1, 0, 0},
    {0, -1, 0},
    {0, 1, 0},
    {0, 0, -1},
    {0, 0, 1}
};

std::vector<Vertex> octahedronVertices
{
    {octahedron[0], red}, {octahedron[2], red}, {octahedron[4], red},
    {octahedron[0], blue}, {octahedron[2], blue}, {octahedron[5], blue},
    {octahedron[0], green}, {octahedron[3], green}, {octahedron[4], green},
    {octahedron[0], yellow}, {octahedron[3], yellow}, {octahedron[5], yellow},
    {octahedron[1], yellow}, {octahedron[2], yellow}, {octahedron[4], yellow},
    {octahedron[1], green}, {octahedron[2], green}, {octahedron[5], green},
    {octahedron[1], blue}, {octahedron[3], blue}, {octahedron[4], blue},
    {octahedron[1], red}, {octahedron[3], red}, {octahedron[5], red}
};

glm::mat4 octahedronScale = glm::scale (glm::vec3 (SQRT2_INV));
