#ifndef GLIT_GLIT_GUI_HPP_
#define GLIT_GLIT_GUI_HPP_

#include <memory>

#include <GLFW/glfw3.h>

#include "spdlog/logger.h"

namespace glit
{

/**
 * @brief A class to manage and render a GUI using GLFW and ImGui.
 */
class GUI
{
  public:
    /**
     * @brief Constructs a GUI instance.
     *
     * @param width The width of the window.
     * @param height The height of the window.
     * @param title The title of the window.
     */
    GUI(int width, int height, const char *title);

    /**
     * @brief Destroys the GUI instance, cleaning up resources.
     */
    ~GUI();

    /**
     * @brief Enters the main loop, handling rendering and events.
     */
    void run();

  private:
    GLFWwindow                     *m_window;
    int                             m_width;
    int                             m_height;
    std::shared_ptr<spdlog::logger> m_logger;
};

}  // namespace glit

#endif  // GLIT_GLIT_GUI_HPP_
