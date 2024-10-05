#pragma once

#include <raylib.h>
#include <string>

class Game {

public:
    Game();
    ~Game();
    void init();
    void deinit();
    void draw();
    void update();
    void initScreen();

    void drawString(std::string s);

private:
    const int charSize = 8;
    const int width = 80;
    const int height = 60;
    const int screenWidth = width * charSize;
    const int screenHeight = height * charSize;
    char* screen = nullptr;
    Texture2D texture;
    int xPos, yPos;

    void drawChar(int c, Color color);

};