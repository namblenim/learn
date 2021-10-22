#ifndef __TextureManager__
#define __TextureManager__
#include "SDL.h"

class TextureManager
{
  private:
    static TextureManager * s_pInstance;

    TextureManager() {}
    ~TextureManager() {}

    bool load(std::string id, SDL_Renderer* pRenderer);

    void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip = SDL_Flip_NONE);

    void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, int SDL_Renderer* pRenderer, SDL_RendererFlip = SDL_Flip_NONE);

  private:
    std::map<std::string, SDL_Texture* m_textureMap;

  public:
    static TextureManager* Instance()
    {
      if (s_pInstance == 0)
          s_pInstance = new TextureManager();
      return s_pInstance;

      typedef TextureManager TheTextureManager;
    }
};