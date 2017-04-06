#version 450

layout(location=0) in vec3 PositionIn;
layout(location=1) in vec2 UVIn;
layout(location=2) in vec3 NormalIn;
layout(location=3) in vec3 TangentIn;
layout(location=4) in vec3 BitangentIn;

uniform mat4 ProjectionMatrix;
uniform mat4 ViewMatrix;
uniform mat4 WorldMatrix;

void main()
{
	gl_Position = ProjectionMatrix * ViewMatrix * WorldMatrix * vec4(PositionIn,1.0);
};