#ifndef GLIT_GLIT_GUI_HPP_
#define GLIT_GLIT_GUI_HPP_

#include <memory>

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <spdlog/logger.h>

#include "glit/commit_edge.hpp"
#include "glit/commit_node.hpp"

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

    /**
     * @brief Sets up the GUI to render a git graph.
     */
    void load_git();

  private:
    /**
     * @brief Render the current frame.
     */
    void render_frame();

    /**
     * @brief Convert logical coordinates to screen coordinates.
     *
     * @param logical_x The logical X coordinate.
     * @param logical_y The logical Y coordinate.
     * @return The corresponding screen coordinates.
     */
    glm::vec2 logical_to_screen(float logical_x, float logical_y) const;

    GLFWwindow                     *m_window;          /**< Pointer to the GLFW window. */
    int                             m_width;           /**< Width of the window. */
    int                             m_height;          /**< Height of the window. */
    std::shared_ptr<spdlog::logger> m_logger;          /**< Logger for application. */
    std::string                     m_repository_name; /**< Name of the repository. */
    std::vector<CommitNode>         m_commit_nodes;    /**< Container for commit nodes. */
    std::vector<CommitEdge>         m_commit_edges;    /**< Container for commit edges. */
    float                           m_zoom_factor;     /**< Current zoom factor. */
    glm::vec2                       m_logical_center;  /**< Current center of screen in logical coordinates. */
};

}  // namespace glit

#endif  // GLIT_GLIT_GUI_HPP_
