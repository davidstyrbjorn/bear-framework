#pragma once

#include<deque>

#include"../renderable.h"
#include"../view.h"

namespace bear { namespace graphics {

class SlowRenderer {

private:
	unsigned int VBO; // Vertex buffer object
	unsigned int VAO; // Vertex array object
	unsigned int IBO; // Index buffer object
	std::deque<Renderable> render_poll;

	static View unit_view; 

public:
	/* Constructor */
	SlowRenderer();
	/* Destructor */
	~SlowRenderer();

	/* Should initalize the opengl buffers */
	void init();

	/* Rendering routines */
	void begin();
	void submit(Renderable& renderable);
	void flush(View& view = unit_view);

	/* Other */
	int get_indicies_count(int vertex_count);

};


	
}}