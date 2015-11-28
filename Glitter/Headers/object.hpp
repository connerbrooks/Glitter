#pragma once
#include <vector>
#include "transform.hpp"
#include "shader.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace RendAR
{
  class Object : public Transform {
  public:
    Object();
    ~Object();

    void setVertices(const std::vector<GLfloat>& vertices);
    void setVertices(const std::vector<GLfloat>& vertices,
                     const std::vector<GLushort>& indices);
    void setVertices(const std::vector<GLfloat>& vertices,
                     const std::vector<GLfloat>& normals);
    void setShader(const Shader& shader);
    virtual void render(glm::mat4& view, glm::mat4& proj) = 0;

    Shader shader_;
    GLuint VBO, VAO;

  private:
    std::vector<GLushort> indices_;
    std::vector<GLfloat> vertices_;
    std::vector<GLfloat> normals_;

    GLint uniform_model_;
    GLint uniform_view_;
    GLint uniform_projection_;
    //GLint uniform_color_;

    //glm::vec3 position_;
    //virtual void render() = 0;

  };
}