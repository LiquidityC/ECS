#include "TestMessage.h"

TestMessage::TestMessage(MessageType t, const std::string m) :
	type(t),
	message(m)
{
}

MessageType TestMessage::getType() const
{
	return type;
}

std::string TestMessage::getMessage() const
{
	return message;
}
