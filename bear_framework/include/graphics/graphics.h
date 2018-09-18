#pragma once

#include<string>
#include<memory>

// Include files for the graphics module to work 
#include"vertex.h"
#include"shader.h"
#include"renderable.h"
#include"image.h"
#include"shape.h"
#include"text.h"
#include"view.h"
#include"texture.h"

namespace bear { namespace graphics {

	class Graphics {
		// Define some friendships between graphics classes
		friend class BatchRenderer;
		friend class TextLabel;
		friend class ParticleRenderer;
	
	private:
		// Used by: BatchRenderer
		static Shader* s_DefaultShader;
		static Shader* s_DefaultShaderText;
		static Shader* s_DefaultParticleShader;
		
		static unsigned int m_ScreenWidth;
		static unsigned int m_ScreenHeight;

	public:
		/* 
		* Initalize GLEW OpenGL bindings 
		* Arguments: window width and height used for shaders
		*/
		static bool init(unsigned int a_Width, unsigned int a_Height);

		/* Deallocates shader objects */
		static bool exit();

		/*
		* Callback for when window size is changed
		*/
		static void window_resize_callback(unsigned int a_Width, unsigned int a_Height);
	};

	// Used by Graphics::s_DefaultShader
	static int default_shader_pos_location = 0;
	static int default_shader_col_location = 1;
	static int default_shader_uv_location = 2;
	static std::string default_vertex_shader_source = "#version 330 \nlayout(location=0) in vec2 in_pos; \nlayout(location=1) in vec4 in_color; \nlayout(location=2) in vec2 in_uv; \nlayout(location=3) in int in_sampler_index; \nuniform mat4 projection_matrix; \nuniform mat4 model_matrix = mat4(1.0); \nuniform mat4 view_matrix = mat4(1.0); \nout vec4 color; \nout int sampler_index; \nout vec2 uv; \n void main(){ \ngl_Position = projection_matrix * model_matrix * view_matrix * vec4(in_pos.x, in_pos.y, 0, 1.0); \ncolor = in_color; \nuv = in_uv; \nsampler_index = in_sampler_index; \n} ";
	static std::string default_fragment_shader_source = "#version 330 \nin int sampler_index; \nin vec4 color; \nin vec2 uv; \nuniform sampler2D texture_sampler; \nuniform sampler2D sampler_list[4]; \nuniform int texture_mode; \nvoid main(){ \nif(sampler_index == -1) { gl_FragColor = color; } \nelse { gl_FragColor = texture(sampler_list[sampler_index], uv); } \n}";
	// Used by Graphics::s_DefaultShaderText
	static std::string text_vertex_shader_source = "#version 330 core \n layout(location = 0) in vec4 vertex; \n out vec2 TexCoords; \n uniform mat4 projection_matrix; \n uniform mat4 view_matrix = mat4(1.0f); \n void main() \n{ \n gl_Position = projection_matrix * view_matrix * vec4(vertex.xy, 0, 1); \n TexCoords = vertex.zw; \n }";
	static std::string text_fragment_shader_source = "#version 330 core \n in vec2 TexCoords; \n uniform sampler2D texture; \n uniform vec3 text_color; \n out vec4 color; \n void main() \n { \n color = vec4(1,1,1,texture2D(texture, TexCoords).r) * vec4(text_color,1); \n }";
	
} }