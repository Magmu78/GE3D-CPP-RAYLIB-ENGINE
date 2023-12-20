#include <GE3D/GameManager.h>
#include <GE3D/GameObject.h>
#include <GE3D/RigidbodyComponent.h>
#include <GE3D/Cube.h>
#include <GE3D/GMath.h>
#include <vector>
#include <memory>
#include <vendor/imgui/imgui.h>
#include <vendor/imgui/rlImGui.h>
#include <vendor/imgui/imgui_impl_raylib.h>
#include "raylib.h"

std::vector<std::shared_ptr<Component>> GameManager::allComponents;
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
    Cube cubeComponent;
    RigidbodyComponent cubeRigidbody;

    cube.transform.position = { 0, 0, 0 };
    cube.transform.scale = { 2, 1, 2 };
    cube.AddComponent(&cubeComponent);
    //cube.AddComponent(&cubeRigidbody);
    cubeComponent.color = RED;

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

        /* bool clickedOutside = true; // Variable pour détecter si un clic a été effectué en dehors des objets

        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            // Récupérer la position du clic de souris
            Vector2 mousePosition = GetMousePosition();

            // Vérifier si le clic de souris a été effectué sur l'un des objets
            for (auto& gameObject : GameManager::allGameObjects)
            {
                currentObject = gameObject.get(); 
                if (currentObject->GetComponent(cubeComponent))
                {
                    if (CheckCollisionPointRec(mousePosition, { currentObject->transform.scale.x, currentObject->transform.scale.y }))
                    {
                        currentObject->selected = true; // Marquer l'objet comme sélectionné
                        clickedOutside = false; // Le clic a été effectué sur un objet
                    }
                    else
                    {
                        currentObject->selected = false; // Désélectionner l'objet s'il a été précédemment sélectionné
                    }
                }
            }
        }

        if (clickedOutside)
        {
            // Désélectionner tous les objets si le clic a été effectué en dehors de leur zone
            for (auto& gameObject : GameManager::allGameObjects)
            {
                currentObject = gameObject.get();
                currentObject->selected = false;
            }
        } */
        /* if (currentObject != nullptr)
        {
            if (currentObject->selected)
            {
                // Utilisation de ImGui::InputFloat pour une entrée float
                ImGui::InputFloat("Position X", &currentObject->transform.position.x, 0.1f, 1.0f);
                ImGui::InputFloat("Position Y", &currentObject->transform.position.y, 0.1f, 1.0f);
                ImGui::InputFloat("Position Z", &currentObject->transform.position.z, 0.1f, 1.0f);
                ImGui::Checkbox("Active", &currentObject->active);
                ImGui::Checkbox("Debug Mode", &debugMode);

                if (debugMode)
                {
                    ImGui::Text("ID : %d", currentObject->id);
                }
            }
        }
        else
        {
            std::cout << "Current object = nullptr" << std::endl;
        } */

        ImGui::InputFloat("Position X", &cube.transform.position.x, 0.1f, 1.0f);
        ImGui::InputFloat("Position Y", &cube.transform.position.y, 0.1f, 1.0f);
        ImGui::InputFloat("Position Z", &cube.transform.position.z, 0.1f, 1.0f);
        ImGui::Checkbox("Active", &cube.active);
        ImGui::Checkbox("Debug Mode", &debugMode);

        if (debugMode)
        {
            ImGui::Text("ID : %d", cube.id);

            GameObject* cubePtr = &cube;

            ImGui::Text("Address: %p", static_cast<void*>(cubePtr));
        }

        for (const auto& component : GameManager::allComponents)
        {
            component->Update(deltaTime);
        }

        for (const auto& gameObject : GameManager::allGameObjects)
        {
            gameObject->Update(deltaTime);
        }

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