/*
기획 파트이며 c언어 공부가 부족하여
c언어 자체의 기초가 부족하여 수업 따라잡기가 불가능 하다고 느껴
적어도 이해한 내용을 주석으로 정리하는 수준으로 하겠습니다
*/
#include "Game.h"
#include "TextureManager.h"
Game* g_game = 0;
TextureManager* t_TextureManager = 0;

int main(int argc, char* argv[])//함수 분리한다는 것의 개념 이해 못함
{
    g_game = new Game();
    g_game->init("Game Class", 100, 100, 640, 480, 0);
    while (g_game->running())
    {
        g_game->handleEvents();
        g_game->update();
        g_game->render();
    }
    g_game->clean();
    return 0;
}




//init 함수: 화면을 생성하고 초기화
//render 함수: 화면에 내용을 그려냄
//main 함수: 게임 루프 -> 게임의 기본적인 시스템을 반복시켜 따로 구동할 필요 없게함
//이 루프를 프레임이며 초당 30 혹은 60번 반복
//init 함수로 화면을 생성 좌표, 넓이, 높이, 색 등 초기화
//render 함수로 화면을 지정한 색으로 지움(사람 눈에는 색이 변한 것으로 보임), 색뿐만 하니라 화면의 크기 위치 등을 변경 가능

//별도의 정의 없이 Game 클래스 불러옴(최상위 클래스로 처리)