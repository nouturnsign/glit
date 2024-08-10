#include "glit/commit_node.hpp"

#include <imgui.h>

namespace glit
{

CommitNode::CommitNode(const std::string &hash, const std::string &message, const std::vector<std::string> &branches,
                       const std::vector<std::string> &tags)
    : m_hash(hash), m_message(message), m_branches(branches), m_tags(tags)
{
}

void
CommitNode::render() const
{
    ImGui::Text("Commit: %s", m_hash.c_str());
    ImGui::Text("Message: %s", m_message.c_str());

    if (!m_branches.empty())
    {
        ImGui::Text("Branches:");
        for (const auto &branch : m_branches)
        {
            ImGui::BulletText("%s", branch.c_str());
        }
    }

    if (!m_tags.empty())
    {
        ImGui::Text("Tags:");
        for (const auto &tag : m_tags)
        {
            ImGui::BulletText("%s", tag.c_str());
        }
    }
}

}  // namespace glit
