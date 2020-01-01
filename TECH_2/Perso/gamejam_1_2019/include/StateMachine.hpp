#pragma once

#include <memory>
#include <stack>
#include "State.hpp"

namespace Gengine
{
	typedef std::unique_ptr<State> StateRef;

	class StateMachine {
		public:
			StateMachine(){}
			~StateMachine(){}
			void AddState(StateRef newState, bool isReplacing = true);
			void RemoveState();
			void ProcessStateChanges();
			StateRef &GetActiveState();
		private:
			std::stack<StateRef> _states;
			StateRef _new_state;
			bool _isRemoving;
			bool _isAdding;
			bool _isReplacing;
	};
}