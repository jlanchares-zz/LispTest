#include "pch.h"

#include "Lisp.h"

TEST(LispTestCase, AtomTest) {
	LispAtom result = Lisp::parse("asd");
	EXPECT_FALSE(result.isList());
	EXPECT_EQ(result.getContent(), "asd");
}

TEST(LispTestCase, EmptyListTest) {
	LispAtom result = Lisp::parse("()");
	EXPECT_TRUE(result.isList());
	EXPECT_EQ(result.size(), 0);
	EXPECT_EQ(result.getContent(), "");
}

TEST(LispTestCase, EmptyListChildrenTest) {
	LispAtom result = Lisp::parse("()");
	EXPECT_TRUE(result.isList());
	EXPECT_EQ(result.size(), 0);
	std::vector<LispAtom> children = result.getChildren();
	EXPECT_EQ(children.size(), 0);

}

TEST(LispTestCase, NotEmptyListTest) {
	LispAtom result = Lisp::parse("(a s d)");
	EXPECT_TRUE(result.isList());
	EXPECT_EQ(result.size(), 3);
	std::vector<LispAtom> children = result.getChildren();
	EXPECT_EQ(children.size(), 3);
	EXPECT_FALSE(children[0].isList());
	EXPECT_EQ(children[0].getContent(), "a");
	EXPECT_FALSE(children[1].isList());
	EXPECT_EQ(children[1].getContent(), "s");
	EXPECT_FALSE(children[2].isList());
	EXPECT_EQ(children[2].getContent(), "d");
}

TEST(LispTestCase, NestedListTest) {
	LispAtom result = Lisp::parse("(ab (bcd de) fgh)");
	EXPECT_TRUE(result.isList());
	EXPECT_EQ(result.size(), 3);
	std::vector<LispAtom> children = result.getChildren();
	EXPECT_EQ(children.size(), 3);
	EXPECT_FALSE(children[0].isList());
	EXPECT_EQ(children[0].getContent(), "ab");
	EXPECT_TRUE(children[1].isList());
	std::vector<LispAtom> list2children = children[1].getChildren();
	EXPECT_EQ(list2children.size(), 2);
	EXPECT_FALSE(list2children[0].isList());
	EXPECT_EQ(list2children[0].getContent(), "bcd");
	EXPECT_FALSE(list2children[1].isList());
	EXPECT_EQ(list2children[1].getContent(), "de");
	EXPECT_FALSE(children[2].isList());
	EXPECT_EQ(children[2].getContent(), "fgh");
}
