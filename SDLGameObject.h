#ifndef __SDLGAMEOBJECT_H__
#define __SDLGAMEOBJECT_H__
#include"GameObject.h"
#include"Vector2D.h"
class SDLGameObject : public GameObject{
public:
  SDLGameObject(const LoaderParams* pParams);
  virtual void draw();
  virtual void update();
  virtual void clean(){};
  virtual ~SDLGameObject(){}
protected:
  Vector2D m_position;
  Vector2D m_velocity;
  Vector2D m_acceleration;
  int m_width = 0;
  int m_height = 0;
  int m_currentRow = 0;
  int m_currentFrame = 0;
  std::string m_textureID = "";
};

#endif
