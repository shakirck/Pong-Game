//
// Created by neoito on 15/3/22.
//

#ifndef PONG_BALL_H
#define PONG_BALL_H


#include "raylib.h"

class Ball {
public:
    float x , y ;
    float speedx  , speedY;
    float radius;
    Ball(float x , float y , float radius , float speedx ,  float speedy){
       this->x = x ;
       this->y = y;
       this->radius = radius;
       this->speedY = speedy;
       this->speedx = speedx;
    }
    void Draw(){

        DrawCircle( x, y, radius,BLACK);
    }
};


#endif //PONG_BALL_H
