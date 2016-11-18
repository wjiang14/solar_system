//
// Created by wei on 11/18/16.
// Star.hpp
// Solar_System
//

#ifndef SOLAR_SYSTEM_STAR_HPP
#define SOLAR_SYSTEM_STAR_HPP
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
class Star {
 public:
  // radius of star orbit
  GLfloat  radius;
  // rotation speed
  GLfloat  speed, selfSpeed;
  // distance between start center and parent start
  GLfloat distance;
  // start color
  GLfloat rgbaColor[4];

  // parent star
  Star* parentStar;
  Star(GLfloat radius, GLfloat distance, GLfloat speed, GLfloat selfSpeed,
       Star* parent);
  // draw star move, rotation on canvas
  void drawStar();
  // call drawStar();
  virtual void draw() {drawStar()};
  // parameter is time span for each frame update
  virtual void update(long timeSpan);

 protected:
  GLfloat alphaSelf, alpha;
};

class Planet: public Star {
 public:
  Planet(GLfloat radius, GLfloat distance, GLfloat speed, GLfloat selfSpeed,
         Star* parent, GLfloat rgbColor[3]);

  // draw texture on planet
  void drawPlanet();

  virtual void draw() {drawPlanet(); drawStar();}

};

class LightPlanet : public Planet {
 public:
  LightPlanet(GLfloat Radius, GLfloat Distance,
              GLfloat Speed, GLfloat SelfSpeed,
              Star* Parent, GLfloat rgbColor[]);

  // light source
  void drawLight();
  virtual void draw() {drawLight(); drawPlanet(); drawStar();}
};
#endif //SOLAR_SYSTEM_STAR_HPP
