#include "Renderer.h"

#include <iostream>

void GLClearError() {
    while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line) {
    bool isOk = true;
    while (GLenum error = glGetError()) {
        std::cout << "[OpenGL Error] (" << error << "): " << function << " " << file << ":" << line << std::endl;
        isOk = false;
    }
    return isOk;
}

void Renderer::clear() const {
    GLCall(glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::setClearColor(glm::vec4 clearColor) const {
    GLCall(glClearColor(clearColor[0], clearColor[1], clearColor[2], clearColor[3]));
}

void Renderer::draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const {
    shader.bind();
    va.bind();
    ib.bind();


    GLCall(glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}
