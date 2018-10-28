#include "TestChangeComponent.h"

void TestChangeComponent::update(const TestUpdate& update)
{
	updateMsg = update.getUpdateMsg();
}

void TestChangeComponent::receive(const TestMessage& message)
{
	if (message.getType() == CHANGE)
		received = message.getMessage();
}
