# PvZ-Tool 🌱
This is an external mod menu for Plants vs. Zombies GOTY Edition. 

# Features ⛏️
- Modify tree of wisdom and money stats
- Set sun values mid game
- Freeze sun

- Plant an entire row at a time
- Disable plant cooldown
- Make plants invincible

# Usage 
- You may simply clone the repository and use the pre-compiled binary OR compile it yourself (see requirements)

# Requirements
- A compiler that supports C++ 14
- Windows 10+ (DirectX 11 is a dependency for rendering the GUI)

# Compiling
```bash
git clone https://github.com/harvest7777/PvZ-Tool.git
cd PvZ-Tool

g++ main.cpp Level.cpp styleMenu.cpp WinHelpers.cpp ZenGarden.cpp imgui.cpp imgui_demo.cpp imgui_draw.cpp imgui_impl_dx11.cpp imgui_impl_win32.cpp imgui_tables.cpp imgui_widgets.cpp -o main.exe -L"C:\Program Files (x86)\Windows Kits\10\Lib\10.0.22621.0\um\x64" -ld3d11 -ldxgi -ldxguid -ld3dcompiler -luser32 -lgdi32 -ldwmapi

./main.exe
```
