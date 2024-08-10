#include <iostream>

#include "glit/error.hpp"
#include "glit/gui.hpp"

int
main() noexcept
{
    try
    {
        glit::GUI gui(640, 480, "glit", glit::Style::Classic);
        gui.run();
    }
    catch (const glit::GUIError &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
