#ifndef GLIT_GLIT_GUI_H_
#define GLIT_GLIT_GUI_H_

#include <GLFW/glfw3.h>

namespace glit
{

void setup_glad();
void setup_imgui(GLFWwindow *window);
void render_imgui();
int  mainloop();

}  // namespace glit

#endif  // GLIT_GLIT_GUI_H_
