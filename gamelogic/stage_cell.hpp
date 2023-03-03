#ifndef __STAGE_CELL_HPP__
#define __STAGE_CELL_HPP__


namespace Example
{
    class StageCell
    {
    public:
        static const int CAPACITY = 10;
                
        enum class Floor  // Это новый (строгий) enum. Появился в C++11 
        {
            NONE,
            STONE,
            WOODEN
        };

        enum class Object
        {
            NONE,
            PLAYER,
            DOOR_KEY,
            DOOR_CLOSED,
            DOOR_OPENED,
            STAIRS_UP,
            STAIRS_DOWN
        };

        StageCell();

        void SetFloor(const StageCell::Floor &floor);
        const StageCell::Floor &GetFloor() const;

        bool IsVoid() const;
        
        bool PushObject(const StageCell::Object &item);
        const StageCell::Object &PopObjectAt(const int &idx);
        const StageCell::Object &PopObject();
        const StageCell::Object &PeekObjectAt(const int& idx) const;

        bool IsFullfilled() const;
        bool IsEmpty() const;

    private:
        int _items_count;
        StageCell::Floor _floor;
        StageCell::Object _items[StageCell::CAPACITY];

        bool _is_index_correct(const int &idx) const;
    };
}


#endif  // __STAGE_CELL_HPP__