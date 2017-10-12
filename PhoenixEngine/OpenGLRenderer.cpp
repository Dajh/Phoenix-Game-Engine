#include "OpenGLRenderer.h"
#include <Windows.h>
#include <glew.h>


OpenGLRenderer::OpenGLRenderer()
{

}

void OpenGLRenderer::renderPrimitive(PrimitiveType prim)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 1.0f);

	switch (prim) 
	{
	case PrimitiveType::PRIM_POINT:
		break;
	case PrimitiveType::PRIM_LINE:
		break;
	case PrimitiveType::PRIM_TRIANGLE:
		
		float verts[] = { 0.0, 1.0, 0.0, -1.0, -1.0, 0.0, 1.0, -1.0, 0.0 };
		GLuint vao, vbo;
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), verts, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		/*
		glBegin(GL_TRIANGLES);
		glVertex2f(1.0f, 0.0f);
		glVertex2f(0.0f, 1.0f);
		glVertex2f(-1.0f, 0.0f);
		*/
		break;
	case PrimitiveType::PRIM_QUAD:
		break;
	}

	glEnd();
	glFlush();
}