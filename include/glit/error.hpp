#ifndef GLIT_GLIT_ERROR_HPP_
#define GLIT_GLIT_ERROR_HPP_

#include <stdexcept>
#include <string>

namespace glit
{

class GlitError : public std::runtime_error
{
  public:
    GlitError(const std::string &msg) : std::runtime_error(msg)
    {
    }
};

class GUIError : public GlitError
{
  public:
    GUIError(const std::string &msg) : GlitError(msg)
    {
    }
};

}  // namespace glit

#endif  // GLIT_GLIT_ERROR_HPP_
