#pragma once

// tile properties
constexpr int TILE_W = 32;
constexpr int TILE_H = 32;

// player (should this be moved to PlayerData?)
constexpr float PLAYER_H_SPEED = 2.f;
constexpr float PLAYER_V_SPEED = PLAYER_H_SPEED;

// window properties
constexpr const char WINDOW_NAME[] = "Farming";
constexpr int WINDOW_W = 1024;
constexpr int WINDOW_H = 768;
constexpr int NUM_COLUMNS_IN_WINDOW = WINDOW_W / TILE_W;
constexpr int NUM_ROWS_IN_WINDOW = WINDOW_H / TILE_H;

// game object defaults
constexpr int DEFAULT_POS_X = 100;
constexpr int DEFAULT_POS_Y = 150;

// normalized unit vector lenght
constexpr float NORMALIZED_UNIT_VECTOR_LENGTH = 0.707f;
