#include "pch.h"
#include "Lisp.h"

LispAtom Lisp::parse(std::string code)
{
	LispAtom root;
	std::string content;
	int openParenthesis = 0;
	for (size_t i = 0; i < code.length(); ++i) {
		char next = code.at(i);
		if (next == '(') {
			openParenthesis++;
			root.setIsList(true);
		}
		else if (next == ')') {
			openParenthesis--;
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
