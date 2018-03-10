#pragma once
class Action
{
public:
	Action();
	virtual ~Action() = 0;
	virtual void doAction() = 0;
}; 

