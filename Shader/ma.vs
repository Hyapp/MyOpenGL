#version 460 core

layout (location = 0) in vec3 Data;
out float ourColor;
 
void main()
{
	gl_Position = vec4(Data.xy,1.0f,1.0f);
	ourColor = Data.z;
}