#include "stage.hpp"


namespace Example
{
    StageCell Stage::_out_of_stage_cell = StageCell();

    StageCell &Stage::GetCellAt(const int &x, const int &y)
    {
        if (!this->_IsCoordsCorrect(x, y)) return this->_GetOutOfStageCell();

        return this->_cells[y * Stage::WIDTH + x];
    }

    bool Stage::_IsCoordsCorrect(const int &x, const int &y) const
    {
        return x >= 0 && x < Stage::WIDTH && y >= 0 && y < Stage::HEIGHT;
    }

    StageCell &Stage::_GetOutOfStageCell()
    {
        this->_out_of_stage_cell.SetFloor(StageCell::Floor::NONE);
        
        return this->_out_of_stage_cell;
    }
}
