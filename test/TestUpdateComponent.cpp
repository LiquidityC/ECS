#include "TestUpdateComponent.h"

void TestUpdateComponent::update(const TestUpdate& update)
{
	updateMsg = update.getUpdateMsg();
}

void TestUpdateComponent::receive(const TestMessage& message)
{
	if (message.getType() == UPDATE)
		received = message.getMessage();
}
