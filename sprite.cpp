<<<<<<< HEAD
#include <string>
#include "raylib.h"
#include "library_of_textures.hpp"
#include "sprite.hpp"


namespace Example
{   
    Sprite::Sprite(const int& texture_id)
    {
		this->_texture_id = texture_id;
        this->_center_position.x = 0.0f;
        this->_center_position.y = 0.0f;
    }
    
    void Sprite::DrawAt(const Vector2& position, const TextureLibrary& texture_library) const
    {
		const ::Texture2D& texture = texture_library.GetTexture(this->_texture_id);

		Vector2 left_top_corner;
		left_top_corner.x = position.x - (float)(texture.width >> 1);
		left_top_corner.y = position.y - (float)(texture.height >> 1);
       
		DrawTextureV(texture, left_top_corner, WHITE);
    }
=======
#include <string>
#include "raylib.h"
#include "library_of_textures.hpp"
#include "sprite.hpp"


namespace Example
{   
    Sprite::Sprite(const int& texture_id)
    {
		this->_texture_id = texture_id;
        this->_center_position.x = 0.0f;
        this->_center_position.y = 0.0f;
    }
    
    void Sprite::DrawAt(const Vector2& position, const TextureLibrary& texture_library) const
    {
		const ::Texture2D& texture = texture_library.GetTexture(this->_texture_id);

		Vector2 left_top_corner;
		left_top_corner.x = position.x - (float)(texture.width >> 1);
		left_top_corner.y = position.y - (float)(texture.height >> 1);
       
		DrawTextureV(texture, left_top_corner, WHITE);
    }
>>>>>>> b89589e (Первичная заливка файлов проекта)
}