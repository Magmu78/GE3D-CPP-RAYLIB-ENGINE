#include <GE3D/Cube.h>
#include <GE3D/GameObject.h>

Cube::Cube()
{
	color = RED;

	name = "Cube Shape";

	type = ComponentType::CubeComponent;

	AddCompToGlobalList();
}

/* Cube::Cube(Vector3 position, Vector3 scale, Color color) : position(this->position), scale(this->scale), color(this->color)
{

} */

void Cube::Update(float deltaTime)
{
	Draw();
	std::cout << "Cube Updated" << std::endl;
}

void Cube::Draw()
{
	DrawCube(attachedGameObject->transform.position, attachedGameObject->transform.scale.x, attachedGameObject->transform.scale.y, attachedGameObject->transform.scale.z, color);
}