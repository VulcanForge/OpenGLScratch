#pragma once

std::vector<glm::vec3> dodecahedron
{
    {-1, -1, -1},
    {-1, -1, 1},
    {-1, 1, -1},
    {-1, 1, 1},
    {1, -1, -1},
    {1, -1, 1},
    {1, 1, -1},
    {1, 1, 1},
    {0, -PHI, -PHI_INV},
    {0, -PHI, PHI_INV},
    {0, PHI, -PHI_INV},
    {0, PHI, PHI_INV},
    {-PHI_INV, 0, -PHI},
    {PHI_INV, 0, -PHI},
    {-PHI_INV, 0, PHI},
    {PHI_INV, 0, PHI},
    {-PHI, -PHI_INV, 0},
    {-PHI, PHI_INV, 0},
    {PHI, -PHI_INV, 0},
    {PHI, PHI_INV, 0}
};

std::vector<Vertex> dodecahedronVertices
{
    {dodecahedron[16], yellow}, {dodecahedron[17], yellow}, {dodecahedron[2], yellow}, {dodecahedron[12], yellow}, {dodecahedron[0], yellow},
    {dodecahedron[16], green}, {dodecahedron[17], green}, {dodecahedron[3], green}, {dodecahedron[14], green}, {dodecahedron[1], green},
    {dodecahedron[18], green}, {dodecahedron[19], green}, {dodecahedron[6], green}, {dodecahedron[13], green}, {dodecahedron[4], green},
    {dodecahedron[18], yellow}, {dodecahedron[19], yellow}, {dodecahedron[7], yellow}, {dodecahedron[15], yellow}, {dodecahedron[5], yellow},
    {dodecahedron[8], red}, {dodecahedron[9], red}, {dodecahedron[1], red}, {dodecahedron[16], red}, {dodecahedron[0], red},
    {dodecahedron[8], blue}, {dodecahedron[9], blue}, {dodecahedron[5], blue}, {dodecahedron[18], blue}, {dodecahedron[4], blue},
    {dodecahedron[10], blue}, {dodecahedron[11], blue}, {dodecahedron[3], blue}, {dodecahedron[17], blue}, {dodecahedron[2], blue},
    {dodecahedron[10], red}, {dodecahedron[11], red}, {dodecahedron[7], red}, {dodecahedron[19], red}, {dodecahedron[6], red},
    {dodecahedron[12], red}, {dodecahedron[13], red}, {dodecahedron[4], red}, {dodecahedron[8], red}, {dodecahedron[0], red},
    {dodecahedron[12], blue}, {dodecahedron[13], blue}, {dodecahedron[6], blue}, {dodecahedron[10], blue}, {dodecahedron[2], blue},
    {dodecahedron[14], blue}, {dodecahedron[15], blue}, {dodecahedron[5], blue}, {dodecahedron[9], blue}, {dodecahedron[1], blue},
    {dodecahedron[14], red}, {dodecahedron[15], red}, {dodecahedron[7], red}, {dodecahedron[11], red}, {dodecahedron[3], red}
};

std::vector<uint16_t> dodecahedronIndices
{
    0, 1, 2, 3, 4, 0xFFFF,
    5, 6, 7, 8, 9, 0xFFFF,
    10, 11, 12, 13, 14, 0xFFFF,
    15, 16, 17, 18, 19, 0xFFFF,
    20, 21, 22, 23, 24, 0xFFFF,
    25, 26, 27, 28, 29, 0xFFFF,
    30, 31, 32, 33, 34, 0xFFFF,
    35, 36, 37, 38, 39, 0xFFFF,
    40, 41, 42, 43, 44, 0xFFFF,
    45, 46, 47, 48, 49, 0xFFFF,
    50, 51, 52, 53, 54, 0xFFFF,
    55, 56, 57, 58, 59, 0xFFFF
};

glm::mat4 dodecahedronScale = glm::scale (glm::vec3 (.5f * PHI));
