#version 330 core

out vec4 fragColor;

in vec3 normal;
in vec3 fragPos;
in vec3 viewLightPos;

uniform vec3 objectColor;
uniform vec3 lightColor;

void main() 
{
  float ambientStrength = 0.1;
  vec3 ambient = ambientStrength * lightColor;
  
  vec3 norm = normalize(normal); 
  vec3 lightDir = normalize(viewLightPos - fragPos);

  float diff = max(dot(norm, lightDir), 0.0);
  vec3 diffuse = diff * lightColor;

  float specularStrength = 0.5;
  vec3 viewDir = normalize(-fragPos);
  vec3 reflectDir = reflect(-lightDir, norm);
  float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
  vec3 specular = specularStrength * spec * lightColor;  
  
  vec3 result = (ambient + diffuse + specular) * objectColor;
  //result = normal;
  fragColor = vec4( result, 1.0 );
}
