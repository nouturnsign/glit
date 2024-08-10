#ifndef GLIT_GLIT_COMMIT_NODE_HPP_
#define GLIT_GLIT_COMMIT_NODE_HPP_

#include <string>
#include <vector>

#include <imgui.h>

namespace glit
{

/**
 * @brief Represents a commit node in the visualization.
 */
class CommitNode
{
  public:
    /**
     * @brief Constructs a CommitNode instance.
     *
     * @param logical_x The x-coordinate in logical coordinates.
     * @param logical_y The y-coordinate in logical coordinates.
     * @param hash The hash of the commit.
     * @param message The commit message.
     * @param branches A list of branches associated with the commit.
     * @param tags A list of tags associated with the commit.
     */
    CommitNode(float logical_x, float logical_y, const std::string &hash, const std::string &message,
               const std::vector<std::string> &branches = {}, const std::vector<std::string> &tags = {});

    /**
     * @brief Renders the commit node at a specific screen position.
     *
     * @param screen_pos The position on the screen where the node should be rendered.
     * @param style The style to render with.
     */
    void render(ImVec2 screen_pos, const ImGuiStyle &style) const;

    /**
     * @brief Sets the logical X coordinate of the commit node.
     *
     * @param logical_x The logical X coordinate.
     */
    void set_logical_x(float logical_x);

    /**
     * @brief Sets the logical Y coordinate of the commit node.
     *
     * @param logical_y The logical Y coordinate.
     */
    void set_logical_y(float logical_y);

    /**
     * @brief Gets the logical X coordinate of the commit node.
     *
     * @return The logical X coordinate.
     */
    float get_logical_x() const;

    /**
     * @brief Gets the logical Y coordinate of the commit node.
     *
     * @return The logical Y coordinate.
     */
    float get_logical_y() const;

  private:
    /**
     * @brief Returns the abbreviated commit hash.
     *
     * @return The first 7 characters of the commit hash.
     */
    std::string get_abbreviated_hash() const;

    /**
     * @brief Returns the first line of the commit message.
     *
     * @return The first line of the commit message or the entire message if no newline is found.
     */
    std::string get_first_line_message() const;

    /**
     * @brief Renders a marker (e.g., tag or branch) at a specified position.
     *
     * @param position The position to render the marker.
     * @param label The label to display on the marker.
     * @param color The color of the marker.
     */
    void render_marker(ImVec2 position, const std::string &label, ImU32 color) const;

    std::string              m_hash;      /**< Commit hash. */
    std::string              m_message;   /**< Commit message. */
    std::vector<std::string> m_tags;      /**< Tags associated with the commit. */
    std::vector<std::string> m_branches;  /**< Branches associated with the commit. */
    float                    m_logical_x; /**< Logical X coordinate. */
    float                    m_logical_y; /**< Logical Y coordinate. */
};

}  // namespace glit

#endif  // GLIT_GLIT_COMMIT_NODE_HPP_
