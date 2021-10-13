#version 330 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;

out vec3 normal;
out vec3 fragPos;
out vec3 viewLightPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection; 
uniform vec3 lightPos;
uniform mat3 normalMatrix; // implement this next!!! get rid of calculation in shader, test by spinning cube

void main() 
{
  fragPos = vec3(view * model * vec4(aPos, 1.0));
  normal = mat3(transpose(inverse(view * model))) * aNormal; // do this outside of shader on big projects
  viewLightPos = vec3(view * vec4(lightPos, 1.0));
  gl_Position = projection * view * model *  vec4(aPos, 1.0);
}
