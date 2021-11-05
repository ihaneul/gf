#pragma once
#include "SDLGameObject.h"
#include "GameObject.h"

class Player : public SDLGameObject
{
public:
  Player(const LoaderParams* pParams);
  virtual void draw();
  virtual void update();
  virtual void clean();
};
