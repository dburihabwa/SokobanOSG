#pragma once
#include "GUIButton.h"
#include "../Logic/Direction.h"

namespace Sokoban {
	///<summary>
	/// Direction Button is a object used to pilot the character through the puzzle by using your mouse.
	///</summary>
    class DirectionButton :
        public Sokoban::GUIButton
    {
    public:
		///	<summary>
		///		Usual DirectionButton Constructor receiving space coordinates and a logical Direction
		///		<param>x</param>
		///	</summary>
        DirectionButton(int x, int y, int z, Direction direction);
		osg::ref_ptr<osg::Node> createNode();
        Type getType();
		///	<summary>
		///		Returns the logical direction of the button
		///	</summary>*
        Direction getDirection() const;
    private:
        Direction _direction;
    };
};

