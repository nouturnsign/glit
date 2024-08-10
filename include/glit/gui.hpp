#ifndef GLIT_GLIT_GUI_HPP_
#define GLIT_GLIT_GUI_HPP_

#include <memory>

#include <GLFW/glfw3.h>

#include "spdlog/logger.h"

namespace glit
{

class GUI
{
  public:
    GUI(int width, int height, const char *title);
    ~GUI();
    void run();

  private:
    void setupGlad();
    void setupImgui();
    void renderImgui();

    GLFWwindow                     *window;
    int                             width;
    int                             height;
    std::shared_ptr<spdlog::logger> logger;
};

}  // namespace glit

#endif  // GLIT_GLIT_GUI_HPP_
