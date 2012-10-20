#pragma once
#include "Player.h"
using namespace osg;
namespace Sokoban
{
	class PlayerPositionUpdater : public NodeCallback
	{
	public:
		PlayerPositionUpdater(ref_ptr<Player> player) : _player(player) {}
		~PlayerPositionUpdater(void);
		void operator()(Node* node, NodeVisitor* nv);
	private:
		ref_ptr<Player> _player;
	};
}

