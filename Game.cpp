#include "Game.h"
#include "SDL_image.h"
#include "TextureManager.h"

bool Game::init(const char *title, int xpos, int ypos, int width, int height, int flags) {
  if ( !TheTextureMnager::Instance()->load("Assets/animate-alpha.png", "animate", m_pRenderer))
  {
    return false;
  }
  m_textureManager. load("Assets/animate-alpha.png", "animate", m_pRenderer);
  if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
    if (m_pWindow != 0) {
      m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

      if (m_pRenderer != 0) {
        SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255); 
      } else {
        return false; // 랜더러 생성 실패
      }
    } else {
      return false; // 윈도우 생설 실패 l
    }
  } else {
    return false; // SDL 초기화 실패
  }

  m_bRunning = true;

  SDL_Surface* pTempSurface = IMG_Load("Assets/animate-alpha.png");
  m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
  SDL_FreeSurface(pTempSurface);

  m_sourceRectangle.w = 128;
  m_sourceRectangle.h = 82;

  m_destinationRectangle.w = m_sourceRectangle.w;
  m_destinationRectangle.h = m_sourceRectangle.h;

  m_destinationRectangle.x = m_sourceRectangle.x = 0;
  m_destinationRectangle.y = m_sourceRectangle.y = 0;


  return true;
}

void Game::update()
{
  m_sourceRectangle.x = 128 * ( (SDL_GetTicks() / 100) % 6);
  m_currentFrame = ( (SDL_GetTicks() / 100) % 6);
}

void Game::render()
{
  SDL_RenderClear(m_pRenderer);  
  SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
  SDL_RenderPresent(m_pRenderer); 

  m_textureManager.draw("animate", 0,0, 128, 82, m_pRenderer);
  m_textureManager.drawFrame("animate", 100,100, 128, 82, 0, m_currentFrame, m_pRenderer);

  TheTextureMnager::Instance()->draw("animate", 0,0, 128, 82, m_pRenderer);

  TheTextureMnager::Instance()->drawFrame("animate", 100,100, 128, 82, 0, m_currentFrame, m_pRenderer);
}

bool Game::running()
{ 
   return m_bRunning; 
}

void Game::handleEvents() 
{
  SDL_Event event;
  if (SDL_PollEvent(&event)) {
    switch (event.type) {
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

//그려줄 색 지정
//이벤트?? 처리를 위함 함수
//종료 버튼을 누르면 윈도우(화면), 코드, 루프 중지

//Texture?? 생성 (Assets를 불러와 surface 로 부터 Texture를 생성??)후 더이상 실행할 필요 없으니 또 실행하지 않도록 처리
//원본상자(기본적인 Texture 전체) 대상상자(윈도우의 부분)
//SDL_QueryTexture함수를 사용하여 Texture의 크기 구함
//보여주고 싶은 부분을 정하기 위해 좌표의 기준점을 정함
//render 함수에 Texture 그리는 부분 추가