//Using SDL and standard IO
#include <SDL.h>
#include <iostream>

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;


int main(int /*argc*/, char**  /*args[]*/) {
				//The window we'll be rendering to
				SDL_Window* window = nullptr;

				//The surface contained by the window
				SDL_Surface* screenSurface = nullptr;

				//Initialize SDL
				if (SDL_Init(SDL_INIT_VIDEO) < 0) {
								std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << "\n";
				}
				else {
								window = SDL_CreateWindow(
												"Summer2017",
												SDL_WINDOWPOS_CENTERED,
												SDL_WINDOWPOS_CENTERED,
												SCREEN_WIDTH,
												SCREEN_HEIGHT,
												SDL_WINDOW_SHOWN
								);

								if (window == nullptr) {
												std::cout << "SDL could not be created! SDL_Error: " << SDL_GetError() << "\n";
								}
								else {
												//Get window surface
												screenSurface = SDL_GetWindowSurface(window);

												//Fill the surface white
												SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x00, 0x00, 0xFF));

												//Update the surface
												SDL_UpdateWindowSurface(window);

												//Main loop flag
												bool quit = false;

												//Event handler
												SDL_Event e;

												//while application is running
												while (!quit) {
																//Handle events on queue
																while (SDL_PollEvent(&e) != 0) {
																				//User requests quit
																				if (e.type == SDL_QUIT) {
																								quit = true;
																				}
																				//User presses a key
																				else if (e.type == SDL_KEYDOWN) {
																								//Select surfaces based on key press
																								switch (e.key.keysym.sym) {
                            case SDLK_w:
																																std::cout << "W" << "\n";
                            break;

                            case SDLK_a:
																																std::cout << "A" << "\n";
                            break;

                            case SDLK_s:
																																std::cout << "S" << "\n";
                            break;

                            case SDLK_d:
																																std::cout << "D" << "\n";
                            break;

                            default:
																																quit = true;
                            break;
																								}

																				}
																}
																

												} //events end




												//Wait two seconds
											//	SDL_Delay(5000);
								}
				}

				//Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();

				return 0;
}//main end
