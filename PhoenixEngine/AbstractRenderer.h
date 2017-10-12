#pragma once

#ifndef ABSTRACT_RENDERER_H
#define ABSTRACT_RENDERER_H

#include "BasicTypes.h"

class AbstractRenderer 
{
public:
	AbstractRenderer();
	~AbstractRenderer();
	virtual void renderPrimitive(GraphicPrimitiveType prim) = 0;
};

#endif // !ABSTRACT_RENDERER_H
