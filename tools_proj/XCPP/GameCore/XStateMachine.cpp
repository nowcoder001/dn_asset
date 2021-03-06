#include "XStateMachine.h"
#include "XSkillComponent.h"


XStateMachine::XStateMachine()
{
}


XStateMachine::~XStateMachine()
{
	delete _current;
	delete _pre;
	delete _default;
	delete _skill;

	_skill = NULL;
	_default = NULL;
	_current = NULL;
	_skill = NULL;
}


bool XStateMachine::CanAct(IXStateTransform* next)
{
	return CanAct(next->SelfState());
}

bool XStateMachine::CanAct(XStateDefine state)
{
	return (state == XState_Death) || (InnerPermission(state) && _current->IsPermitted(state));
}


void XStateMachine::Update(float fDeltaT)
{
	_current->StateUpdate(fDeltaT);
	if (_current->IsFinished()) TransferToDefaultState();
}

void XStateMachine::ForceToDefaultState(bool ignoredeath)
{
	if (ignoredeath || _current->SelfState() != XState_Death)
	{
		if (_current != _default)
		{
			_current->Stop(_default->SelfState());
			TransferToDefaultState();
		}
	}
}

void XStateMachine::TransferToDefaultState()
{
	XIdleArgs args;
	DispatchEvent(&args);
}

bool XStateMachine::TransferToState(IXStateTransform* next)
{
	if (CanAct(next))
	{
		if (_current->SelfState() != next->SelfState() || next->SelfState() != XState_Move)
			_current->Stop(next->SelfState());

		_pre = _current;
		_current = next;
		_current->OnGetPermission();
		return true;
	}
	else
	{
		next->OnRejected(_current->SelfState());
		return false;
	}
}

void XStateMachine::SetDefaultState(IXStateTransform* def)
{
	_default = def;
	_current = _default;
	_pre = _default;
}