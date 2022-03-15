#include <iostream>
#include "raylib.h"
#include "Ball.h"
#include "Paddle.h"

int main() {
    InitWindow(800 , 600 , "pong");
    SetWindowState(FLAG_VSYNC_HINT);
    Ball *ball = new Ball( GetScreenWidth()/2 , GetScreenHeight()/2  , 5 , 140   , 200);
   Paddle *leftPaddle = new Paddle(50 , GetScreenHeight()/2 , 100 , 10 , 300);

    Paddle *rightPaddle = new Paddle(  GetScreenWidth()-50 ,  GetScreenHeight()/2  ,  100 , 10 , 300) ;
    const char* winner = nullptr;
    while(!WindowShouldClose()){
       ball -> x +=ball -> speedx* GetFrameTime();
       ball-> y+=ball -> speedY* GetFrameTime();
       if(ball -> y<0){
           ball -> speedY*=-1;
       }
       if(ball -> y>GetScreenHeight()){
           ball -> speedY*=-1;
       }
        if(IsKeyDown(KEY_W)){
            leftPaddle -> y -= leftPaddle -> speed*GetFrameTime();
            std::cout << "key pressed W" << std::endl;
        }
        if(IsKeyDown(KEY_S)){
            leftPaddle -> y += leftPaddle -> speed*GetFrameTime();
            std::cout << "key pressed S" << std::endl;
        }
        if(IsKeyDown(KEY_UP)){
           rightPaddle -> y -= rightPaddle -> speed*GetFrameTime();
        }
        if(IsKeyDown(KEY_DOWN)){
           rightPaddle -> y += rightPaddle -> speed*GetFrameTime();
        }

        if(CheckCollisionCircleRec(Vector2{ball->x , ball->y} , ball->radius ,leftPaddle -> GetRect())){
            ball->speedx *=-1.1f;
        }
        if(CheckCollisionCircleRec(Vector2{ball->x , ball->y} , ball->radius ,rightPaddle -> GetRect())){
            ball->speedx *=-1.1f;
        }
        if(ball->x < 0)
            winner = "Player Right Win";
       if(ball->x >GetScreenWidth())
            winner = "Player Left Win";
        BeginDrawing();
        ClearBackground(WHITE);
        ball->Draw();

        leftPaddle -> Draw();
        rightPaddle -> Draw();
        if(winner){
            int textWidth = MeasureText(winner , 60);
            DrawText(winner ,(GetScreenWidth() - textWidth)/2 ,GetScreenHeight()/2-30, 60 , GREEN);
            std::cout << GetScreenHeight()/2 << " " << GetScreenWidth()/2 << std::endl <<textWidth << std::endl;
        }

        DrawFPS(10,10);
        EndDrawing();

    }
    CloseWindow();
    return 0;
}
