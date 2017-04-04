#include "gtest\gtest.h"
#include "Foo.h"

// This one works
TEST(FooTest, Add)
{
	Foo foo;

	EXPECT_EQ( foo.add(1,1), 2 );
	EXPECT_EQ( foo.add(1,-1), 0 );
	EXPECT_EQ( foo.add(12345, 1), 12346 );

	// etc etc...
}

// This one does not
TEST(FooTest, Sub)
{
	Foo foo;

	EXPECT_EQ( foo.sub(1,1), 0 );
	EXPECT_EQ( foo.sub(0,-1), 1 );
	EXPECT_EQ( foo.sub(-1, 1), -2 );

	// etc etc...
}

// This one is not yet implemented
TEST(FooTest, Mul)
{
	Foo foo;

	EXPECT_EQ( foo.mul(1,1), 1 );
	EXPECT_EQ( foo.mul(2,2), 4 );
	EXPECT_EQ( foo.mul(4,-1), -4 );

	// etc etc...
}