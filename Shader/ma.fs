#version 460 core

in float ourColor;
out vec4 FragColor;

uniform float time;

void main()
{
	float c = ourColor;
	float redColor = c;
	float greenColor = 1 -c;
	vec2 Color = vec2(redColor,greenColor);
	FragColor = vec4(sin(Color + time),0.55f,1.0f);
}