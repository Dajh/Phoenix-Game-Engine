#pragma once

#include "AbstractRenderer.h"

class OpenGLRenderer : public AbstractRenderer
{
public:
	OpenGLRenderer();
	~OpenGLRenderer();
	void renderPrimitive(PrimitiveType prim);

};