#include "Shader.h"
#include <iostream>
#include <vector>
#include <glm/gtc/type_ptr.hpp>

Shader::Shader(const std::string& vertexSrc, const std::string& fragmentSrc) {
    GLuint vertexShader = compileShader(GL_VERTEX_SHADER, vertexSrc);
    GLuint fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentSrc);

    id = glCreateProgram();
    glAttachShader(id, vertexShader);
    glAttachShader(id, fragmentShader);
    glLinkProgram(id);

    GLint isLinked = 0;
    glGetProgramiv(id, GL_LINK_STATUS, (int*)&isLinked);
    if (isLinked == GL_FALSE) {
        GLint maxLength = 0;
        glGetProgramiv(id, GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<GLchar> infoLog(maxLength);
        glGetProgramInfoLog(id, maxLength, &maxLength, &infoLog[0]);

        glDeleteProgram(id);
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        std::cerr << "Shader link error: " << infoLog.data() << std::endl;
        return;
    }

    glDetachShader(id, vertexShader);
    glDetachShader(id, fragmentShader);
}

Shader::~Shader() {
    glDeleteProgram(id);
}

void Shader::bind() const {
    glUseProgram(id);
}

void Shader::unbind() const {
    glUseProgram(0);
}

void Shader::setMat4(const std::string& name, const glm::mat4& matrix) {
    GLint location = glGetUniformLocation(id, name.c_str());
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

GLuint Shader::compileShader(GLenum type, const std::string& source) {
    GLuint shader = glCreateShader(type);
    const GLchar* sourceCStr = source.c_str();
    glShaderSource(shader, 1, &sourceCStr, 0);
    glCompileShader(shader);

    GLint isCompiled = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled == GL_FALSE) {
        GLint maxLength = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<GLchar> infoLog(maxLength);
        glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

        glDeleteShader(shader);
        std::cerr << "Shader compile error: " << infoLog.data() << std::endl;
        return 0;
    }

    return shader;
}
