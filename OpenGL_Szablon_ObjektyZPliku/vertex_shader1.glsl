#version 450

layout(location = 0) in vec3 pozycja1;
layout(location = 2) in vec2 vt1;

uniform mat4 macierz_przesuniecia1;

out vec2 wsp_tekstury1;

void main()
{
	wsp_tekstury1 = vt1;
	gl_Position1 = macierz_przesuniecia1*vec4(pozycja1, 1.0);
}

//macierz_przesuniecia*vec4(pozycja, 1.0);