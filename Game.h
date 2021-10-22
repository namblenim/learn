
#ifndef __Game__
#define __Game__
#include "SDL.h"

//TextureManager m_TextureManager;
int m_currentFrame;

class Game {
public:
    Game() {}
    ~Game() {}

    bool init(const char *title, int xpos, int ypos, int width, int height, int flags);
    void render();
    void update(); 
    bool running();
    void handleEvents();
    void clean();

private:
    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    bool m_bRunning;

    SDL_Texture* m_pTexture; 
    // 원본 사각형
    SDL_Rect m_sourceRectangle;	 
    // 대상 사각형
    SDL_Rect m_destinationRectangle;
};
#endif /* defined(__Game__) */



//Game 클래스
//기본적인 루프 함수들을 Game 클래스에서 처리
//전처리기??

//Assets의 사진을 화면에 띄우기 위해 좌표와 높이, 넓이를 지정하여 함수 작성
