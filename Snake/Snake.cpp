//
//  Snake.cpp
//  Snake
//
//  Created by Cedric on 2020/4/22.
//  Copyright © 2020 Cedric. All rights reserved.
//

#include "Snake.hpp"

SnakeBody::SnakeBody(unsigned x,unsigned y)
{
    this->x = x;
    this->y = y;
}

Food::Food()
{
    Respawn();
}

void Food::Respawn()
{
    x = rand()%(CELL_WIDTH-2)+1;//获取随机位置
    y = rand()%(CELL_WIDTH-2)+1;
}

Snake::Snake()
{
    Restart();
}

Snake::~Snake()
{
    body.clear();
}

void Snake::Restart()
{
    body.clear();
    for(unsigned i = 0;i < START_LENGTH;i ++)
    {
        AddBody(START_X - i,START_Y);
    }
    direction = GO_RIGHT;
    time = 0;
    timeout = 100;
    dead = false;
}

void Snake::AddBody(unsigned x, unsigned y)
{
    SnakeBody b(x,y);
    body.push_back(b);
}

void Snake::Update(SDL_Event &event)
{
    if(dead)
    {
        return;
    }
    UpdateInputControl(event);
    time ++;
    if(time < timeout)
    {
        return;
    }
    time = 0;
    if(CheckWallCollision() || CheckSelfCollision())
    {
        dead = true;
        return;
    }
    if(CheckFoodCollision())
    {
        food.Respawn();
        bool Check = true;//检查食物与蛇身是否重合
        while(Check)
        {
            Check = false;
            for(unsigned i = 0;i < body.size();i ++)
            {
                if(food.x == body[i].x && food.y == body[i].y)
                {
                    food.Respawn();
                    break;
                }
            }
        }
    }
    else{
        body.pop_back();
    }
    MoveSnake();
}

void Snake::UpdateInputControl(SDL_Event &event)
{
    if(event.type == SDL_KEYDOWN)
    {
        switch(event.key.keysym.sym)
        {
            case SDLK_UP:
            {
                if(direction != GO_DOWN) direction = GO_UP;
                break;
            }
            case SDLK_DOWN:
            {
                if(direction != GO_UP) direction = GO_DOWN;
                break;
            }
            case SDLK_LEFT:
            {
                if(direction != GO_RIGHT) direction = GO_LEFT;
                break;
            }
            case SDLK_RIGHT:
            {
                if(direction != GO_LEFT) direction = GO_RIGHT;
                break;
            }
        }
    }
}

bool Snake::CheckWallCollision()
{
    unsigned headx = body[0].x;
    unsigned heady = body[0].y;
    bool Check = (headx == 0 || headx ==CELL_WIDTH || heady == 0 || heady == CELL_HEIGHT);
    return Check;
}

bool Snake::CheckSelfCollision()
{
    unsigned headx = body[0].x;
    unsigned heady = body[0].y;
    for(unsigned i = 1;i < body.size();i ++)
    {
        if(body[i].x == headx && body[i].y == heady)
            return true;
    }
    return false;
}

bool Snake::CheckFoodCollision()
{
    bool Check = (body[0].x == food.x && body[0].y == food.y);
    return Check;
}

void Snake::MoveSnake()
{
    unsigned x,y;
    switch(direction)
    {
        case 0:
        {
            x = body[0].x;
            y = body[0].y-1;
            break;
        }
        case 1:
        {
            x = body[0].x;
            y = body[0].y+1;
            break;
        }
        case 2:
        {
            x = body[0].x-1;
            y = body[0].y;
            break;
        }
        case 3:
        {
            x = body[0].x+1;
            y = body[0].y;
            break;
        }
        default://若direction未初始化，仅可能出现在开始
        {
            x = body[0].x+1;
            y = body[0].y;
            break;
        }
    }
    SnakeBody sb(x,y);
    body.push_front(sb);
}

void Snake::Render(SDL_Renderer *gRenderer)
{
    if(dead)
    {
        return;
    }
    renderrect.w = CELL_SIZE;
    renderrect.h = CELL_SIZE;
    RenderFood(gRenderer);
    RenderSnake(gRenderer);
}

void Snake::RenderFood(SDL_Renderer *gRenderer)
{
    renderrect.x = food.x * CELL_SIZE;
    renderrect.y = food.y * CELL_SIZE;
    SDL_SetRenderDrawColor(gRenderer,129,216,209,255);
    SDL_RenderFillRect(gRenderer,&renderrect);
}

void Snake::RenderSnake(SDL_Renderer *gRenderer)
{
    renderrect.x = body[0].x * CELL_SIZE;
    renderrect.y = body[0].y * CELL_SIZE;
    SDL_SetRenderDrawColor(gRenderer,255,0,255,255);
    SDL_RenderFillRect(gRenderer,&renderrect);
    for(unsigned i = 1;i < body.size(); i ++)
    {
        renderrect.x = body[i].x * CELL_SIZE;
        renderrect.y = body[i].y * CELL_SIZE;
        SDL_SetRenderDrawColor(gRenderer,0,0,255,255);
        SDL_RenderFillRect(gRenderer,&renderrect);
    }
}





