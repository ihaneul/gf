#include "Game.h"
//#include "SDL_image.h"
#include "TextureManager.h"

bool Game::init(const char *title, int  xpos,int ypos, int width, int height, int flags)
{
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    m_pWindow = SDL_CreateWindow(title, xpos,ypos,width,height,flags);
    if(m_pWindow != 0){
      m_pRenderer = SDL_CreateRenderer(m_pWindow,-1,0);

      if(m_pRenderer != 0){
        SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 0);
      } else{
        return false; // 랜더러 생성 실패
      }
    } else{
      return false; // 윈도우 생성 실패
    }
  }else{
      return false; // SDL 초기화 실패
    }
  m_bRunning = true;

  m_textureManager.load("Assets/animate-alpha.png", "animate", m_pRenderer);
  m_go.load(100, 100,  128, 82,"animate");
  m_player.load(300, 300, 128, 82,"animate");
  return true;
}

void Game::update()
{
  m_go.update();
  m_player.update();
}

void Game::render()
{
  SDL_RenderClear(m_pRenderer);   // 랜더 삭제 

  m_go.draw(m_pRenderer);
  m_player.draw(m_pRenderer);

  SDL_RenderPresent(m_pRenderer); // 다른 버퍼 연결
}

bool Game::running()
{
  return m_bRunning;
}

void Game::handleEvents()
{
  SDL_Event event;
  if(SDL_PollEvent(&event)){
    switch(event.type){
      case SDL_QUIT:
        m_bRunning = false;
        break;
      default:
        break;
    }
  }
}
void Game::clean()
{
  SDL_DestroyWindow(m_pWindow);
  SDL_DestroyRenderer(m_pRenderer);
  SDL_Quit();
}