#ifndef HELLO_H
#define HELLO_H

#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/viewport.hpp>

#include <godot_cpp/core/binder_common.hpp>

namespace test
{
	class Hello : public godot::Node2D
	{
		GDCLASS(Hello, godot::Node2D)

	public:
		static void _bind_methods();

		Hello();
		~Hello();

		//void Signal(godot::Node* node, godot::Vector2 position);

		void _init();
		void _ready();
		void _process(float delta);

	private:
		bool done;
	};
}

#endif // HELLO_H
