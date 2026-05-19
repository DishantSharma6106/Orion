#pragma once

#include <string>
#include <glad/gl.h>
#include <glm/glm.hpp>

class Shader {
public:
    Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
    ~Shader();

    void bind() const;
    void unbind() const;

    void setMat4(const std::string& name, const glm::mat4& matrix);

private:
    GLuint compileShader(GLenum type, const std::string& source);

    GLuint id;
};
