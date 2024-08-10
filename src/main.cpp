#include <cstdlib>
#include <iostream>
#include <string>

#include <cxxopts.hpp>

#include "glit/error.hpp"
#include "glit/gui.hpp"

int
main(int argc, char *argv[]) noexcept
{
    cxxopts::Options options("glit", "A Git graph visualizer");

    // clang-format off
    options.add_options()
        ("w,width", "Window width", cxxopts::value<int>()->default_value("800"))
        ("h,height", "Window height", cxxopts::value<int>()->default_value("600"))
        ("t,title", "Window title", cxxopts::value<std::string>()->default_value("glit"))
        ("s,style", "ImGui style (Light, Classic, Dark)", cxxopts::value<std::string>()->default_value("Dark"))
        ("help", "Print usage")
        ;
    // clang-format on

    cxxopts::ParseResult result;
    try
    {
        result = options.parse(argc, argv);
    }
    catch (const cxxopts::exceptions::exception &exc)
    {
        std::cerr << "glit Option Error: " << exc.what() << std::endl;
        return EXIT_FAILURE;
    }

    if (result.count("help"))
    {
        std::cout << options.help() << std::endl;
        return EXIT_SUCCESS;
    }

    int         width;
    int         height;
    std::string title;
    std::string style_str;
    try
    {
        width = result["width"].as<int>();
        height = result["height"].as<int>();
        title = result["title"].as<std::string>();
        style_str = result["style"].as<std::string>();
    }
    catch (const cxxopts::exceptions::exception &exc)
    {
        std::cerr << "glit Option Error: " << exc.what() << std::endl;
        return EXIT_FAILURE;
    }

    glit::Style style;
    if (style_str == "Light")
        style = glit::Style::Light;
    else if (style_str == "Classic")
        style = glit::Style::Classic;
    else if (style_str == "Dark")
        style = glit::Style::Dark;
    else
    {
        std::cerr << "glit Option Error: failed to parse options: invalid style string" << std::endl;
        return EXIT_FAILURE;
    }

    try
    {
        glit::GUI gui(width, height, title.c_str(), style);
        gui.run();
    }
    catch (const glit::GUIError &exc)
    {
        std::cerr << "glit GUI Error: " << exc.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
