#include "catch.hpp"
#include "TestEntity.h"
#include "TestComponent.h"
#include "TestMessage.h"
#include "TestUpdate.h"
#include "TestUpdateComponent.h"
#include "TestChangeComponent.h"

TEST_CASE("Test Entity/Component", "[entity]")
{
	TestEntity e;

	SECTION("Test messaging", "[message][component]")
	{

		TestComponent *c1 = new TestComponent();
		TestComponent *c2 = new TestComponent();
		e.addComponent(c1);
		e.addComponent(c2);

		REQUIRE(c1->received == "");
		REQUIRE(c2->received == "");

		e.transmit(TestMessage(UPDATE, "A message"));
		REQUIRE(c1->received == "A message");
		REQUIRE(c2->received == "A message");
	}

	SECTION("Test update", "[update][component]")
	{
		TestComponent *c1 = new TestComponent();
		TestComponent *c2 = new TestComponent();
		e.addComponent(c1);
		e.addComponent(c2);

		REQUIRE(c1->updateMsg == "");
		REQUIRE(c2->updateMsg == "");

		e.update(TestUpdate("An update"));
		REQUIRE(c1->updateMsg == "An update");
		REQUIRE(c2->updateMsg == "An update");
	}

	SECTION("Test filtered message", "[message][component]")
	{
		TestComponent *c = new TestComponent();
		TestUpdateComponent *uc = new TestUpdateComponent();
		TestChangeComponent *cc = new TestChangeComponent();

		e.addComponent(c);
		e.addComponent(uc);
		e.addComponent(cc);

		REQUIRE(c->received == "");
		REQUIRE(uc->received == "");
		REQUIRE(cc->received == "");

		e.transmit(TestMessage(UPDATE, "An update message"));
		REQUIRE(c->received == "An update message");
		REQUIRE(uc->received == "An update message");
		REQUIRE(cc->received == "");

		e.transmit(TestMessage(CHANGE, "A change message"));
		REQUIRE(c->received == "A change message");
		REQUIRE(uc->received == "An update message");
		REQUIRE(cc->received == "A change message");
	}
}
