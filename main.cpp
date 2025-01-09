#include <cstdint>
#define CLAY_IMPLEMENTATION
#include "clay.h"
#include "renderers/raylib/clay_renderer_raylib.c"

#include <iostream>

void HandleClayErrors(Clay_ErrorData errorData) {
  printf("%s", errorData.errorText.chars);
}

int main(void) {
  Clay_Raylib_Initialize(
      1024, 768, "Introducing Clay Demo",
      FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_HIGHDPI | FLAG_MSAA_4X_HINT |
          FLAG_VSYNC_HINT); // Extra parameters to this function are new since
                            // the video was published

  uint64_t clayRequiredMemory = Clay_MinMemorySize();

  Clay_Arena clayMemory = Clay_CreateArenaWithCapacityAndMemory(
      clayRequiredMemory, malloc(clayRequiredMemory));

  Clay_Initialize(clayMemory,
                  (Clay_Dimensions){.width = float(GetScreenWidth()),
                                    .height = float(GetScreenHeight())},
                  (Clay_ErrorHandler){HandleClayErrors});

  while (!WindowShouldClose()) {
    Clay_BeginLayout();

    CLAY(CLAY_RECTANGLE({.color = {255, 0, 0, 255}}),
         CLAY_LAYOUT({.sizing = {.width = CLAY_SIZING_GROW(),
                                 .height = CLAY_SIZING_GROW()}})) {}

    Clay_RenderCommandArray renderCommands = Clay_EndLayout();

    BeginDrawing();
    ClearBackground(BLACK);
    Clay_Raylib_Render(renderCommands);
    EndDrawing();
  }
}
