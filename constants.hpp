#ifndef __CONSTANTS_HPP__
#define __CONSTANTS_HPP__


namespace Example
{
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 600;

    const int TEXTURE_LIBRARY_CAPACITY = 128;

    const int STAGE_CELL_SIZE = 64;
    const int STAGE_MAX_WIDTH = WINDOW_WIDTH / STAGE_CELL_SIZE;
    const int STAGE_MAX_HEIGHT = WINDOW_HEIGHT / STAGE_CELL_SIZE;

    const int STAGE_CELL_CAPACITY = 10;

    typedef enum StageCellType
    {
        NONE,
        EMPTY,
        WALL
    } StageCellType;

    typedef enum StageCellObjectType
    {
        NONE,
        PLAYER,
        DOOR_KEY,
        DOOR,
        STAIRS_UP,
        STAIRS_DOWN
    };
}


#endif  // __CONSTANTS_HPP__