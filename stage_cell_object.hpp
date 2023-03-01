#ifndef __STAGE_CELL_OBJECT_HPP__
#define __STAGE_CELL_OBJECT_HPP__


#include "raylib.h"
#include "constants.hpp"
#include "sprite.hpp"


namespace Example
{
    /*
    * Ѕазовый тип любого объекта, который может быть размещЄн в €чейке игрового
    * уровн€.
    */
    class StageCellObject : public Sprite
    {
    public:
        StageCellObject(const int& texture_id)
            : Sprite(texture_id)
            , _type(StageCellObjectType::NONE)
            , _is_pickupable(false)
            , _is_blocker(false)
        {}

        StageCellObjectType GetType() const;
        bool IsPickable() const;
        bool IsBlocker() const;
        
    protected:
        StageCellObjectType _type;
        bool _is_pickupable;
        bool _is_blocker;
    };
}


#endif  // __STAGE_CELL_OBJECT_HPP__