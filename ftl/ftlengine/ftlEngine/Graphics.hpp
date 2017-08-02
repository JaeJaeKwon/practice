#pragma once
#include "System.hpp"
//#include <GL\glew.h>
#include <memory>
#include <vector>

namespace SWE {

				class Sprite;
				class Graphics :public System
				{
				public:
								//Magical singletern code
								  static Graphics* instance()  //!< Returns an instance of the class
        {
            static std::unique_ptr<Graphics> instance(new Graphics());
            return instance.get();
        }
								~Graphics();
																//Initialize the system
								void Initialize(void) override;

							//All systems are updated every frame
								void Update(float dt) override;

								//All systems need a virtual destructor to their desturctors called
								std::vector<Sprite*> SpriteList;

				private:
								Graphics();
						//		GLuint CreateShader(GLenum Shadertype, const char * fileName);
							//	void CreateCircleVertexBuffer();


								unsigned int program;
								unsigned int VAO;
								int uniformLocations[2]; // posOffset, sizeOffset
								//GLfloat* g_circleVertexBuffer;
								//int numVertices;
								//const float PI = 3.14159265359;

				};

}