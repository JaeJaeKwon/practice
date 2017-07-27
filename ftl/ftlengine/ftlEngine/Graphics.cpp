#include "Graphics.hpp"
#include "DebugUtil.hpp"
#include "GL\glew.h" // loading opengl functions
#include "Application.hpp"

#include <fstream> //file stream; open file
#include <sstream> //string stream; file -> string

SWE::Graphics::Graphics()
{
}


SWE::Graphics::~Graphics()
{
}

GLuint SWE::Graphics::CreateShader(GLenum Shadertype, const char * fileName)
{
				std::fstream f;
				f.open(fileName);
				DEBUG_ASSERT(f.is_open(), "Opening a shader failed");

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

				//Get the error
				GLint iv;
				glGetShaderiv(program, GL_LINK_STATUS, &iv);
				if (iv != GL_TRUE) {
								DEBUG_PRINT("Failed to link program!!");
				}



}

void SWE::Graphics::Update(float /*dt*/)
{
				glClear(GL_COLOR_BUFFER_BIT);

				glUseProgram(program);
			
				Application::instance()->SwapWindow();
}

