#version 450

layout(location = 0) in vec3 pozycja;
layout(location = 2) in vec2 vt;

uniform mat4 macierz_przesuniecia;

out vec2 wsp_tekstury;

void main()
{
	wsp_tekstury = vt;
	gl_Position = macierz_przesuniecia*vec4(pozycja, 1.0);
}

//macierz_przesuniecia*vec4(pozycja, 1.0);