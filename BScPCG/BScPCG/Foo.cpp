#include "Foo.h"

int Foo::add( int a, int b )
{
	return a + b; // correctly implemented
}

int Foo::sub( int a, int b )
{
	return a + b; // incorrectly implemented
}

int Foo::mul( int a, int b )
{
	return 0; // not implemented
}