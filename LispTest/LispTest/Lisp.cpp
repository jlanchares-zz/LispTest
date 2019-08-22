#include "pch.h"
#include "Lisp.h"

LispAtom Lisp::parse(std::string code)
{
	LispAtom root;
	std::string content;
	for (size_t i = 0; i < code.length(); ++i) {
		char next = code.at(i);
		if (next == '(') {

		}
		else if (next == ')') {

		}
		else if (next == ' ') {

		}
		else {
			content.push_back(next);
		}
	}
	root.setContent(content);
	return root;
}
