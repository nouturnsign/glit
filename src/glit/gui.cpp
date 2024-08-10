#include "glit/gui.hpp"

#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <glad/gl.h>
#include <glm/glm.hpp>
#include <imgui.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

#include "glit/error.hpp"

namespace glit
{

GUI::GUI(int width, int height, const char *title, Style theme) : m_width(width), m_height(height), m_window(nullptr)
{
    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%t] [%l] %v");
    try
    {
        m_logger = spdlog::basic_logger_mt("console", "logs.txt");
    }
    catch (const spdlog::spdlog_ex &exc)
    {
        std::string message = "Unable to initialize logger, reason: ";
        message += exc.what();
        throw GUIError(message);
    }

    m_logger->info("Initializing GUI...");

    if (!glfwInit())
    {
        m_logger->error("Failed to initialize GLFW");
        throw GUIError("Failed to initialize GLFW");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    m_window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!m_window)
    {
        glfwTerminate();
        m_logger->error("Failed to create GLFW window");
        throw GUIError("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(m_window);

    if (!gladLoadGL(glfwGetProcAddress))
    {
        m_logger->error("Failed to initialize GLAD");
        throw GUIError("Failed to initialize GLAD");
    }
    m_logger->info("GLAD initialized successfully");

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGui_ImplGlfw_InitForOpenGL(m_window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
    set_style(theme);
    m_logger->info("ImGui initialized successfully");
}

GUI::~GUI()
{
    if (m_window)
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
        glfwDestroyWindow(m_window);
    }
    glfwTerminate();
    m_logger->info("Cleaned up GUI resources");
}

void
GUI::run()
{
    m_logger->info("Entering main loop");
    while (!glfwWindowShouldClose(m_window))
    {
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::Begin("Hello, world!");
        ImGui::Text("This is a simple example.");
        ImGui::End();

        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(m_window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(m_window);
    }
    m_logger->info("Exiting main loop");
}

void
GUI::set_style(Style style)
{
    switch (style)
    {
        case Style::Light:
            ImGui::StyleColorsLight();
            glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
            break;
        case Style::Classic:
            ImGui::StyleColorsClassic();
            glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
            break;
        case Style::Dark:
        default:
            ImGui::StyleColorsDark();
            glClearColor(0.0f, 0.0f, 0.0f, 1.00f);
            break;
    }
}

}  // namespace glit
