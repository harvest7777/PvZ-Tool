#include "styleMenu.h"

void styleMenu(ImGuiStyle& style)
{
    //set bg color
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.14f, 0.3f, 0.14f, 1.0f);
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.14f, 0.3f, 0.14f, 1.0f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.14f, 0.3f, 0.14f, 1.0f);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.10f, 0.15f, 0.10f,1.0f);

    // Checkbox background
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.35f, 0.55f, 0.30f, 1.00f);  // Medium green

    // Checkbox background when hovered
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.45f, 0.65f, 0.40f, 1.00f);  // Slightly brighter green

    // Checkbox background when active (checked)
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.25f, 0.45f, 0.25f, 1.00f);  // Darker green

    // Checkbox checkmark color
    style.Colors[ImGuiCol_CheckMark] = ImVec4(0.85f, 0.90f, 0.85f, 1.00f);  // Light greenish white

    // Button background
    style.Colors[ImGuiCol_Button] = ImVec4(0.45f, 0.65f, 0.40f, 1.00f);  // Soft green

    // Button background when hovered
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.55f, 0.75f, 0.50f, 1.00f);  // Brighter green

    // Button background when active (clicked)
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.35f, 0.55f, 0.35f, 1.00f);  // Darker green

    // Button text color
    style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);  // White

}