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
     * @param hash The hash of the commit.
     * @param message The first line of the commit message.
     * @param branches A list of branches associated with the commit.
     * @param tags A list of tags associated with the commit.
     */
    CommitNode(const std::string &hash, const std::string &message, const std::vector<std::string> &branches = {},
               const std::vector<std::string> &tags = {});

    /**
     * @brief Renders the commit node using ImGui.
     */
    void render() const;

  private:
    std::string              m_hash;     /**< Commit hash. */
    std::string              m_message;  /**< First line of commit message. */
    std::vector<std::string> m_tags;     /**< Tags associated with the commit. */
    std::vector<std::string> m_branches; /**< Branches associated with the commit. */
};

}  // namespace glit

#endif  // GLIT_GLIT_COMMIT_NODE_HPP_
