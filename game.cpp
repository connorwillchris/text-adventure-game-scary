#include <cstdio>
#include <raylib.h>
#include <math.h>

#include "game.hpp"

Game::Game() {
    xPos = -1;
    yPos = 0;
}

Game::~Game() {}

void Game::init() {
    InitWindow(screenWidth, screenHeight, "Text Adventure Game Scary");
    texture = LoadTexture("assets/terminal.png");
    screen = (char*)MemAlloc(width * height);
}

void Game::deinit() {
    MemFree(screen);
    screen = nullptr;

    UnloadTexture(texture);
    CloseWindow();
}

void Game::draw() {
    int x, y;
    BeginDrawing();

    for (int i = 0; i < width * height; i++) {
        xPos = i % width;
        yPos = floor(i / width);
        drawChar(screen[i], WHITE);
    }

    EndDrawing();
}

void Game::drawChar(int c, Color color) {
    int this_x = c % 16;
    int this_y = floor((double)c / 16);

    DrawTextureRec(
        texture,
        (Rectangle) {
            .x = static_cast<float>(charSize * this_x),
            .y = static_cast<float>(charSize * this_y),
            .width = static_cast<float>(charSize),
            .height = static_cast<float>(charSize),
        },
        (Vector2) {
            .x = static_cast<float>(xPos * charSize),
            .y = static_cast<float>(yPos * charSize),
        },
        color
    );
}

void Game::update() {
    xPos = 0, yPos = 1;
    drawChar('A', GREEN);
    xPos = 1, yPos = 1;
    drawChar('B', WHITE);
}

void Game::drawString(std::string s) {
    for (int i = 0; i < s.length(); i++) {
        screen[xPos + (width * yPos)] = (char)s[i];

        xPos++;
        if (xPos >= width) {
            xPos = 0;
            yPos++;
        }
    }
}

void Game::initScreen() {
    xPos = 0, yPos = 0;
    drawString("WELCOME TO THE GAME!");
}
