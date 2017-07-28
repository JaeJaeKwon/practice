#pragma once
/*
Timer.hpp
HeeJae Kwon
Static class to keep track of time
*/
#include <chrono>
#include <memory>

namespace SWE {
				using namespace std::chrono;


				class Timer
				{
				public:
								static Timer* instance()  //!< Returns an instance of the class
								{
												static std::unique_ptr<Timer> instance(new Timer());
												return instance.get();
								}
        
								float GetDelta() {
												currTime = high_resolution_clock::now();

												duration<float> delta(currTime - prevTime);

												prevTime = high_resolution_clock::now();

												return delta.count();
								};

				private:
								time_point<high_resolution_clock> prevTime;
								time_point<high_resolution_clock> currTime;

								Timer() {
												prevTime = high_resolution_clock::now();
												currTime = prevTime;
								}

				};
}