#include "glit/gui.hpp"

#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <glad/gl.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <imgui.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

#include "glit/error.hpp"
#include "spdlog/common.h"

namespace glit
{

GUI::GUI(int width, int height, const char *title) : width(width), height(height), window(nullptr)
{
    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%t] [%l] %v");
    try
    {
        logger = spdlog::basic_logger_mt("console", "logs.txt");
    }
    catch (const spdlog::spdlog_ex &exc)
    {
        std::string message = "Unable to initialize logger, reason: ";
        message += exc.what();
        throw GUIError(message);
    }

    logger->info("Initializing GUI...");

    if (!glfwInit())
    {
        logger->error("Failed to initialize GLFW");
        throw GUIError("Failed to initialize GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        logger->error("Failed to create GLFW window");
        throw GUIError("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(window);
    setupGlad();
    setupImgui();
}

GUI::~GUI()
{
    if (window)
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
        glfwDestroyWindow(window);
        glfwTerminate();
        logger->info("Cleaned up GUI resources");
    }
}

void
GUI::setupGlad()
{
    if (!gladLoadGL(glfwGetProcAddress))
    {
        logger->error("Failed to initialize GLAD");
        throw GUIError("Failed to initialize GLAD");
    }
    logger->info("GLAD initialized successfully");
}

void
GUI::setupImgui()
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
    ImGui::StyleColorsDark();
    logger->info("ImGui initialized successfully");
}

void
GUI::renderImgui()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("Hello, world!");
    ImGui::Text("This is a simple example.");
    ImGui::End();

    ImGui::Render();
    int display_w, display_h;
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void
GUI::run()
{
    logger->info("Entering main loop");
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        renderImgui();
        glfwSwapBuffers(window);
    }
    logger->info("Exiting main loop");
}

}  // namespace glit
