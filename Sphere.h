#pragma once

struct Sphere
{
    std::vector<Vertex> vertices;
    std::vector<uint16_t> indices;

    Sphere (int32_t sectors, glm::vec3 colour)
    {
        float longitudeStep = PI / sectors;
        float latitudeStep = PI / sectors / 2;

        for (int32_t j = -sectors; j < sectors; ++j)
            for (int32_t i = 0; i < 2 * sectors; ++i)
            {
                glm::vec3 point
                {
                    sin (i * longitudeStep) * cos (j * latitudeStep),
                    sin (j * latitudeStep),
                    cos (i * longitudeStep) * cos (j * latitudeStep)
                };
                vertices.emplace_back (Vertex {point, colour});
                indices.emplace_back ((j + sectors) * 2 * sectors + i);
                indices.emplace_back ((j + sectors) * 2 * sectors + ((i + 1) % (2 * sectors)));
                indices.emplace_back ((j + sectors + 1) * 2 * sectors + ((i + 1) % (2 * sectors)));
                indices.emplace_back ((j + sectors) * 2 * sectors + i);
                indices.emplace_back ((j + sectors + 1) * 2 * sectors + ((i + 1) % (2 * sectors)));
                indices.emplace_back ((j + sectors + 1) * 2 * sectors + i);
            }

        for (int32_t i = 0; i < 2 * sectors; ++i)
            vertices.emplace_back (Vertex {{0, 1, 0}, colour});
    }
};
