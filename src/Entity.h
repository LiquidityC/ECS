#pragma once

#include <vector>
#include "Component.h"

namespace ECS
{
	template <typename T, typename U>
		class Entity
		{
			protected:
				std::vector<Component<T, U>*> components;

			public:
				Entity() { };

				Entity(const Entity<T, U>& entity) {
					components = entity.components;
				};

				Entity& operator=(const Entity<T, U>& entity) {
					while (!components.is_empty()) {
						delete components.pop_back();
					}
					components = entity.components;
				};

				virtual ~Entity() {
					while (!components.empty()) {
						delete components.back();
						components.pop_back();
					}
				};

				void addComponent(Component<T, U> *comp) {
					components.push_back(comp);
					comp->setEntity(this);
				};

				void transmit(const U& msg) {
					for (auto &comp : components) {
						comp->receive(msg);
					}
				}

				void update(const T& t) {
					for (auto &comp : components) {
						comp->update(t);
					}
				}
		};
}
