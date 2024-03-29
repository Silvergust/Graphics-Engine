#version 330 core

layout (location = 0) in vec3 pos;

uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main() {
	gl_Position = projectionMatrix * viewMatrix * vec4(pos, 1.0f);
};