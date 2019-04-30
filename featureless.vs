#version 330 core

layout (location = 0) in vec3 pos;

uniform mat4 viewMatrix;

void main() {
	gl_Position = viewMatrix * vec4(pos, 1.0f);
};