#include "catch.hpp"
#include "TestEntity.h"
#include "TestComponent.h"
#include "TestMessage.h"
#include "TestUpdate.h"

TEST_CASE("Test Entity/Component", "[entity]")
{
	TestEntity e;
	TestComponent *c1 = new TestComponent();
	TestComponent *c2 = new TestComponent();
	e.addComponent(c1);
	e.addComponent(c2);

	SECTION("Test messaging", "[message][component]")
	{
		e.transmit(TestMessage(UPDATE, "A message"));
		REQUIRE(c1->received == "A message");
		REQUIRE(c2->received == "A message");
	}

	SECTION("Test update", "[update][component]")
	{
		e.update(TestUpdate("An update"));
		REQUIRE(c1->updateMsg == "An update");
		REQUIRE(c2->updateMsg == "An update");
	}
}
