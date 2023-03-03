#ifndef __STAGE_HPP__
#define __STAGE_HPP__


#include "raylib.h"
#include "sprite.hpp"
#include "library_of_textures.hpp"


namespace Example
{
    class ViewStage
    {
    public:
        static const int CELL_SIZE = 64;

        ViewStage();

        void DrawAt(const Vector2& position, const TextureLibrary& texture_library) const;
        
    private:
    };
}


#endif  // __STAGE_HPP__