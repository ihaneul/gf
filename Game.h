#pragma once
#include "SDL.h"
#include <map>
#include "TextureManager.h"
#include "SDLGameObject.h"
#include "GameObject.h"
#include "Player.h"
#include <vector>
#include "Enemy.h"

class Game{
private:
  Game() {}
  static Game* s_pInstance;
public:
  static Game* Instance() {
    if(s_pInstance == 0){
    s_pInstance = new Game();
    return s_pInstance;
    }
    return s_pInstance;
  }
  SDL_Renderer* getRenderer() const { return m_pRenderer;}
    bool init(const char *title, int  xpos,int ypos, int width, int height, int flags);
    void render();
    void update();
    bool running();
    void handleEvents();
    void clean();
    void quit() {m_bRunning = false;}
    TextureManager m_textureManager;
    int m_currentFrame;
//    GameObject m_go;
//    Player m_player;
    std::vector<GameObject*> m_gameObjects;
  private:
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
  //  SDL_Texture* m_pTexture;
    //원본 사각형
    //SDL_Rect m_sourceRectangle;
    //대상 사각형
   // SDL_Rect m_destinationRectangle;
    bool m_bRunning;
};
typedef Game TheGame;