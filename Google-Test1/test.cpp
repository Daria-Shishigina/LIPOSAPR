#include "pch.h"
#include "../Project2/Vector.h"
#include "../Project2/Stack.h"
#include "../Project2/Stack.cpp"
#include "../Project2/Vector.cpp"



class VectorTest : public ::testing::Test
{
};

class StackTest : public ::testing::Test
{
};

TEST_F(VectorTest, TEST_VECTOR_PUSH_BACK)
{
	Vector vector = Vector();
	vector.PushBack(3);
	int testedValue = vector.GetThis(0);
	int expect = 3;
	EXPECT_EQ(testedValue, expect);
}

TEST_F(VectorTest, TEST_VECTOR_THROW_MINUS)
{
	Vector vector = Vector();
	ASSERT_ANY_THROW(vector.GetThis(-1));
}

TEST_F(VectorTest, TEST_VECTOR_THROW_PLUS)
{
	Vector vector = Vector();
	vector.PushBack(2);
	ASSERT_ANY_THROW(vector.GetThis(3));
}

TEST_F(VectorTest, TEST_VECTOR_POP_BACK)
{
	Vector vector = Vector();
	vector.PushBack(2);
	vector.PopBack();
	bool empty = vector.IsEmpty();
	ASSERT_TRUE(empty);
}


TEST_F(VectorTest, TEST_VECTOR_POP_BACK_THROW)
{
	Vector vector = Vector();
	ASSERT_ANY_THROW(vector.PopBack());
}


TEST_F(VectorTest, TEST_VECTOR_IS_EMPTY)
{
	Vector vector = Vector();
	vector.PushBack(2);
	bool empty = vector.IsEmpty();
	ASSERT_FALSE(empty);
}

TEST_F(VectorTest, TEST_VECTOR_CLEAR)
{
	Vector vector = Vector();
	vector.PushBack(2);
	vector.Clear();
	bool empty = vector.IsEmpty();
	ASSERT_TRUE(empty);
}

TEST_F(StackTest, TEST_STACK)
{
	Stack stack = Stack(3);
	int testedValue = stack.Size();
	int expect = 3;
	EXPECT_EQ(testedValue, expect);
}


TEST_F(StackTest, TEST_STACK_CLEAR)
{
	Stack stack = Stack(3);
	stack.Clear();
	bool empty = stack.IsEmpty();
	ASSERT_TRUE(empty);
}


TEST_F(StackTest, TEST_STACK_PUSH_THROW)
{
	Vector vector = Vector();
	Stack stack = Stack(1);
	ASSERT_NO_THROW(stack.Push(vector));
}

TEST_F(StackTest, TEST_STACK_PUSH)
{
	Vector vector = Vector();
	vector.PushBack(2);
	Stack stack = Stack(3);
	stack.Push(vector);
	Vector expect = vector;
	EXPECT_EQ(stack.Pull().GetThis(0), expect.GetThis(0));
}

TEST_F(StackTest, TEST_STACK_PULL_THROW)
{
	Vector vector = Vector();
	Stack stack = Stack(0);
	ASSERT_ANY_THROW(stack.Pull());
}

TEST_F(StackTest, TEST_STACK_PULL)
{
	Vector vector = Vector();
	vector.PushBack(1);
	Stack stack = Stack(1);
	stack.Push(vector);
	stack.Pull();
	bool empty = stack.IsEmpty();
	ASSERT_TRUE(empty);
}


TEST_F(StackTest, TEST_STACK_IS_EMPTY)
{
	Stack stack = Stack(1);
	bool empty = stack.IsEmpty();
	ASSERT_TRUE(empty);
}







