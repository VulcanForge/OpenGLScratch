#version 450 core

in vec3 vertex_colour;

out vec4 colour;

void main ()
{
    colour = vec4 (vertex_colour, 1);
}