#include <gtest/gtest.h>
#include "Set.h"


TEST(SetTest, DefaultConstructor) {
    Set s;
    EXPECT_TRUE(s.empty());
    EXPECT_EQ(s.size(), 0u);
}

TEST(SetTest, InsertSingleString) {
    Set s;
    auto a = makeString("a");
    s.insert(a);
    EXPECT_FALSE(s.empty());
    EXPECT_EQ(s.size(), 1u);
    EXPECT_TRUE(s.contains(a));
}

TEST(SetTest, InsertDuplicateNotGrowing) {
    Set s;
    auto a = makeString("a");
    s.insert(a);
    s.insert(a);
    EXPECT_EQ(s.size(), 1u);
}

TEST(SetTest, EraseExistingElement) {
    Set s;
    auto a = makeString("a");
    s.insert(a);
    EXPECT_TRUE(s.erase(a));
    EXPECT_TRUE(s.empty());
}

TEST(SetTest, EraseNonExistingElement) {
    Set s;
    EXPECT_FALSE(s.erase(makeString("x")));
}


TEST(SetTest, UnionTwoNonEmpty) {
    Set s1;
    s1.insert(makeString("a"));
    s1.insert(makeString("b"));

    Set s2;
    s2.insert(makeString("b"));
    s2.insert(makeString("c"));

    Set u = s1 + s2;
    EXPECT_EQ(u.size(), 3u);
    EXPECT_TRUE(u.contains(makeString("a")));
    EXPECT_TRUE(u.contains(makeString("b")));
    EXPECT_TRUE(u.contains(makeString("c")));
}

TEST(SetTest, UnionAssignAddsElements) {
    Set s1;
    s1.insert(makeString("a"));

    Set s2;
    s2.insert(makeString("b"));

    s1 += s2;
    EXPECT_EQ(s1.size(), 2u);
    EXPECT_TRUE(s1.contains(makeString("a")));
    EXPECT_TRUE(s1.contains(makeString("b")));
}

TEST(SetTest, UnionWithEmptyKeepsOriginal) {
    Set s;
    s.insert(makeString("a"));
    Set empty;
    Set u = s + empty;
    EXPECT_EQ(u.size(), 1u);
    EXPECT_TRUE(u.contains(makeString("a")));
}

TEST(SetTest, EmptyUnionEmptyIsEmpty) {
    Set a, b;
    Set u = a + b;
    EXPECT_TRUE(u.empty());
}


TEST(SetTest, IntersectionNonEmpty) {
    Set s1;
    s1.insert(makeString("a"));
    s1.insert(makeString("b"));

    Set s2;
    s2.insert(makeString("b"));
    s2.insert(makeString("c"));

    Set inter = s1 * s2;
    EXPECT_EQ(inter.size(), 1u);
    EXPECT_TRUE(inter.contains(makeString("b")));
}

TEST(SetTest, IntersectionAssign) {
    Set s1;
    s1.insert(makeString("a"));
    s1.insert(makeString("b"));

    Set s2;
    s2.insert(makeString("b"));

    s1 *= s2;
    EXPECT_EQ(s1.size(), 1u);
    EXPECT_TRUE(s1.contains(makeString("b")));
}

TEST(SetTest, IntersectionWithEmptyIsEmpty) {
    Set s;
    s.insert(makeString("a"));
    Set empty;
    Set inter = s * empty;
    EXPECT_TRUE(inter.empty());
}


TEST(SetTest, DifferenceBasic) {
    Set s1;
    s1.insert(makeString("a"));
    s1.insert(makeString("b"));

    Set s2;
    s2.insert(makeString("b"));

    Set diff = s1 - s2;
    EXPECT_EQ(diff.size(), 1u);
    EXPECT_TRUE(diff.contains(makeString("a")));
}

TEST(SetTest, DifferenceAssignRemovesElements) {
    Set s1;
    s1.insert(makeString("a"));
    s1.insert(makeString("b"));

    Set s2;
    s2.insert(makeString("b"));

    s1 -= s2;
    EXPECT_EQ(s1.size(), 1u);
    EXPECT_TRUE(s1.contains(makeString("a")));
}

TEST(SetTest, DifferenceWithEmptyKeepsAll) {
    Set s;
    s.insert(makeString("a"));
    s.insert(makeString("b"));

    Set empty;
    Set diff = s - empty;
    EXPECT_EQ(diff.size(), 2u);
}

TEST(SetTest, EmptyMinusNonEmptyIsEmpty) {
    Set s1;
    Set s2;
    s2.insert(makeString("a"));
    Set diff = s1 - s2;
    EXPECT_TRUE(diff.empty());
}


TEST(SetTest, ClearByEraseSequence) {
    Set s;
    s.insert(makeString("a"));
    s.insert(makeString("b"));
    s.erase(makeString("a"));
    s.erase(makeString("b"));
    EXPECT_TRUE(s.empty());
}

TEST(SetTest, InsertAfterEraseWorks) {
    Set s;
    s.insert(makeString("a"));
    s.erase(makeString("a"));
    s.insert(makeString("b"));
    EXPECT_EQ(s.size(), 1u);
    EXPECT_TRUE(s.contains(makeString("b")));
}

TEST(SetTest, ChainOfOperations) {
    Set s1;
    s1.insert(makeString("a"));
    s1.insert(makeString("b"));

    Set s2;
    s2.insert(makeString("b"));
    s2.insert(makeString("c"));

    Set r = (s1 + s2) * s1;
    r -= s2;
    EXPECT_EQ(r.size(), 1u);
    EXPECT_TRUE(r.contains(makeString("a")));
}

TEST(SetTest, LargeSetInsertMany) {
    Set s;
    for (char c = 'a'; c <= 'z'; ++c) {
        std::string str(1, c);
        s.insert(makeString(str));
    }
    EXPECT_EQ(s.size(), 26u);
}

TEST(SetTest, ContainsAfterManyInsertsAndErases) {
    Set s;
    s.insert(makeString("a"));
    s.insert(makeString("b"));
    s.insert(makeString("c"));
    s.erase(makeString("b"));
    EXPECT_TRUE(s.contains(makeString("a")));
    EXPECT_FALSE(s.contains(makeString("b")));
    EXPECT_TRUE(s.contains(makeString("c")));
}


TEST(SetTest, PowerSetOfEmptyHasOneElement) {
    Set s;
    Set ps = s.powerSet();
    EXPECT_EQ(ps.size(), 1u);
}

TEST(SetTest, PowerSetOfSingleElement) {
    Set s;
    s.insert(makeString("a"));
    Set ps = s.powerSet();
    // {}, {a}
    EXPECT_EQ(ps.size(), 2u);
}


TEST(SetTest, ConstructFromSimpleString) {
    Set s("{a, b}");
    EXPECT_EQ(s.size(), 2u);
    EXPECT_TRUE(s.contains(makeString("a")));
    EXPECT_TRUE(s.contains(makeString("b")));
}

TEST(SetTest, ConstructFromNestedString) {
    Set s("{a, {b}}");
    EXPECT_TRUE(s.contains(makeString("a")));
    EXPECT_GE(s.size(), 1u);
}

TEST(SetTest, OutputOperatorProducesBraces) {
    Set s;
    s.insert(makeString("a"));
    std::ostringstream oss;
    oss << s;
    std::string out = oss.str();
    EXPECT_FALSE(out.empty());
    EXPECT_NE(out.find('{'), std::string::npos);
    EXPECT_NE(out.find('}'), std::string::npos);
}



TEST(SetTest, EqualSets) {
    Set a("{a, b}");
    Set b("{b, a}");
    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a != b);
}

TEST(SetTest, NotEqualSets) {
    Set a("{a}");
    Set b("{b}");
    EXPECT_FALSE(a == b);
    EXPECT_TRUE(a != b);
}
TEST(SetTest, InsertTwoSameThenEraseOne) {
    Set s;
    auto a = makeString("a");
    s.insert(a);
    s.insert(a);            
    EXPECT_EQ(s.size(), 1u);
    EXPECT_TRUE(s.erase(a));
    EXPECT_TRUE(s.empty());
}

TEST(SetTest, UnionResultContainsAllSourceElements) {
    Set s1;
    s1.insert(makeString("a"));
    s1.insert(makeString("b"));

    Set s2;
    s2.insert(makeString("c"));

    Set u = s1 + s2;
    EXPECT_TRUE(u.contains(makeString("a")));
    EXPECT_TRUE(u.contains(makeString("b")));
    EXPECT_TRUE(u.contains(makeString("c")));
    EXPECT_EQ(u.size(), 3u);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
