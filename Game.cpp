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
/*  SDL_Surface* pTemSurface = IMG_Load("Assets/animate-alpha.png");
  SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255); // 붉은색 배경
  m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTemSurface);

  SDL_FreeSurface(pTemSurface); // surface 삭제 

 // SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
  
  m_sourceRectangle.x = 0;
  m_sourceRectangle.y = 0;

  m_sourceRectangle.h = 82;
  m_sourceRectangle.w = 128;
  m_destinationRectangle.w = m_sourceRectangle.w;
  m_destinationRectangle.h = m_sourceRectangle.h;

  m_destinationRectangle.x = 0;
  m_destinationRectangle.y = 0;

  SDL_RenderCopy(m_pRenderer,m_pTexture,&m_sourceRectangle,&m_destinationRectangle);*/
  return true;
}

void Game::update()
{
  m_currentFrame = ( (SDL_GetTicks() / 100) % 6);
  /*m_sourceRectangle.x = 128 * ( (SDL_GetTicks() / 100) % 6);
  m_destinationRectangle.x = (SDL_GetTicks()/15);*/
}

void Game::render()
{
  SDL_RenderClear(m_pRenderer);   // 랜더 삭제 
 // SDL_RenderCopy(m_pRenderer,m_pTexture,&m_sourceRectangle,&m_destinationRectangle); // 랜더 
  m_textureManager.draw("animate", 0, 0, 128, 82, m_pRenderer);
  m_textureManager.drawFrame("animate", 100, 100, 128, 82, 0, m_currentFrame, m_pRenderer);

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