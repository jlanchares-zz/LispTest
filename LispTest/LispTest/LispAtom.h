#pragma once
class LispAtom
{
public:
	LispAtom() : _isList(false) {}
	inline bool isList() const { return _isList; }
	inline void setIsList(bool list) { _isList = list; }
	inline std::string getContent() { return _content; }
	inline void setContent(std::string content) { _content = content; }
	inline int size() { return _listContent.size();  }
	inline std::vector<LispAtom> getChildren() { return _listContent; }
	inline void addChildren(LispAtom children) { _listContent.push_back(children); }

private:
	bool _isList;
	std::string _content;
	std::vector<LispAtom> _listContent;
};

