#pragma once
/*
Timer.hpp
HeeJae Kwon
Static class to keep track of time
*/
#include <chrono>

namespace SWE {
				using namespace std::chrono;

				namespace {
								time_point<high_resolution_clock> prevTime;
								time_point<high_resolution_clock> currTime;
				}

				class Timer
				{
				public:
								static void Initialize() {
												prevTime = high_resolution_clock::now();
												currTime = prevTime;
								};
								static float GetDelta() {
												currTime = high_resolution_clock::now();

												duration<float> delta(currTime - prevTime);

												prevTime = high_resolution_clock::now();

												return delta.count();
								};

				private:

				};
}