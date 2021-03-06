#pragma once

#include "context.hpp"
#include "engine.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace RendAR {
  class GLFW3Context : public Context {
  public:
    GLFW3Context();
    GLFW3Context(int width, int height);
    virtual ~GLFW3Context();
    virtual bool init(int &argc, char **argv) override;
    virtual void showWindow() override;
    virtual void mainLoop(void (*updateLoop)()) override;
    virtual void swapBuffers() override;

    void setKeyCallBack(void (*cb)(GLFWwindow*, int, int, int, int));
    void setCursorPosCallback(void (*cb)(GLFWwindow *, double, double));

  private:
    GLFWwindow *window_;
    int width_ = 800, height_ = 600;
  };
}
