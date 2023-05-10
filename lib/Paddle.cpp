#include "Paddle.h"

// nothing doing in the constructor and destructor
Paddle::Paddle() { }

const int Lightsaber[10][10]= {
    { 1,1,0,0,0,0,0,0,0,0, },
    { 1,1,1,1,0,0,0,0,0,0, },
    { 0,1,1,0,1,0,0,0,0,0, },
    { 0,1,0,1,1,0,0,0,0,0, },
    { 0,0,1,1,0,1,0,0,0,0, },
    { 0,0,0,0,1,0,1,0,0,0, },
    { 0,0,0,0,0,1,0,1,0,0, },
    { 0,0,0,0,0,0,1,0,1,0, },
    { 0,0,0,0,0,0,0,1,0,1, },
    { 0,0,0,0,0,0,0,0,1,1, },
};

void Paddle::init(int x,int height,int width) {
    printf("Paddle: Init\n");
    _x = x;  // x value on screen is fixed
    _y = HEIGHT/2 - height/2;  // y depends on height of screen and height of paddle
    _height = height;
    _width = width;
    _speed = 2;  // default speed
}

void Paddle::draw(N5110 &lcd) { 
    //printf("Paddle: Draw\n");
    lcd.drawSprite(_x, _y, 10, 10, (int*)Lightsaber);
}

void Paddle::update(UserInput input) {
    printf("Paddle: Update\n");
    _speed = 2;
    // update y value depending on direction of movement
    // North is decrement as origin is at the top-left so decreasing moves up
    if (input.d == N) { _y-=_speed; }
    else if (input.d == S) { _y+=_speed; }

    // check the y origin to ensure that the paddle doesn't go off screen
    if (_y < 1) { _y = 1; }
    if (_y > HEIGHT - _height - 1) { _y = HEIGHT - _height - 1; }
}

Position2D Paddle::get_pos() { return {_x,_y}; }

int Paddle::get_height() { return _height; }

int Paddle::get_width() { return _width; }