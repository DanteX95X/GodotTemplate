#ifndef HELLO_H
#define HELLO_H

#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/viewport.hpp>

#include <godot_cpp/core/binder_common.hpp>
#include "../godot-cpp/gen/include/godot_cpp/classes/node2d.hpp"

namespace test
{
	class Hello : public godot::Node2D
	{
		GDCLASS(Hello, godot::Node2D)

	public:
		static void _bind_methods();

		Hello();
		~Hello();

		void Signal(godot::Node* node, godot::Vector2 position);

		void _ready() override;
		void _process(double delta) override;

	private:
		bool done;
		double time{};
	};
}

#endif // HELLO_H
