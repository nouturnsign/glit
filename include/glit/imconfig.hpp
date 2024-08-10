#ifndef GLIT_GLIT_CONFIG_HPP_
#define GLIT_GLIT_CONFIG_HPP_

// clang-format off
#define IM_VEC2_CLASS_EXTRA \
    constexpr ImVec2(const glm::vec2& f) : x(f.x), y(f.y) {} \
    operator glm::vec2() const { return glm::vec2(x,y); }
// clang-format on

#endif  // GLIT_GLIT_CONFIG_HPP_
