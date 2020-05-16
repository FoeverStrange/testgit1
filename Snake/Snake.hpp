//
//  Snake.hpp
//  Snake
//
//  Created by Cedric on 2020/4/22.
//  Copyright © 2020 Cedric. All rights reserved.
//

#ifndef Snake_hpp
#define Snake_hpp

#include<SDL_stdinc.h>
#include <deque>
#include <SDL.h>
#include <iostream>


#define SDL_MAIN_HANDLED

using namespace std;

static const unsigned WINDOW_WIDTH = 800;//窗口宽
static const unsigned WINDOW_HEIGHT = 600;//窗口高
static const unsigned CELL_SIZE = 20;//单位格大小
static const unsigned CELL_WIDTH = WINDOW_WIDTH/CELL_SIZE;//单位格宽
static const unsigned CELL_HEIGHT = WINDOW_HEIGHT/CELL_SIZE;//单位格高
static const unsigned GO_UP = 0;
static const unsigned GO_DOWN = 1;
static const unsigned GO_LEFT = 2;
static const unsigned GO_RIGHT = 3;
static const unsigned START_X = CELL_WIDTH/2;//初始位置
static const unsigned START_Y = CELL_HEIGHT/2;
static const unsigned START_LENGTH = 3;//初始长度

class SnakeBody
{
public:
    unsigned x,y;//蛇身坐标
    SnakeBody(unsigned x,unsigned y);
};

class Food
{
public:
    unsigned x,y;//食物坐标
    Food();
    void Respawn();//建立食物
};

class Snake//游戏基本功能
{
public:
    Snake();
    ~Snake();
    void Restart();//重制为初始状态
    void Update(SDL_Event &event);
    void Render(SDL_Renderer *grenderer);
    inline bool IsDead(){return dead;}
private:
    deque<SnakeBody> body;
    Food food;
    bool dead;//死亡判定
    unsigned direction;
    unsigned time,timeout;
    SDL_Rect renderrect;
    void UpdateInputControl(SDL_Event &event);//更新键盘输入
    void RenderSnake(SDL_Renderer *grenderer);//渲染蛇身
    void RenderFood(SDL_Renderer *gRenderer);//渲染食物
    void AddBody(unsigned x, unsigned y);//增加蛇身
    void MoveSnake();
    bool CheckWallCollision();
    bool CheckSelfCollision();
    bool CheckFoodCollision();
};

#endif /* Snake_hpp */
