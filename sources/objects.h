#ifndef OBJECTS_H
#define OBJECTS_H

typedef struct {
  float posX;
  float posY;
  float velocityX;
  float velocityY;
  float radius;
} Circle;

void initCircle(Circle *circle, float x, float y, float radius);
void updateCircle(Circle *circle, float deltaTime);
void drawCircle(const Circle *circle);

#endif
