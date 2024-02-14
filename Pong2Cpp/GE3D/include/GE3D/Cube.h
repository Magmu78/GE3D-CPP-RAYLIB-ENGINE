#pragma once

#include <GE3D/Component.h>
#include "raylib.h"

class Cube : public Component
{
public:
	Cube();
	Cube(Color _color) : color(_color) {};

	void Update(float deltaTime) override;
	void Draw();

	void AddCompToGlobalList() override;

	Color GetColor();
	void SetColor(Color newColor);

	//Cube(Vector3 position, Vector3 scale, Color color);
private:
	Color color;
};