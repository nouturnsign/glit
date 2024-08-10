#ifndef GLIT_GLIT_ERROR_HPP_
#define GLIT_GLIT_ERROR_HPP_

#include <stdexcept>
#include <string>

namespace glit
{

/**
 * @brief Base class for all exceptions in the glit library.
 *
 * This class serves as the base exception type for all errors that occur
 * within the glit library. It inherits from `std::runtime_error` to provide
 * a standard exception interface.
 */
class GlitError : public std::runtime_error
{
  public:
    /**
     * @brief Constructs a GlitError instance with a message.
     *
     * @param msg The error message to be associated with the exception.
     */
    GlitError(const std::string &msg) : std::runtime_error(msg)
    {
    }
};

/**
 * @brief Exception class for GUI-related errors in the glit library.
 *
 * This class is derived from `GlitError` and is used specifically for
 * exceptions related to GUI operations in the glit library.
 */
class GUIError : public GlitError
{
  public:
    /**
     * @brief Constructs a GUIError instance with a message.
     *
     * @param msg The error message to be associated with the exception.
     */
    GUIError(const std::string &msg) : GlitError(msg)
    {
    }
};

}  // namespace glit

#endif  // GLIT_GLIT_ERROR_HPP_
