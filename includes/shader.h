#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

class Shader 
{
  public:
    // Shader program ID
    unsigned int ID;

    // Constructor
    Shader(const char* vertexPath, const char* fragmentPath);
    // use shader
    void use();
    // utility uniform functions
    void setBool(const std::string &name, bool value) const;  
    void setInt(const std::string &name, int value) const;   
    void setFloat(const std::string &name, float value) const;
    void setMat4(const std::string &name, const glm::mat4 &mat) const;
    void setVec3(const std::string &name, const glm::vec3 &vec) const;
    void setVec3(const std::string &name, float x, float y, float z) const;

  private:
    void checkCompileErrors(GLuint shader, std::string type);

};

#endif


