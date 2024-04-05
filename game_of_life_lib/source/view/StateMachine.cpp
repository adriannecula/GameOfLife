#include <memory>

class State;
using StateRef = std::unique_ptr<State> ;
class StateMachine
{
public:
    StateMachine() = default;
    ~StateMachine() = default;
    void AddState(StateRef newState, bool isReplacing = true);
    void RemoveState();
    void ProcessStateChangess();

    StateRef& GetActiveState;

};