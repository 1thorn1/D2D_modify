#include "pch.h"
#include "TimeManager.h"

std::chrono::high_resolution_clock::time_point TimeManager::previousTime;
float TimeManager::deltaTime;

void TimeManager::Update() {
    auto currentTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> deltaTimeDuration = currentTime - previousTime;
    deltaTime = deltaTimeDuration.count();
    previousTime = currentTime;
}
