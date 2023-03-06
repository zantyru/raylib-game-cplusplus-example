#ifndef __LIBRARY_OF_TEXTURES_HPP__
#define __LIBRARY_OF_TEXTURES_HPP__


#include <string>
#include "raylib.h"
#include "constants.hpp"


namespace Example
{
    class TextureLibrary
    {
    public:

        static const int CAPACITY = 128;

        TextureLibrary();
        ~TextureLibrary();

        void LoadTexture(const int& id, const std::string& filename);
        void UnloadTexture(const int& id);
        const Texture2D& GetTexture(const int& id) const;

    private:
        Texture2D _textures[TextureLibrary::CAPACITY];
        bool _is_texture_loaded[TextureLibrary::CAPACITY];

        bool _IsIdValid(const int& id) const;
    };
}


#endif  // __LIBRARY_OF_TEXTURES_HPP__