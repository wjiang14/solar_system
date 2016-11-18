//
// Created by wei on 11/18/16.
// Star.cpp
// SolarSystem
//

#include "Star.hpp"
#include "cmath"

#define PI 3.1415926

// build constructor
Star::Star(GLfloat radius, GLfloat distance, GLfloat speed, GLfloat selfSpeed, Star *parent) {
  this->radius = radius;
  this->distance = distance;
  this->selfSpeed = selfSpeed;
  this->alphaSelf = this->alpha = 0;

  for (int i = 0; i < 4; i++) {
    this->rgbaColor[i] = 1.0f;
  }

  this->parentStar = parent;
  if (speed > 0) {
    this->speed = 360.0f/speed;
  } else {
    this->speed = 0.0f;
  }
}

void Star::drawStar() {
  glEnable(GL_LINE_SMOOTH);
  glEnable(GL_BLEND);

  int n = 1440;

  // save OpenGL matrix environment
  glPushMatrix();
  {
    // revolution

    // if it is plant (parent != 0), move a radius unit
    if (parentStar != 0 && parentStar->distance > 0) {
      // rotate alpha around Z axis
      glRotatef(parentStar->alpha, 0, 0, 1);
      // translate distance along X axis, keep Y, Z constant
      glTranslatef(parentStar->distance, 0.0, 0.0);
    }

    // draw the orbit
    glBegin(GL_LINES);
    for (int i = 0; i < n; ++i) {
      glVertex2f(distance * cos(2 * PI * i / n), distance * sin(2 * PI *i / n));
    }
    glEnd();

    // rotate alpha around Z axis
    glRotatef(alpha, 0, 0, 1);
    // translate distance along X axis, keep Y, Z constant
    glTranslatef(distance, 0.0, 0.0);

    // rotation
    glRotatef(alphaSelf, 0, 0, 1);

    // draw color on planet
    glColor3f(rgbaColor[0], rgbaColor[1], rgbaColor[2]);
    glutSolidSphere(radius, 40, 32);
  }

  glPopMatrix();

  void Star::update(long timeSpan) {
    alpha += timeSpan * speed;
    alphaSelf += selfSpeed;
  }

  Planet::Planet(GLfloat radius, GLfloat distance,
      GLfloat speed,  GLfloat selfSpeed,
      Star* parent, GLfloat rgbColor[3]) :
  Star(radius, distance, speed, selfSpeed, parent) {
    rgbaColor[0] = rgbColor[0];
    rgbaColor[1] = rgbColor[1];
    rgbaColor[2] = rgbColor[2];
    rgbaColor[3] = 1.0f;
  }


  void Planet::drawPlanet() {}
}
