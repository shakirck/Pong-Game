#include <iostream>
#include "raylib.h"

struct  Ball{
   float x , y ;
   float speedx  , speedY;
   float radius;
   void Draw(){

       DrawCircle( x, y, radius,BLACK);
   }
};
struct  Paddle{
    float x , y ;
    float speed ;
    float height ;
    float width ;

    void Draw(){
        DrawRectangleRec(GetRect(),BLACK);
    }
    Rectangle GetRect(){
       return Rectangle{  x-width/2,y-width/2  , width , height };
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    InitWindow(800 , 600 , "pong");
    SetWindowState(FLAG_VSYNC_HINT);
    Ball ball;
    ball.x= GetScreenWidth()/2 ;
    ball.y= GetScreenHeight()/2;
    ball.radius  = 5;
    ball.speedx= 120;
   ball.speedY= 200;
    Paddle leftPaddle ;
    leftPaddle.x=  50;
    leftPaddle.y = GetScreenHeight()/2 ;
    leftPaddle.height = 100;
    leftPaddle.width = 10;
    leftPaddle.speed=230;
    Paddle rightPaddle;
    rightPaddle.x = GetScreenWidth()-50;
    rightPaddle.y = GetScreenHeight()/2;
    rightPaddle.height = 100;
    rightPaddle.width  = 10;
    rightPaddle.speed=230;
    const char* winner = nullptr;
    while(!WindowShouldClose()){


       ball.x +=ball.speedx* GetFrameTime();
       ball.y+=ball.speedY* GetFrameTime();
       if(ball.y<0){
           ball.speedY*=-1;
       }
       if(ball.y>GetScreenHeight()){
           ball.speedY*=-1;
       }
        if(IsKeyDown(KEY_W)){
            leftPaddle.y -= leftPaddle.speed*GetFrameTime();
            std::cout << "key pressed W" << std::endl;
        }
        if(IsKeyDown(KEY_S)){
            leftPaddle.y += leftPaddle.speed*GetFrameTime();
            std::cout << "key pressed S" << std::endl;
        }
        if(IsKeyDown(KEY_UP)){
           rightPaddle.y -= rightPaddle.speed*GetFrameTime();
        }
        if(IsKeyDown(KEY_DOWN)){
           rightPaddle.y += rightPaddle.speed*GetFrameTime();
        }

        if(CheckCollisionCircleRec(Vector2{ball.x , ball.y} , ball.radius ,leftPaddle.GetRect())){
            ball.speedx *=-1.1f;
        }
        if(CheckCollisionCircleRec(Vector2{ball.x , ball.y} , ball.radius ,rightPaddle.GetRect())){
            ball.speedx *=-1.1f;
        }
        if(ball.x < 0)
            winner = "Player Right Win";
       if(ball.x >GetScreenWidth())
            winner = "Player Left Win";
        BeginDrawing();
        ClearBackground(WHITE);
        ball.Draw();

        leftPaddle.Draw();
        rightPaddle.Draw();
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
