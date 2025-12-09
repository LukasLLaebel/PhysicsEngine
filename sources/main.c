#include "objects.h"
#include "raylib.h"

const int screenWidth = 800;
const int screenHeight = 600;

int main() {
  InitWindow(screenWidth, screenHeight, "Physics Engine");
  SetTargetFPS(60);

  // Create an array of circles
  const int numCircles = 5;
  Circle circles[numCircles];

  // Initialize each circle at different positions
  initCircle(&circles[0], 100, 100, 50.0f);
  initCircle(&circles[1], 300, 200, 40.0f);
  initCircle(&circles[2], 500, 150, 60.0f);
  initCircle(&circles[3], 200, 400, 45.0f);
  initCircle(&circles[4], 600, 300, 55.0f);

  // Main game loop
  while (!WindowShouldClose()) {
    float deltaTime = GetFrameTime();

    // Update all circles
    for (int i = 0; i < numCircles; i++) {
      updateCircle(&circles[i], deltaTime);
    }

    // Draw
    BeginDrawing();
    ClearBackground(RAYWHITE);

    // Draw all circles
    for (int i = 0; i < numCircles; i++) {
      drawCircle(&circles[i]);
    }

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
