#pragma once

#include "../src/ECS.h"
#include "TestUpdate.h"
#include "TestMessage.h"

class TestComponent : public ECS::Component<TestUpdate, TestMessage>
{
	public:
		std::string updateMsg;
		std::string received;

		void update(const TestUpdate&) override;

		void receive(const TestMessage&) override;
};
