//
// Created by neoito on 15/3/22.
//

#ifndef PONG_PADDLE_H
#define PONG_PADDLE_H


#include "raylib.h"

class Paddle {
public:
    float x , y ;
    float speed ;
    float height ;
    float width ;

    Paddle(float x, float y, float height, float width, float speed) {
        this->x = x ;
        this->y = y;
        this->speed = speed;
        this->height  = height;
        this->width = width;
    }

    void Draw(){
        DrawRectangleRec(GetRect(),BLACK);
    }
    Rectangle GetRect(){
        return Rectangle{  x-width/2,y-width/2  , width , height };
    }
};


#endif //PONG_PADDLE_H
