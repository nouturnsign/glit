#ifndef GLIT_GLIT_COMMIT_EDGE_HPP_
#define GLIT_GLIT_COMMIT_EDGE_HPP_

#include <imgui.h>

#include "glit/commit_node.hpp"

namespace glit
{

/**
 * @brief Represents a directed edge between two commit nodes in the visualization.
 */
class CommitEdge
{
  public:
    /**
     * @brief Constructs a CommitEdge instance.
     *
     * @param child The starting node of the edge (child node).
     * @param parent The ending node of the edge (parent node).
     */
    CommitEdge(const CommitNode &child, const CommitNode &parent);

    /**
     * @brief Renders the directed edge using ImGui.
     *
     * @param child_screen_pos The position on the screen where the arrow starts (child).
     * @param parent_screen_pos The position on the screen where the arrow ends (parent).
     * @param style The style to render with.
     */
    void render(ImVec2 child_screen_pos, ImVec2 parent_screen_pos, const ImGuiStyle &style) const;

    /**
     * @brief Gets the child commit node of the edge.
     *
     * @return The child node.
     */
    const CommitNode &get_child() const;

    /**
     * @brief Gets the parent commit node of the edge.
     *
     * @return The parent node.
     */
    const CommitNode &get_parent() const;

  private:
    const CommitNode &m_child;  /**< Starting position of the edge. */
    const CommitNode &m_parent; /**< Ending position of the edge. */
};

}  // namespace glit

#endif  // GLIT_GLIT_COMMIT_EDGE_HPP_
