#pragma once

#include "../src/ECS.h"
#include "TestComponent.h"
#include "TestUpdate.h"
#include "TestMessage.h"

class TestEntity : public ECS::Entity<TestUpdate, TestMessage>
{
};
