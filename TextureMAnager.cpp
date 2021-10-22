#include "TextureManager.h"
#include "SDL.h"
/*#include "IMG_Load.h"
#include "SDL_CreateTextureFromSurface.h"
#include "SDL_FreeSurface.h"*/

TextureManager* TextureManager::s_pInstance = 0;

bool  TextureManager::load (std::string fileName,  std::string id, SDL_Renderer* pRenderer)
{
  SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
  if (pTempSurface == 0)
  {
    return false;
  }
  SDL_Texture* pTecxture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
  SDL_FreeSurface(pTempSurface);
  if (pTecxture != 0)
    {
      m_textureMap[id] = pTecxture;
      return true;
    }
    return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer *pRenderer, SDL_RendererFlip flip)
{
  SDL_Rect srcRect;
  SDL_Rect destRect;

  srcRect.x = 0;
  srcRect.y = 0;
  srcRect.w = destRect.w = width
  srcRect.h = destRect.h = height
  destRect.x = x;
  destRect.y = y;

  SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect, &destRect, 0, 0, flip);
}