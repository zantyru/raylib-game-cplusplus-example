#include "stage_cell.hpp"


namespace Example
{
    StageCell::StageCell()
    {
        this->_floor = StageCell::Floor::NONE;
        this->_items_count = 0;

        for (int idx = 0; idx < StageCell::CAPACITY; idx++)
        {
            this->_items[idx] = StageCell::Object::NONE;
        }
    }

    void StageCell::SetFloor(const StageCell::Floor &floor)
    {
        this->_floor = floor;

        //@NOTE Обработка случая, когда непустой ячейке выставляется
        // значение пола NONE, отдано классу ответственному за
        // реализацию игровых механик (правил игры). То есть здесь
        // с объектами ничего не происходит, они остаются "висеть"
        // над пустотой.
    }

    const StageCell::Floor &StageCell::GetFloor() const
    {
        return this->_floor;
    }

    bool StageCell::IsVoid() const
    {
        return this->_floor == StageCell::Floor::NONE;
    }

    bool StageCell::PushObject(const StageCell::Object &item)
    {
        if (this->IsFullfilled()) return false;
        if (this->IsVoid()) return false;
        this->_items[this->_items_count] = item;
        this->_items_count++;
        return true;
    }

    const StageCell::Object &StageCell::PopObjectAt(const int &idx)
    {
        if (!this->_is_index_correct(idx)) return StageCell::Object::NONE;

        StageCell::Object item = this->_items[idx];
        for (int jdx = idx; jdx < this->_items_count - 1; jdx++)
        {
            this->_items[jdx] = this->_items[jdx + 1];
        }
        this->_items[this->_items_count - 1] = StageCell::Object::NONE;
        this->_items_count--;

        return item;
    }

    const StageCell::Object &StageCell::PopObject()
    {
        if (this->IsEmpty()) return StageCell::Object::NONE;

        StageCell::Object item = this->_items[this->_items_count - 1];
        this->_items[this->_items_count - 1] = StageCell::Object::NONE;
        this->_items_count--;

        return item;
    }

    const StageCell::Object &StageCell::PeekObjectAt(const int& idx) const
    {
        if (!this->_is_index_correct(idx)) return StageCell::Object::NONE;
        return this->_items[idx];
    }

    bool StageCell::IsFullfilled() const
    {
        return this->_items_count == StageCell::CAPACITY;
    }

    bool StageCell::IsEmpty() const
    {
        return this->_items_count == 0;
    }

    bool StageCell::_is_index_correct(const int &idx) const
    {
        return idx >= 0 && idx < StageCell::CAPACITY;
    }
}