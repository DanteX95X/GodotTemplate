#include "move_around.h"
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/object.hpp>

namespace test
{
	void MoveAround::_bind_methods()
	{
		godot::ClassDB::bind_method(godot::D_METHOD("setSpeed"), &MoveAround::setSpeed);
		godot::ClassDB::bind_method(godot::D_METHOD("getSpeed"), &MoveAround::getSpeed);
		ADD_PROPERTY(godot::PropertyInfo(godot::Variant::FLOAT, "speed"), "setSpeed", "getSpeed");

		godot::ClassDB::bind_method(godot::D_METHOD("setAmplitude"), &MoveAround::setAmplitude);
		godot::ClassDB::bind_method(godot::D_METHOD("getAmplitude"), &MoveAround::getAmplitude);
		ADD_PROPERTY(godot::PropertyInfo(godot::Variant::FLOAT, "amplitude"), "setAmplitude", "getAmplitude");

		ADD_SIGNAL(godot::MethodInfo("done",
									 godot::PropertyInfo(godot::Variant::OBJECT, "node"),
									 godot::PropertyInfo(godot::Variant::VECTOR2, "position")));
	}

	MoveAround::MoveAround()
	{
	}

	MoveAround::~MoveAround()
	{
	}

	void MoveAround::_init()
	{
	}

	void MoveAround::_process(double delta)
	{
		if(godot::Engine::get_singleton()->is_editor_hint())
		{
			return;
		}

		timePassed += speed * delta;
		godot::Vector2 position = godot::Vector2(amplitude + (amplitude * sin(timePassed * 2.0)),
												 amplitude + (amplitude * cos(timePassed * 1.5)));
		set_position(position);

		if(timePassed > 10)
		{
			emit_signal("done", this, position);
		}
	}

	float MoveAround::getSpeed() const { return speed; }
	void MoveAround::setSpeed(float speed) { this->speed = speed; }

	float MoveAround::getAmplitude() const { return amplitude; }
	void MoveAround::setAmplitude(float amplitude) { this->amplitude = amplitude; }
}
