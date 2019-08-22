#pragma once

#include "LispAtom.h"

class Lisp
{
public:
	static LispAtom parse(std::string code);
};

