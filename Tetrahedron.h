#pragma once

std::vector<glm::vec3> tetrahedron
{
    {1, 1, 1},
    {-1, -1, 1},
    {-1, 1, -1},
    {1, -1, -1}
};

std::vector<Vertex> tetrahedronVertices
{
    {tetrahedron[0], red}, {tetrahedron[1], red}, {tetrahedron[2], red},
    {tetrahedron[0], green}, {tetrahedron[1], green}, {tetrahedron[3], green},
    {tetrahedron[0], blue}, {tetrahedron[2], blue}, {tetrahedron[3], blue},
    {tetrahedron[1], purple}, {tetrahedron[2], purple}, {tetrahedron[3], purple}
};

glm::mat4 tetrahedronScale = glm::scale (glm::vec3 (.5f * SQRT2_INV));
