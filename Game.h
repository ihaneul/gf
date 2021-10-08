#pragma once
//#ifndef __Game__
//#define __Game__

#include "SDL.h"
#include <map>
#include "TextureManager.h"

class Game{
public:
    Game() {}
    ~Game() {}

    bool init(const char *title, int  xpos,int ypos, int width, int height, int flags);
    void render();
    void update();
    bool running();
    void handleEvents();
    void clean();
    TextureManager m_textureManager;
    int m_currentFrame;
  private:
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    SDL_Texture* m_pTexture;
    //원본 사각형
    SDL_Rect m_sourceRectangle;
    //대상 사각형
    SDL_Rect m_destinationRectangle;
    bool m_bRunning;
};

//#endif