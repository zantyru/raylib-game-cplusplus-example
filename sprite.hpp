#ifndef __SPRITE_HPP__
#define __SPRITE_HPP__


#include "raylib.h"
#include "library_of_textures.hpp"


namespace Example
{
    class Sprite
    {
    public:
        Sprite(const TextureLibrary &texture_library, const int &texture_id, const Vector2 &origin);
        
        void DrawAt(const Vector2 &position, const ::Color &color = ::WHITE) const;
        
    private:
        int _texture_id;
        Vector2 _origin;
        const TextureLibrary &_texture_library;
    };
}


#endif  // __SPRITE_HPP__