#ifndef GLIT_GLIT_GUI_HPP_
#define GLIT_GLIT_GUI_HPP_

#include <memory>

#include <GLFW/glfw3.h>

#include "spdlog/logger.h"

namespace glit
{

/**
 * @brief Enum representing available ImGui styles.
 */
enum class Style
{
    Light,   /**< Light mode style. */
    Classic, /**< Classic mode style. */
    Dark     /**< Dark mode style. */
};

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
     * @param style The initial ImGui style.
     */
    GUI(int width, int height, const char *title, Style style);

    /**
     * @brief Destroys the GUI instance, cleaning up resources.
     */
    ~GUI();

    /**
     * @brief Enters the main loop, handling rendering and events.
     */
    void run();

    /**
     * @brief Sets the ImGui style.
     *
     * @param style The desired ImGui style.
     */
    void set_style(Style style);

  private:
    GLFWwindow                     *m_window; /**< Pointer to the GLFW window. */
    int                             m_width;  /**< Width of the window. */
    int                             m_height; /**< Height of the window. */
    std::shared_ptr<spdlog::logger> m_logger; /**< Logger for application. */
};

}  // namespace glit

#endif  // GLIT_GLIT_GUI_HPP_
