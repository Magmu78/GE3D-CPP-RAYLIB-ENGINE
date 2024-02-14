#include <GE3D/Cube.h>
#include <GE3D/GameObject.h>

Cube::Cube() : color(WHITE)
{
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
	//std::cout << "Cube Updated" << std::endl;
}

void Cube::Draw()
{
	if (attachedGameObject != nullptr)
	{
		DrawCube(attachedGameObject->transform.position, attachedGameObject->transform.scale.x, attachedGameObject->transform.scale.y, attachedGameObject->transform.scale.z, color);
	}
}

void Cube::AddCompToGlobalList()
{
	GameManager::allCubes.push_back(std::make_shared<Cube>(*this));
}

Color Cube::GetColor()
{
	return color;
}

void Cube::SetColor(Color newColor)
{
	color = newColor;
}