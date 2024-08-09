#pragma once

class TimeManager {
private:
    static std::chrono::high_resolution_clock::time_point previousTime;
    static float deltaTime;

public:
    TimeManager() {
        // Initialize the static member variables only once
        if (previousTime == std::chrono::high_resolution_clock::time_point()) {
            previousTime = std::chrono::high_resolution_clock::now();
            deltaTime = 0.0f;
        }
    }

    static void Update();

    static float GetDeltaTime() { return deltaTime; }
};