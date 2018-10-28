#pragma once

namespace ECS
{
	template<typename T, typename U>
		class Entity;

	template<typename T, typename U>
		class Component
		{
			private:
				Entity<T, U> *entity;

			public:
				Component() { };

				Component(const Component &comp) {
					entity = comp.entity;
				};
				Component& operator=(const Component &comp) {
					entity = comp.entity;
				};
				virtual ~Component() { };

				void setEntity(const Entity<T, U> *e) {
					this->entity = e;
				};

				virtual void update(const T&) = 0;

				virtual void receive(const U&) = 0;
		};
}


