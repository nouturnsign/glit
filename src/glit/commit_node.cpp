#include "glit/commit_node.hpp"

#include <glm/glm.hpp>
#include <imgui.h>

namespace glit
{

constexpr float NODE_RADIUS = 40.0f;  // TODO: determine radius from screen

CommitNode::CommitNode(glm::vec2 logical_pos, const std::string &hash, const std::string &message,
                       const std::vector<std::string> &branches, const std::vector<std::string> &tags)
    : m_hash(hash), m_message(message), m_branches(branches), m_tags(tags), m_logical_pos(logical_pos)
{
}

void
CommitNode::render(glm::vec2 screen_pos, const ImGuiStyle &style) const
{
    const float radius = NODE_RADIUS;
    ImU32       line_color = ImGui::ColorConvertFloat4ToU32(style.Colors[ImGuiCol_Text]);

    ImDrawList *draw_list = ImGui::GetWindowDrawList();
    draw_list->AddCircle(screen_pos, radius, line_color, 12, 1.0f);

    // Render node text
    glm::vec2 text_pos(screen_pos.x - radius + 5, screen_pos.y - 10);
    ImGui::SetCursorScreenPos(text_pos);
    ImGui::Text("%s", get_abbreviated_hash().c_str());
    ImGui::Text("%s", get_first_line_message().c_str());

    // Render tags and branches
    float     marker_radius = 10.0f;
    glm::vec2 marker_offset(0, -radius - 20);

    for (const auto &branch : m_branches)
    {
        render_marker(screen_pos + marker_offset, branch, IM_COL32(0, 255, 0, 255));
        marker_offset.y -= marker_radius * 2;
    }

    marker_offset.x += marker_radius * 2;
    for (const auto &tag : m_tags)
    {
        render_marker(screen_pos + marker_offset, tag, IM_COL32(255, 0, 0, 255));
        marker_offset.y -= marker_radius * 2;
    }
}

void
CommitNode::set_logical_pos(glm::vec2 logical_pos)
{
    m_logical_pos = logical_pos;
}

glm::vec2
CommitNode::get_logical_pos() const
{
    return m_logical_pos;
}

std::string
CommitNode::get_abbreviated_hash() const
{
    return m_hash.substr(0, 7);  // Abbreviate to first 7 characters
}

std::string
CommitNode::get_first_line_message() const
{
    size_t pos = m_message.find('\n');
    return (pos != std::string::npos) ? m_message.substr(0, pos) : m_message;
}

void
CommitNode::render_marker(glm::vec2 position, const std::string &label, ImU32 color) const
{
    ImDrawList *draw_list = ImGui::GetWindowDrawList();
    float       marker_radius = 10.0f;
    draw_list->AddCircleFilled(position, marker_radius, color);
    ImGui::SetCursorScreenPos(position + glm::vec2(-marker_radius, -marker_radius));
    ImGui::Text("%s", label.c_str());
}

}  // namespace glit
