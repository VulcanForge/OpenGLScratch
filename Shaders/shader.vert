#version 450 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 colour;

uniform mat4 transform;

out vec3 vertex_colour;

void main ()
{
    gl_Position = transform * vec4 (position, 1);
	vertex_colour = colour;
}