#include <string>
#include "raylib.h"
#include "library_of_textures.hpp"
#include "sprite.hpp"


namespace Example
{   
    Sprite::Sprite(const TextureLibrary &texture_library, const int &texture_id, const Vector2 &origin) :
        _texture_library(texture_library),
        _texture_id(texture_id),
        _origin(origin)
    { }
    
    void Sprite::DrawAt(const Vector2 &position, const ::Color &color) const
    {
        const ::Texture2D &texture = this->_texture_library.GetTexture(this->_texture_id);

        Vector2 left_top_corner;
        left_top_corner.x = position.x - this->_origin.x;
        left_top_corner.y = position.y - this->_origin.y;
       
        DrawTextureV(texture, left_top_corner, color);
    }
}