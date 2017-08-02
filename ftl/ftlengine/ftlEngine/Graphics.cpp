#include "Graphics.hpp"
#include "DebugUtil.hpp"
//#include "GL\glew.h" // loading opengl functions
#include "Application.hpp"

#include <fstream> //file stream; open file
#include <sstream> //string stream; file -> string
#include <vector>

#include <SOIL.h>
#include <GL\glew.h>

#include "Sprite.hpp"
#include "Transform.hpp"



SWE::Graphics::Graphics() //: numVertices(0)
{
}


SWE::Graphics::~Graphics()
{
				glBindVertexArray(0);
				glDeleteProgram(program);
}

//CreateShader Global function
GLuint CreateShader(GLenum Shadertype, const char * fileName)
{
				std::fstream f;
				f.open(fileName);
				DEBUG_ASSERT(!f.is_open(), "Opening a shader failed");

				std::stringstream sstream;

				sstream << f.rdbuf();
				std::string source = sstream.str();
				const char* sourceGL = source.c_str();
				GLuint shader = glCreateShader(Shadertype);
				glShaderSource(shader, 1, &sourceGL, nullptr);


				//Comiling shader
				glCompileShader(shader);
				GLint iv;
				glGetShaderiv(shader, GL_COMPILE_STATUS, &iv);

				GLint InfoLogLength;
				glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &InfoLogLength);
				if (iv != GL_TRUE) {
								std::vector<char> message(InfoLogLength + 1);
								glGetShaderInfoLog(shader, InfoLogLength, nullptr, &message[0]);
								DEBUG_PRINT("Error message = %s\n", &message[0]);
								DEBUG_PRINT("Failed to link program!!");
				}


				f.close();

				return shader;
}

//void SWE::Graphics::CreateCircleVertexBuffer()
//{
//				const int LevelOfDetail = 36; // one vertex per 10 degree
//				numVertices = LevelOfDetail + 2; //1 for center, 1 for loop
//				g_circleVertexBuffer = new GLfloat[numVertices*3];  //x, y, z per vertex
//
//				//Center vertex
//				g_circleVertexBuffer[0] = 0;
//				g_circleVertexBuffer[1] = 0;
//				g_circleVertexBuffer[2] = 0;
//
//				GLfloat* step = &g_circleVertexBuffer[3];
//				float draian = PI / LevelOfDetail;
//				float dr = 0;
//				for (int i = 0; i < LevelOfDetail; i +=3 /*x,y,z*/) {
//								step[i] = cosf(draian);
//								step[i+1] = sinf(draian);
//								step[i+2] = 0;
//								dr += draian;
//				}
//
//				g_circleVertexBuffer[numVertices * 3 - 3] = step[0];
//				g_circleVertexBuffer[numVertices * 3 - 2] = step[1];
//				g_circleVertexBuffer[numVertices * 3 - 1] = step[2];
//}



void SWE::Graphics::Initialize(void)
{
				//glFunctions ..
				DEBUG_ASSERT(glewInit() != GLEW_OK, "Initializing GLW is failed\n");

				//random values
				glClearColor(1, 1, 0.3f, 1);

				//Createing shader program
				program = glCreateProgram();

				//Creating shader
				GLuint vertexShader = CreateShader(GL_VERTEX_SHADER, "vertexShader.vert");
				GLuint fragmentShader = CreateShader(GL_FRAGMENT_SHADER, "fragmentShader.frag");

				//Attach compiled shaders to a program
				glAttachShader(program, vertexShader);
				glAttachShader(program, fragmentShader);

				//Try Linking attached shaders
				glLinkProgram(program);

				glDetachShader(program, vertexShader);
				glDetachShader(program, fragmentShader);


				//Delete shaders
				glDeleteShader(vertexShader);
				glDeleteShader(fragmentShader);

				//Get the error
				GLint iv;
				int InfoLogLength;
				glGetProgramiv(program, GL_LINK_STATUS, &iv);
				glGetProgramiv(program, GL_INFO_LOG_LENGTH, &InfoLogLength);
				if (iv != GL_TRUE) {
								std::vector<char> message(InfoLogLength + 1);
								glGetProgramInfoLog(program, InfoLogLength, nullptr, &message[0]);
								DEBUG_PRINT("Error message = %s\n", &message[0]);
								DEBUG_PRINT("Failed to link program!!");
				}

				glGenVertexArrays(1, &VAO);
				glBindVertexArray(VAO);

				GLuint buffer;
				GLfloat bufferData[] = {
																												-1, 1,0, //Top left vertex
																													1, 1,0,	//Top right vertex
																													1,-1,0, //Bottom right vertex
																													//

																												 0,1, //Top left texture coordinate
																													1,1,  //Top right
																													1,0, //Bottom right
																													//9+6 = 15

																													0,   0,   0,  //0
																												 0,   0.5f,0, //1
																													0.5f,0,   0, //2
																													0,  -0.5f,0, //4
																													//27
																												//Color data
																													1, 0, 0, 1, //Red
																													0, 1, 0, 1, //Green
																													0, 0, 1, 1, //Blue
																													1, 0, 0, 1
																													//27+16
																																}; //3
				//create opengl buffer object
				glGenBuffers(1, &buffer);
				//bind buffer object we generated to the GL_ARRAY_BUFFER target!
				glBindBuffer(GL_ARRAY_BUFFER, buffer);
				//allocate memory for buffer data in GPU
				glBufferData(GL_ARRAY_BUFFER, sizeof(bufferData), bufferData, GL_STATIC_DRAW);

				glEnableVertexAttribArray(0); //Vertex
				glVertexAttribPointer(0, 3/*x,y,z*/, GL_FLOAT, GL_FALSE, 0, (void*)0);
				glEnableVertexAttribArray(1); //color
				glVertexAttribPointer(1, 4/*rgba*/, GL_FLOAT, GL_FALSE, 0, (void*)sizeof(float[27]));

				glEnableVertexAttribArray(2); // Texture coordinate
				glVertexAttribPointer(2, 2,/*u,v*/GL_FLOAT, GL_FALSE, 0, (void*)sizeof(float[9]));

				glBindVertexArray(0);
				glDisableVertexAttribArray(0);
				glDisableVertexAttribArray(1);
				glDisableVertexAttribArray(2);
				glBindBuffer(GL_ARRAY_BUFFER, 0);

				GLuint location = glGetUniformLocation(program, "texturing");
				glUseProgram(program);
				glUniform1i(location, 1);
				glUseProgram(0);

				//texture loading using SOIL
				GLuint textureID = SOIL_load_OGL_texture("Slime.png", 
																																												 SOIL_LOAD_RGBA, 
																																												 SOIL_CREATE_NEW_ID, 
																																													SOIL_FLAG_POWER_OF_TWO|SOIL_FLAG_INVERT_Y);
				glActiveTexture(GL_TEXTURE0);
				glBindTexture(GL_TEXTURE_2D, textureID);

				uniformLocations[0] = glGetUniformLocation(program, "posOffset");
				uniformLocations[1] = glGetUniformLocation(program, "sizeOffset");

		/*		GLuint circleVAO;
				glGenVertexArrays(1, &circleVAO);
				glBindVertexArray(circleVAO);

				GLuint circleBufferObject;
				glGenBuffers(1, &circleBufferObject);
				glBindBuffer(GL_VERTEX_ARRAY, circleBufferObject);
				glBufferData(GL_VERTEX_ARRAY, sizeof(float[38*3], g_circleVertexBuffer, GL_STATIC_DRAW));

				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,(void*)0);

				glBindVertexArray(0);
				glBindBuffer(GL_VERTEX_ARRAY, 0);
				glDisableVertexAttribArray(0);

				glBindVertexArray(circleVAO);*/

}

void SWE::Graphics::Update(float /*dt*/)
{
				glClear(GL_COLOR_BUFFER_BIT);

				glUseProgram(program);
				glBindVertexArray(VAO);

				for (auto & it : SpriteList) {
								glBindTexture(GL_TEXTURE_2D, it->TextureID);
								//Todo: set color, animation...

								//Todo: decide 1 unit in game world
								glUniform2f(uniformLocations[0],
												it->pTransform->GetPosition().x,
												it->pTransform->GetPosition().y);
								//Todo: apply aspect ratio
								glUniform2f(uniformLocations[1], it->Size.x / 600, it->Size.y / 600);
								//Drawing vertex arrays
								//1 param = how to draw the vertices
								//2							=


								glDrawArrays(GL_TRIANGLES, 0, 3);
				}
			

				glBindVertexArray(0);
				glUseProgram(0);

				Application::instance()->SwapWindow();
}

