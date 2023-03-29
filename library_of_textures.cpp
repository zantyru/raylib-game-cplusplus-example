#include <string>
#include "raylib.h"
#include "constants.hpp"
#include "library_of_textures.hpp"


namespace Example
{
    TextureLibrary::TextureLibrary()
    {
        for (int idx = 0; idx < TextureLibrary::CAPACITY; idx++)
        {
            this->_is_texture_loaded[idx] = false;
        }

        ::Image image = ::GenImageColor(
            TextureLibrary::FALLBACK_TEXTURE_WIDTH,
            TextureLibrary::FALLBACK_TEXTURE_HEIGHT,
            ::RED
        );
        this->_fallback_texture = ::LoadTextureFromImage(image);
        ::UnloadImage(image);
    }

    TextureLibrary::~TextureLibrary()
    {
        for (int idx = 0; idx < TextureLibrary::CAPACITY; idx++)
        {
            if (this->_is_texture_loaded[idx])
            {
                ::UnloadTexture(this->_textures[idx]);
            }
        }

        ::UnloadTexture(this->_fallback_texture);
    }

    void TextureLibrary::LoadTexture(const int& id, const std::string& filename)
    {
        // При некорректном id досрочный выход
        if (!this->_IsIdValid(id)) return;

        // Если файла не существует, то досрочный выход
        if (!::FileExists(filename.c_str())) return;

        // Если по указанному id уже загружена текстура, то выгружаем её
        this->UnloadTexture(id);

        // Загрузка
        this->_textures[id] = ::LoadTexture(filename.c_str());
        this->_is_texture_loaded[id] = true;
    }

    void TextureLibrary::UnloadTexture(const int& id)
    {
        // При некорректном id досрочный выход
        if (!this->_IsIdValid(id)) return;

        ::UnloadTexture(this->_textures[id]);
        this->_is_texture_loaded[id] = false;
    }

    const ::Texture2D& TextureLibrary::GetTexture(const int& id) const
    {
        // При некорректном id возвращаем текстуру-заглушку
        if (!this->_IsIdValid(id)) return this->_fallback_texture;

        // Если текстура не загружена, то возвращаем текстуру-заглушку
        if (!this->_is_texture_loaded[id]) return this->_fallback_texture;

        return this->_textures[id];
    }

    bool TextureLibrary::_IsIdValid(const int& id) const
    {
        return id >= 0 && id < TextureLibrary::CAPACITY;
    }
}
