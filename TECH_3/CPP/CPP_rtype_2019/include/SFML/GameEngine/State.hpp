#pragma once

class State
{
private:
    /* data */
public:
    virtual void Init() = 0;
    virtual void HandleInput() = 0;
	virtual void Update(float dt) = 0;
    virtual void Draw(float dt) = 0;
    void Pause() {}
    void Resume() {}

};
