
#include "imgui.h"
#include "imgui_impl_sdl.h"
//#include "imgui_impl_opengl3.h"
#include <SDL.h>
//#include <GL/glew.h> // Include GLEW for OpenGL function loading
#include <iostream>

void ThreeDStyle()
{
    ImGuiStyle &style = ImGui::GetStyle();

    // Define colors
    ImColor DarkBackground = ImColor(30, 30, 30, 255);
    ImColor LightGray = ImColor(200, 200, 200, 255);
    ImColor DarkGray = ImColor(50, 50, 50, 255);
    ImColor ButtonColor = ImColor(70, 70, 70, 255);
    ImColor ButtonHoverColor = ImColor(90, 90, 90, 255);
    ImColor ButtonActiveColor = ImColor(110, 110, 110, 255);

    style.WindowRounding = 5.0f;
    style.FrameRounding = 5.0f;
    style.GrabRounding = 5.0f;

    // Set colors
    style.Colors[ImGuiCol_WindowBg] = DarkBackground;
    style.Colors[ImGuiCol_FrameBg] = DarkGray;
    style.Colors[ImGuiCol_FrameBgHovered] = LightGray;
    style.Colors[ImGuiCol_FrameBgActive] = ButtonActiveColor;
    style.Colors[ImGuiCol_Button] = ButtonColor;
    style.Colors[ImGuiCol_ButtonHovered] = ButtonHoverColor;
    style.Colors[ImGuiCol_ButtonActive] = ButtonActiveColor;

    // Shadow effect for buttons
    style.Colors[ImGuiCol_Border] = DarkGray;
}
/*

int main(int, char**)
{
    // Setup SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create an SDL window
    SDL_Window* window = SDL_CreateWindow("3D-like UI Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_OPENGL);
    if (!window)
    {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Create an OpenGL context
    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    glewInit(); // Initialize GLEW

    // Setup ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark(); // Use dark style

    // Setup Platform/Renderer bindings
    ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
    ImGui_ImplOpenGL3_Init("#version 130");

    // Custom style
    ThreeDStyle();

    // Main loop
    bool running = true;
    while (running)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                running = false;

            ImGui_ImplSDL2_ProcessEvent(&event);
        }*/

        // Start the ImGui frame
        
