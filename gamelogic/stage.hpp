#ifndef __STAGE_HPP__
#define __STAGE_HPP__


#include "stage_cell.hpp"


namespace Example
{
    class Stage
    {
    public:
        static const int WIDTH = 12;
        static const int HEIGHT = 9;

        StageCell &GetCellAt(const int &x, const int &y);
    
    private:
        static const int _CELLS_COUNT = Stage::WIDTH * Stage::HEIGHT;
        StageCell _cells[Stage::_CELLS_COUNT];

        // Специальная версия ячейки, которая используется как заглушка
        // для обозначения ячеек за пределами уровня. Это своего рода
        // аналог nullptr при возврате ссылки на несуществующий объект
        // методом Stage::GetCellAt.
        //
        // В дальнейшем можно перейти на более
        // изящный код: будет базовый класс для ячеек и одним
        // из производных классов будет ячейка-пустота.
        static StageCell _out_of_stage_cell;

        bool _IsCoordsCorrect(const int &x, const int &y) const;
        StageCell &_GetOutOfStageCell();
    };
}


#endif  // __STAGE_HPP__