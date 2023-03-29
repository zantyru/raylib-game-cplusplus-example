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
    
    Example::Sprite sprite(texture_library, 12, Vector2{ 20.0f, 20.0f });
    Example::Sprite sprite_error_1(texture_library, 2, Vector2{ 0.0f, 0.0f });
    Example::Sprite sprite_error_2(texture_library, -9, Vector2{ 0.0f, 0.0f });

    // "Прогрев" конвейера отрисовки  //@HACK
    Texture2D texture = LoadTexture("texture.png");
    BeginDrawing();
    DrawTexture(texture, -texture.width, -texture.height, WHITE);
    EndDrawing();
    UnloadTexture(texture);
    

    // Основной цикл
    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        sprite.DrawAt(Vector2{ 0.0f, 0.0f });
        sprite_error_1.DrawAt(Vector2{ 200.0f, 100.0f });
        sprite_error_2.DrawAt(Vector2{ 400.0f, 300.0f });
        EndDrawing();
    }
    

    CloseWindow();
    return 0;
}


// Всё в одном файле, чтобы компилировать без собственного make-файла
// #include "sprite.cpp"