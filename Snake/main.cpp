//
//  main.cpp
//  Snake
//
//  Created by Cedric on 2020/4/22.
//  Copyright © 2020 Cedric. All rights reserved.
//

#include "Snake.hpp"

using namespace std;

int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cerr << "SDL Init Failed:" << SDL_GetError() << endl;
        return -1;
    }//创建视频
    SDL_Window* gWindow = SDL_CreateWindow("Snake", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);//创建窗口
    SDL_Renderer* gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);//创建渲染器，使用硬件加速
    if (gRenderer == NULL)
    {
        cerr << "Renderer init failed! SDL Error:" << SDL_GetError() << endl;
        return -1;
    }
    else
    {
        SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);//初始化渲染器颜色
    }
    Snake snake;
    SDL_Event event;
    bool running = true;
    while (running)
    {
        while (SDL_PollEvent(&event) != 0)//0代表没有可处理事件
        {
            if (event.key.keysym.sym == SDLK_ESCAPE)//ESC终止程序
            {
                running = false;
            }
            else if (event.key.keysym.sym == SDLK_RETURN)//死亡后回车重新开始
            {
                if (snake.IsDead())
                {
                    snake.Restart();
                }
            }
        }
        snake.Update(event);
        SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
        SDL_RenderClear(gRenderer);
        snake.Render(gRenderer);
        SDL_RenderPresent(gRenderer);
    }
    return 0;
}

