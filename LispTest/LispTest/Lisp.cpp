#include "pch.h"
#include "Lisp.h"

LispAtom Lisp::parse(std::string code)
{
	LispAtom root;
	std::vector<LispAtom> openLists;
	std::string content;
	for (size_t i = 0; i < code.length(); ++i) {
		char next = code.at(i);
		if (next == '(') {
			LispAtom newActive;
			newActive.setIsList(true);
			openLists.push_back(newActive);
		}
		else if (next == ')') {
			if (!content.empty()) {
				LispAtom atom;
				atom.setContent(content);
				content.clear();
				LispAtom& active = openLists.back();
				active.addChildren(atom);
			}
			if (openLists.size() > 1) {
				LispAtom closed (openLists.back());
				openLists.pop_back();
				LispAtom &parent = openLists.back();
				parent.addChildren(closed);
			}
		}
		else if (next == ' ') {
			if (!content.empty()) {
				LispAtom atom;
				atom.setContent(content);
				content.clear();
				LispAtom& active = openLists.back();
				active.addChildren(atom);
			}
		}
		else {
			content.push_back(next);
		}
	}
	if (openLists.size() == 0)
	{
		root.setContent(content);
	}
	else {
		root = openLists.at(0);
	}
	return root;
}
