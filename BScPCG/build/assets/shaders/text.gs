#version 330 core

layout(points) in;
layout(triangles, max_vertices=3) out;

uniform mat4 ProjectionMatrix;
uniform vec2 Size;

out vec2 geomUV;

void main()
{
	// Left triangle:
	// Top left
	gl_Position = ProjectionMatrix * gl_in[0].gl_Position;
	geomUV = vec2(0.0, 0.0);
	EmitVertex();
	
	// Bottom left
	gl_Position = ProjectionMatrix * (gl_in[0].gl_Position + vec4(0.0, Size.y, 0.0, 0.0));
	geomUV = vec2(0.0, 1.0);
	EmitVertex();
	
	// Bottom right
	gl_Position = ProjectionMatrix * (gl_in[0].gl_Position + vec4(Size.x, Size.y, 0.0, 0.0));
	geomUV = vec2(1.0, 1.0);
	EmitVertex();
	
	// Right triangle:
	// Top left
	gl_Position = ProjectionMatrix * gl_in[0].gl_Position;
	geomUV = vec2(0.0, 0.0);
	EmitVertex();
	
	// Bottom right
	gl_Position = ProjectionMatrix * (gl_in[0].gl_Position + vec4(Size.x, Size.y, 0.0, 0.0));
	geomUV = vec2(1.0, 1.0);
	EmitVertex();
	
	// Top right
	gl_Position = ProjectionMatrix * (gl_in[0].gl_Position + vec4(Size.x, 0.0, 0.0, 0.0));
	geomUV = vec2(1.0, 0.0);
	EmitVertex();
}