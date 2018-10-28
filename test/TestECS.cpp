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
}

TEST_CASE("Test messageing", "[entity][message][component]")
{
	TestEntity e;
	TestComponent *c1 = new TestComponent();
	TestComponent *c2 = new TestComponent();
	e.addComponent(c1);
	e.addComponent(c2);

	e.transmit(TestMessage(UPDATE, "A message"));
	REQUIRE(c1->received == "A message");
	REQUIRE(c2->received == "A message");
}

TEST_CASE("Test update", "[entity][update][component]")
{
	TestEntity e;
	TestComponent *c1 = new TestComponent();
	TestComponent *c2 = new TestComponent();
	e.addComponent(c1);
	e.addComponent(c2);

	e.update(TestUpdate("A message"));
	REQUIRE(c1->updateMsg == "A message");
	REQUIRE(c2->updateMsg == "A message");
}
