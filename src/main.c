#include <stdio.h>

#include <raylib.h>

int main(void)
{
    printf("Hello, World!\n");

    InitWindow(600, 600, "Raylib Asteroids");
    InitAudioDevice(); // Initialize audio device

    Sound aerials = LoadSound("resources/aerials.mp3");

    while (!WindowShouldClose())
    {

        if (IsKeyPressed(KEY_SPACE))
            IsSoundPlaying(aerials) ? PauseSound(aerials) : PlaySound(aerials);

        BeginDrawing();
        ClearBackground(LIME);
        DrawText("Congrats! You created your first window!", 10, 10, 20, LIGHTGRAY);
        EndDrawing();
    }

    UnloadSound(aerials);
    CloseAudioDevice(); // Close audio device
    CloseWindow();
    return 0;
}