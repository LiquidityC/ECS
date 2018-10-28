#pragma once

#include <string>

enum MessageType
{
	UPDATE,
	CHANGE
};

class TestMessage
{
	private:
		MessageType type;
		std::string message;

	public:
		TestMessage(MessageType t, const std::string m);

		MessageType getType() const;

		std::string getMessage() const;
};
