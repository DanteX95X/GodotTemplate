#ifndef MOVE_AROUND_H
#define MOVE_AROUND_H

#include <godot_cpp/core/binder_common.hpp>
#include <godot_cpp/classes/sprite2d.hpp>

namespace test
{
	class MoveAround : public godot::Sprite2D
	{
		GDCLASS(MoveAround, godot::Sprite2D)

	public:
		static void _bind_methods();

		MoveAround();
		~MoveAround();

		void _init();
		void _process(double delta) override;

		float getSpeed() const;
		void setSpeed(float speed);

		float getAmplitude() const;
		void setAmplitude(float amplitude);

		void SignalledMethod(godot::Node* node, godot::Vector2 position);

	private:
		float timePassed{0};
		float amplitude{10};
		float speed{7};
	};
}

#endif // MOVE_AROUND_H
