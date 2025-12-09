#include "objects.h"
#include "raylib.h"
#include "utils.h"

const float GRAVITY = 980.0f; // Higher = faster falling
const float BOUNCE_DAMPING =
    0.8f; // Lower = more energy loss (0.5 = very bouncy, 0.95 = super bouncy)
const float GROUND_FRICTION = 0.98f; // Lower = more friction

void initCircle(Circle *circle, float x, float y, float radius) {
  circle->posX = x;
  circle->posY = y;
  circle->velocityX = 100.0f; // pixels per second
  circle->velocityY = 0.0f;
  circle->radius = radius;
}

void updateCircle(Circle *circle, float deltaTime) {
  // Apply gravity - increases downward velocity each frame
  circle->velocityY += GRAVITY * deltaTime;

  // Update position based on velocity
  circle->posX += circle->velocityX * deltaTime;
  circle->posY += circle->velocityY * deltaTime;

  // Bounce off left and right walls
  if (circle->posX - circle->radius < 0) {
    circle->posX = circle->radius;
    circle->velocityX *= -BOUNCE_DAMPING;
  }
  if (circle->posX + circle->radius > screenWidth) {
    circle->posX = screenWidth - circle->radius;
    circle->velocityX *= -BOUNCE_DAMPING;
  }

  // Bounce off ground (bottom)
  if (circle->posY + circle->radius > screenHeight) {
    circle->posY = screenHeight - circle->radius;
    circle->velocityY *= -BOUNCE_DAMPING; // Reverse direction and lose energy
    circle->velocityX *= GROUND_FRICTION; // Slow down horizontal movement

    // Stop tiny bounces
    if (circle->velocityY > -10.0f && circle->velocityY < 0) {
      circle->velocityY = 0;
    }
  }

  // Bounce off ceiling (top)
  if (circle->posY - circle->radius < 0) {
    circle->posY = circle->radius;
    circle->velocityY *= -BOUNCE_DAMPING;
  }
}

void drawCircle(const Circle *circle) {
  Vector2 position = {circle->posX, circle->posY};
  DrawCircleV(position, circle->radius, BLUE);
}
