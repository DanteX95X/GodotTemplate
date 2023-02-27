#include "hello.h"
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/engine.hpp>
//#include <utility_functions.hpp>

//#include "test/move_around.h"

namespace test
{
	void Hello::_bind_methods()
	{
//		godot::register_method("_ready", &Hello::_ready);
//		godot::register_method("_process", &Hello::_process);
//		godot::register_method("Signal", &Hello::Signal);
//		godot::ClassDB::bind_virtual_method("Hello", "_ready", &Hello::_ready);
//		godot::ClassDB::bind_virtual_method("Hello", "_process", &Hello::_process);
	}

	Hello::Hello()
	{
		godot::UtilityFunctions::print("Hello World!");
	}

	Hello::~Hello()
	{
	}

//	void Hello::Signal(godot::Node* node, godot::Vector2 position)
//	{
//		godot::Godot::print("processing signal");
//		queue_free();
//	}

	void Hello::_ready()
	{
		godot::UtilityFunctions::print("Ready");
		godot::UtilityFunctions::print("Testing hot reload");
		time = 0;
//		godot::Node* node = get_node("Sprite");
//		node->connect("done", this, "Signal");
	}

	void Hello::_process(double delta)
	{
		if(!godot::Engine::get_singleton()->is_editor_hint())
		{
			time += delta;
			godot::UtilityFunctions::print("Process: ", time);
		}
	}


}
