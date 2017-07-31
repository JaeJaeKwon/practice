#include "Graphics.hpp"
#include "DebugUtil.hpp"
//#include "GL\glew.h" // loading opengl functions
#include "Application.hpp"

#include <fstream> //file stream; open file
#include <sstream> //string stream; file -> string

#include <vector>


SWE::Graphics::Graphics()
{
}


SWE::Graphics::~Graphics()
{
				glBindVertexArray(0);
				glDeleteProgram(program);
}

GLuint SWE::Graphics::CreateShader(GLenum Shadertype, const char * fileName)
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
				if (iv != GL_TRUE) {
								DEBUG_PRINT("Failed to compile shader source; %s\n", fileName);
				}

				f.close();

				return shader;
}


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
				GLfloat bufferData[] = { 0,   0,   0,  //0
																												 0,   0.5f,0, //1
																													0.5f,0,   0, //2
																													0,  -0.5f,0, //4
																												//Color data
																													1, 0, 0, 1, //Red
																													0, 1, 0, 1, //Green
																													0, 0, 1, 1, //Blue
																													1, 0, 0, 1
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
				glVertexAttribPointer(1, 4/*rgba*/, GL_FLOAT, GL_FALSE, 0, (void*)sizeof(float[12]));

				glBindVertexArray(0);
				glDisableVertexAttribArray(0);
				glDisableVertexAttribArray(1);
				glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void SWE::Graphics::Update(float /*dt*/)
{
				glClear(GL_COLOR_BUFFER_BIT);

				glUseProgram(program);
				glBindVertexArray(VAO);
			
				glDrawArrays(GL_TRIANGLES, 1, 3);

				glUseProgram(0);
				glBindVertexArray(0);

				Application::instance()->SwapWindow();
}

