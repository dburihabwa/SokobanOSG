#pragma once
#include "Player.h"
#include "Direction.h"
namespace Sokoban
{
	class PlayerPositionUpdater : public NodeCallback
	{
	public:
		PlayerPositionUpdater(ref_ptr<Player> player) : _player(player) {}
		~PlayerPositionUpdater(void);
		void operator()(Node* node, NodeVisitor* nv);
	private:
		Direction _lastAppliedMove;
		ref_ptr<Player> _player;
	};
}

