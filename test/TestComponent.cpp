#include "TestComponent.h"

void TestComponent::update(const TestUpdate& update)
{
	updateMsg = update.getUpdateMsg();
}

void TestComponent::receive(const TestMessage& message)
{
	received = message.getMessage();
}
