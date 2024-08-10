#ifndef GLIT_GLIT_GUI_HPP_
#define GLIT_GLIT_GUI_HPP_

#include <GLFW/glfw3.h>

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

    GLFWwindow *window;
    int         width;
    int         height;
};

}  // namespace glit

#endif  // GLIT_GLIT_GUI_HPP_
