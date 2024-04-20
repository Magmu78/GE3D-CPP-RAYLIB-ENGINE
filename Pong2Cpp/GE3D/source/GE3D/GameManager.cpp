#include <GE3D/GameManager.h>
#include <GE3D/GameObject.h>
#include <GE3D/RigidbodyComponent.h>
#include <GE3D/Component.h>
#include <GE3D/Cube.h>
#include <GE3D/GE3DPrereqs.h>
#include <vector>
#include <memory>
#include <vendor/imgui/imgui.h>
#include <vendor/imgui/rlImGui.h>
#include <vendor/imgui/imgui_impl_raylib.h>
#include "raylib.h"

std::vector<std::shared_ptr<RigidbodyComponent>> GameManager::allRigidbodies;
std::vector<std::shared_ptr<Cube>> GameManager::allCubes;
std::vector<std::shared_ptr<GameObject>> GameManager::allGameObjects;

GameManager::GameManager()
{

}

void GameManager::InitAppWindow(int width, int height, const char* title)
{
	InitWindow(width, height, title);
}

void GameManager::Loop()
{
    Camera3D camera = { 0 };
    camera.position = { 3.0f, 3.0f, 3.0f };
    camera.target = { 0.0f, 0.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    float deltaTime = GetFrameTime();

    GameObject cube;
    Cube cubeComponent(RED);

    cube.transform.position = { 0, 0, 0 };
    cube.transform.scale = { 2, 1, 2 };
    cube.AddComponent(ComponentType::CubeComponent);
    //cube.AddComponent(ComponentType::RigidbodyComponent);
    cubeComponent.SetColor(BLUE);

    for (const auto& component : cube.attached_components)
    {
        std::cout << component->GetName() << std::endl;
    }

    //cube.GetComponent(ComponentType::CubeComponent)->SetName("Soufyane");
    bool cameraLocked = false;
    bool keyPressed = false;
    bool previousKeyPressed = false;

    bool debugMode = false;

    float cubePositionX = 0.0f;
    float cubePositionY = 0.0f;
    float cubePositionZ = 0.0f;

    /* GameObject* currentObject = nullptr; */

    rlImGuiSetup(true);

    while (!WindowShouldClose())
    {
        deltaTime = GetFrameTime();

        if (IsKeyPressed(KEY_B))
        {
            keyPressed = true;
        }
        else
        {
            keyPressed = false;
        }

        if (keyPressed && !previousKeyPressed)
        {
            cameraLocked = !cameraLocked;
        }

        previousKeyPressed = keyPressed;

        if (!cameraLocked)
        {
            UpdateCamera(&camera, CAMERA_FIRST_PERSON);
        }

        if (IsKeyPressed(KEY_N))
        {
            camera.up = { 0, 0, 0 };
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        rlImGuiBegin();
        ImGui_ImplRaylib_NewFrame();

        BeginMode3D(camera);
        
        // ImGui window
        ImGui::Begin("GameObject editor");

        ImGui::InputFloat("Position X", &cube.transform.position.x, 0.1f, 1.0f);
        ImGui::InputFloat("Position Y", &cube.transform.position.y, 0.1f, 1.0f);
        ImGui::InputFloat("Position Z", &cube.transform.position.z, 0.1f, 1.0f);
        ImGui::Checkbox("Active", &cube.active);
        ImGui::Checkbox("Debug Mode", &debugMode);

        if (ImGui::Button("Display Components"))
        {
            for (const auto& component : cube.attached_components)
            {
                ImGui::BeginChild(component->GetName().c_str());
                ImGui::Text(component->GetName().c_str());

                if (ImGui::Button("Close"))
                {
                    ImGui::EndChild();
                    break;
                }
            }
        }

        if (debugMode)
        {
            ImGui::Text("ID : %d", cube.id);

            GameObject* cubePtr = &cube;

            ImGui::Text("Address: %p", static_cast<void*>(cubePtr));
        }

        for (const auto& cube : GameManager::allCubes)
        {
            //cube->Draw();
            cube->Update(deltaTime);
            if (cube->attachedGameObject != nullptr)
            {
                std::cout << cube->attachedGameObject << "exists" << std::endl;
            }
        }    

        for (const auto& rigidbody : GameManager::allRigidbodies)
            rigidbody->Update(deltaTime);

        for (const auto& gameObject : GameManager::allGameObjects)
            gameObject->Update(deltaTime);
        

        DrawGrid(1000, 0.5f);

        EndMode3D();

        DrawFPS(10, 10);

        // End the ImGui window
        ImGui::End();

        // End the ImGui frame
        rlImGuiEnd();

        EndDrawing();
    }
}

void GameManager::Cleanup()
{
    CloseWindow();
    rlImGuiShutdown();
}