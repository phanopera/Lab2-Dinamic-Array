#include "pch.h"
#include "../darray/Header.h"
#include <random>

TEST(TestCaseName, TestName) {
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}
//инты
TEST(TestTArrayInt, TestDefault)
{
    TArray<int> a;
    EXPECT_EQ(a.size(), 0);
}

TEST(TestTArrayInt, TestMove)
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
        EXPECT_EQ(b[i], i + 1);
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
}
TEST(TestTArrayInt, TestIInsert)
{
    TArray<int> a;
    for (int i = 0; i < 20; ++i)
    {
        a.insert(i + 1);
    }

    EXPECT_NO_THROW(a.insert(0, 0));
    EXPECT_NO_THROW(a.insert(10, 0));
    EXPECT_NO_THROW(a.insert(22, 0));

    EXPECT_EQ(a.size(), 23);
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
}


//строки
TEST(TestTArrayString, TestDefault)
{
    TArray<std::string> a;
    EXPECT_EQ(a.size(), 0);
}
TEST(TestTArrayString, TestMove)
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
}
TEST(TestTArrayInt, TestIInsert)
{
    TArray<int> a;
    for (int i = 0; i < 20; ++i)
    {
        a.insert(i + 1);
    }

    EXPECT_NO_THROW(a.insert(0, 0));
    EXPECT_NO_THROW(a.insert(10, 0));
    EXPECT_NO_THROW(a.insert(22, 0));

    EXPECT_EQ(a.size(), 23);
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
}
