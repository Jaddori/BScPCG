#include "gtest\gtest.h"
#include "Array.h"

using namespace Utilities;

TEST(ArrayTest, Constructor)
{
	Array<int> arr;

	EXPECT_EQ(arr.getSize(), 0);
	EXPECT_EQ(arr.getCapacity(), Array<int>::DEFAULT_SIZE);
}

TEST(ArrayTest, ConstructorCopy)
{
	Array<int> a1;

	ASSERT_EQ(a1.getSize(), 0);
	ASSERT_EQ(a1.getCapacity(), Array<int>::DEFAULT_SIZE);

	// Add 5 numbers
	for(int i=0; i<5; i++)
	{
		a1.add(1);
	}

	ASSERT_EQ(a1.getSize(), 5);

	// Create new array with the contents of the previous one
	Array<int> a2(a1);

	EXPECT_EQ(a2.getSize(), 5);
	EXPECT_EQ(a2.getSize(), a1.getSize());
	EXPECT_EQ(a2.getCapacity(), Array<int>::DEFAULT_SIZE);
	EXPECT_EQ(a2.getCapacity(), a1.getCapacity());
	EXPECT_NE(a2.getData(), a1.getData());
}

TEST(ArrayTest, ConstructorInitialSize)
{
	const int ARRAY_SIZE = 50;

	Array<int> arr(ARRAY_SIZE);

	EXPECT_EQ(arr.getSize(), 0);
	EXPECT_EQ(arr.getCapacity(), ARRAY_SIZE);
}

TEST(ArrayTest, OperatorAssignment)
{
	Array<int> a1;

	ASSERT_EQ(a1.getSize(), 0);
	ASSERT_EQ(a1.getCapacity(), Array<int>::DEFAULT_SIZE);

	// Add 5 numbers
	for(int i=0; i<5; i++)
	{
		a1.add(1);
	}

	ASSERT_EQ(a1.getSize(), 5);

	Array<int> a2;
	ASSERT_EQ(a2.getSize(), 0 );
	ASSERT_EQ(a2.getCapacity(), Array<int>::DEFAULT_SIZE);

	a2 = a1;
	EXPECT_EQ(a2.getSize(), 5);
	EXPECT_EQ(a2.getSize(), a1.getSize());
	EXPECT_EQ(a2.getCapacity(), Array<int>::DEFAULT_SIZE);
	EXPECT_EQ(a2.getCapacity(), a1.getCapacity());
	EXPECT_NE(a2.getData(), a1.getData());

	// Test setting to an empty array
	Array<int> a3;
	ASSERT_EQ(a3.getSize(), 0);
	ASSERT_EQ(a3.getCapacity(), Array<int>::DEFAULT_SIZE);

	// Make sure a2 has a different capacity than a3
	for(int i=0; i<Array<int>::DEFAULT_SIZE; i++)
	{
		a2.add(1);
	}

	a2 = a3;
	EXPECT_EQ(a2.getSize(), 0);
	EXPECT_EQ(a2.getSize(), a3.getSize());
	EXPECT_NE(a2.getCapacity(), Array<int>::DEFAULT_SIZE);
	EXPECT_NE(a2.getCapacity(), a3.getCapacity());
	EXPECT_NE(a2.getData(), a3.getData());
}

TEST(ArrayTest, OperatorIndex)
{
	Array<int> arr;

	// Make sure we get the right values
	arr.add(1);
	arr.add(2);
	arr.add(3);

	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);

	// Make sure we still get the right values after expanding
	for(int i=0; i<Array<int>::DEFAULT_SIZE; i++)
	{
		arr.add(4+i);
	}

	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 2);
	EXPECT_EQ(arr[2], 3);
	EXPECT_EQ(arr[3], 4);
}

TEST(ArrayTest, At)
{
	Array<int> arr;

	// Make sure we get the right values
	arr.add(1);
	arr.add(2);
	arr.add(3);

	EXPECT_EQ(arr.at(0), 1);
	EXPECT_EQ(arr.at(1), 2);
	EXPECT_EQ(arr.at(2), 3);

	// Make sure we still get the right values after expanding
	for(int i=0; i<Array<int>::DEFAULT_SIZE; i++)
	{
		arr.add(4+i);
	}

	EXPECT_EQ(arr.at(0), 1);
	EXPECT_EQ(arr.at(1), 2);
	EXPECT_EQ(arr.at(2), 3);
	EXPECT_EQ(arr.at(3), 4);
}

TEST(ArrayTest, Add)
{
	Array<int> arr;

	ASSERT_EQ(arr.getSize(), 0);
	ASSERT_EQ(arr.getCapacity(), Array<int>::DEFAULT_SIZE);

	int* initialData = arr.getData();
	for( int i=0; i<Array<int>::DEFAULT_SIZE; i++ )
	{
		arr.add(5);
		EXPECT_EQ(arr.getSize(), i+1);
		EXPECT_EQ(arr.getCapacity(), Array<int>::DEFAULT_SIZE);
		EXPECT_EQ(arr.getData(), initialData); // make sure we're not allocating new memory
	}

	arr.add(5);
	EXPECT_EQ(arr.getSize(), 11);
	EXPECT_EQ(arr.getCapacity(), Array<int>::DEFAULT_SIZE*2);
	EXPECT_NE(arr.getData(), initialData); // make sure we did allocate new memory
}

TEST(ArrayTest, RemoveItem)
{
	Array<int> arr;

	ASSERT_EQ(arr.getSize(), 0);
	ASSERT_EQ(arr.getCapacity(), Array<int>::DEFAULT_SIZE);

	arr.add(1);
	arr.add(2);
	arr.add(3);

	ASSERT_EQ(arr.getSize(), 3);
	ASSERT_EQ(arr[1], 2);

	arr.removeItem(2);

	EXPECT_EQ(arr.getSize(), 2);
	EXPECT_EQ(arr.getCapacity(), Array<int>::DEFAULT_SIZE);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 3);
}

TEST(ArrayTest, RemoveAt)
{
	Array<int> arr;

	ASSERT_EQ(arr.getSize(), 0);
	ASSERT_EQ(arr.getCapacity(), Array<int>::DEFAULT_SIZE);

	arr.add(1);
	arr.add(2);
	arr.add(3);

	ASSERT_EQ(arr.getSize(), 3);
	ASSERT_EQ(arr[1], 2);

	arr.removeAt(1);

	EXPECT_EQ(arr.getSize(), 2);
	EXPECT_EQ(arr.getCapacity(), Array<int>::DEFAULT_SIZE);
	EXPECT_EQ(arr[0], 1);
	EXPECT_EQ(arr[1], 3);
}

TEST(ArrayTest, Clear)
{
	Array<int> arr;

	ASSERT_EQ(arr.getSize(), 0);
	ASSERT_EQ(arr.getCapacity(), Array<int>::DEFAULT_SIZE);

	for(int i=0; i<5; i++)
	{
		arr.add(1);
	}

	ASSERT_EQ(arr.getSize(), 5);

	arr.clear();
	EXPECT_EQ(arr.getSize(), 0);
	EXPECT_EQ(arr.getCapacity(), Array<int>::DEFAULT_SIZE);

	for(int i=0; i<Array<int>::DEFAULT_SIZE+1; i++)
	{
		arr.add(1);
	}

	ASSERT_EQ(arr.getSize(), Array<int>::DEFAULT_SIZE+1);

	arr.clear();
	EXPECT_EQ(arr.getSize(), 0);
	EXPECT_EQ(arr.getCapacity(), Array<int>::DEFAULT_SIZE*2);
}

TEST(ArrayTest, Reserve)
{
	Array<int> arr;

	ASSERT_EQ(arr.getSize(), 0);
	ASSERT_EQ(arr.getCapacity(), Array<int>::DEFAULT_SIZE);

	int* initialData = arr.getData();

	arr.reserve(100);

	EXPECT_EQ(arr.getSize(), 0);
	EXPECT_EQ(arr.getCapacity(), 100);
	EXPECT_NE(arr.getData(), initialData);
}