
#include "constants.hpp"
#include "stage_cell_object.hpp"


namespace Example
{
	StageCellObjectType StageCellObject::GetType() const
	{
		return this->_type;
	}

	bool StageCellObject::IsPickable() const
	{
		return this->_is_pickupable;
	}

	bool StageCellObject::IsBlocker() const
	{
		return this->_is_blocker;
	}

#include "constants.hpp"
#include "stage_cell_object.hpp"


namespace Example
{
	StageCellObjectType StageCellObject::GetType() const
	{
		return this->_type;
	}

	bool StageCellObject::IsPickable() const
	{
		return this->_is_pickupable;
	}

	bool StageCellObject::IsBlocker() const
	{
		return this->_is_blocker;
	}
}