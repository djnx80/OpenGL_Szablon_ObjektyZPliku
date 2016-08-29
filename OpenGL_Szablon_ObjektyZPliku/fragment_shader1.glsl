#version 450

in vec2 wsp_tekstury1;

uniform sampler2D moja_tekstura1;
out vec4 kolor_wyjsciowy1;

void main()
{ 
	vec4 texel1 = texture(moja_tekstura1, wsp_tekstury1);
	kolor_wyjsciowy1 = texel1;
}