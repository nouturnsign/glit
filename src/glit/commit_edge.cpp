#include "glit/commit_edge.hpp"

#include <glm/glm.hpp>

#include "glit/commit_node.hpp"

namespace glit
{

CommitEdge::CommitEdge(const CommitNode &child, const CommitNode &parent) : m_child(child), m_parent(parent)
{
}

void
CommitEdge::render(glm::vec2 child_screen_pos, glm::vec2 parent_screen_pos, const ImGuiStyle &style) const
{
    constexpr float ARROW_SIZE = 10.0f;                                               // Size of the arrowhead
    ImU32 arrow_color = ImGui::ColorConvertFloat4ToU32(style.Colors[ImGuiCol_Text]);  // Using text color for the arrow
    const glm::vec2 start = child_screen_pos;
    const glm::vec2 end = parent_screen_pos;

    ImDrawList *draw_list = ImGui::GetWindowDrawList();

    glm::vec2 dir = end - start;
    float     length = std::sqrt(dir.x * dir.x + dir.y * dir.y);
    dir = dir / length;
    draw_list->AddLine(start, end, arrow_color, 2.0f);

    glm::vec2 arrow_tip = end - dir * ARROW_SIZE * 1.5f;
    glm::vec2 arrow_side1 = arrow_tip + glm::vec2(-dir.y, dir.x) * ARROW_SIZE;
    glm::vec2 arrow_side2 = arrow_tip - glm::vec2(-dir.y, dir.x) * ARROW_SIZE;
    draw_list->AddTriangleFilled(arrow_tip, arrow_side1, arrow_side2, arrow_color);
}

const CommitNode &
CommitEdge::get_child() const
{
    return m_child;
}

const CommitNode &
CommitEdge::get_parent() const
{
    return m_parent;
}

}  // namespace glit
