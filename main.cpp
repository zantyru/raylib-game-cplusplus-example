#include "raylib.h"
#include "constants.hpp"
#include "library_of_textures.hpp"
#include "sprite.hpp"


int main()
{    
    InitWindow(Example::WINDOW_WIDTH, Example::WINDOW_HEIGHT, "raylib and c++ example");
    SetTargetFPS(60);

    Example::TextureLibrary texture_library;
    texture_library.LoadTexture(12, "texture.png");
    
    Example::Sprite sprite(texture_library, 12, Vector2{20.0f, 20.0f});
    Vector2 v;
    v.x = 0.0f;
    v.y = 0.0f;
    
    // "Прогрев" конвейера отрисовки  //@HACK
    Texture2D texture = LoadTexture("texture.png");
    BeginDrawing();
    DrawTexture(texture, 10, 200, WHITE);
    EndDrawing();
    UnloadTexture(texture);
    

    // Основной цикл
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        sprite.DrawAt(v);
        EndDrawing();
    }
    

    CloseWindow();
    return 0;
}


// Всё в одном файле, чтобы компилировать без собственного make-файла
// #include "sprite.cpp"