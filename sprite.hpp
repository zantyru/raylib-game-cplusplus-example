
#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__


#include "raylib.h"
#include "library_of_textures.hpp"


namespace Example
{
    class Sprite
    {
    public:
        Sprite(const int& texture_id);
        
        void DrawAt(const Vector2& position, const TextureLibrary& texture_library) const;
        
    private:
        Vector2 _center_position;
        int _texture_id;
    };
}


#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__


#include "raylib.h"
#include "library_of_textures.hpp"


namespace Example
{
    class Sprite
    {
    public:
        Sprite(const int& texture_id);
        
        void DrawAt(const Vector2& position, const TextureLibrary& texture_library) const;
        
    private:
        Vector2 _center_position;
        int _texture_id;
    };
}


#endif  // __SPRITE_HPP__