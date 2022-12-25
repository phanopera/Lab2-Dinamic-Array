#include "pch.h"
#include "../array/darray.h"
#include <random>

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
//сверх быстрая мегасортиров очка
TEST(TestTArrayInt, TestDefaultConstructor)
{
    TArray<int> a;
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.capacity(), 8);
}


TEST(TestTArrayInt, TestCapacityConstructor)
{
    TArray<int> a { 10 };
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.capacity(), 10);
}
TEST(TestTArrayInt, TestMoveConstructor)
{
    TArray<int> a;
    for (int i = 0; i < 15; ++i)
    {
        a.insert(i + 1);
    }

    TArray<int> b(std::move(a));

    for (int i = 0; i < 15; ++i)
    {
        EXPECT_NO_THROW(b[i]);
        EXPECT_EQ(b[i], i+1);
    }
}

TEST(TestTArrayInt, TestInsert)
{
    TArray<int> a;
    for (int i = 0; i < 5; ++i)
    {
        EXPECT_NO_THROW(a.insert(i + 1));
    }

    EXPECT_EQ(a.size(), 5);
    EXPECT_EQ(a.capacity(), 8);
}
TEST(TestTArrayInt, TestIndexedInsert)
{
    TArray<int> a;
    for (int i = 0; i < 20; ++i)
    {
        a.insert(i + 1);
    }

    EXPECT_NO_THROW(a.insert(0,0));
    EXPECT_NO_THROW(a.insert(10, 0));
    EXPECT_NO_THROW(a.insert(22, 0));

    EXPECT_EQ(a.size(), 23);
    EXPECT_EQ(a.capacity(), 32);
}

TEST(TestTArrayInt, TestRemove)
{
    TArray<int> a;
    for (int i = 0; i < 5; ++i)
    {
        a.insert(i + 1);
    }

    EXPECT_NO_THROW(a.remove(0));

    EXPECT_EQ(a.size(), 4);
    EXPECT_EQ(a[0], 2);
    EXPECT_EQ(a.capacity(), 8);
}
TEST(TestTArrayString, TestDefaultConstructor)
{
    TArray<std::string> a;
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.capacity(), 8);
}


TEST(TestTArrayString, TestCapacityConstructor)
{
    TArray<std::string> a { 10 };
    EXPECT_EQ(a.size(), 0);
    EXPECT_EQ(a.capacity(), 10);
}
TEST(TestTArrayString, TestMoveConstructor)
{
    TArray<std::string> a;
    for (int i = 0; i < 20; ++i)
    {
        a.insert("Loremipsumdolorsitametconsecteturadipiscingelit" + i);
    }

    TArray<std::string> b(std::move(a));

    for (int i = 0; i < 20; ++i)
    {
        EXPECT_NO_THROW(b[i]);
        EXPECT_EQ(b[i], "Loremipsumdolorsitametconsecteturadipiscingelit" + i);
    }
}
TEST(TestTArrayString, TestInsert)
{
    TArray<std::string> a;
    for (int i = 0; i < 5; ++i)
    {
        EXPECT_NO_THROW(a.insert("Loremipsumdolorsitametconsecteturadipiscingelit" + i));
    }

    EXPECT_EQ(a.size(), 5);
    EXPECT_EQ(a.capacity(), 8);
}
TEST(TestTArrayString, TestRemove)
{
    TArray<std::string> a;
    for (int i = 0; i < 5; ++i)
    {
        a.insert("akdhksbhashgkgbvzbshv" + i);
    }

    EXPECT_NO_THROW(a.remove(0));

    EXPECT_EQ(a.size(), 4);
    EXPECT_EQ(a[0], "Loremipsumdolorsitametconsecteturadipiscingelit" + 1);
    EXPECT_EQ(a.capacity(), 8);
}