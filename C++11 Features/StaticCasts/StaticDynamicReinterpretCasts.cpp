// StaticCasts.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Base {
public:
	virtual void Print() {
		std::cout << "Base\n";
	}
};

class BrotherDerived : public Base {

};

class SisterDerived : public Base {

};

int main()
{
	Base base;
	BrotherDerived brother;

	////////////////////
	// Static cast
	///////////////////
	// Checks cast at compile time
	Base *bp = &brother; // BrotherDerived "is a" Base
	//BrotherDerived *bdp = bp; // Doesn't work, but it should because I know the proper class is there
	BrotherDerived *bdp = static_cast<BrotherDerived *>(bp); // Can cast it, however, it is unsafe!

	float num = 1.23f;

	std::cout << "Printing with no cast: " << num << '\n';
	std::cout << "Printing with static cast to int: " << static_cast<int>(num) << '\n';

	//Base &&rrb = Base(); // Allowed
	//Base &&rrb = base; // Doesn't compile, trying to bound rvalue reference to lvalue
	Base &&rrb = static_cast<Base &&>(base); // Cast lvalue to an rvalue reference
	rrb.Print();



	////////////////////
	// Dynamic cast
	///////////////////
	// Does runtime checking to see if the cast makes sense
	bp = &base;
	bdp = dynamic_cast<BrotherDerived *>(bp); // Will try to cast, but will return nullptr if the case doesn't make sense

	if (bdp) {
		std::cout << "Cast worked\n";
	} else {
		std::cout << "Cast failed\n";
	}

	////////////////////
	// Reinterpret cast
	///////////////////
	SisterDerived sister;

	// Can be used when static and dynamic cast both fail, and there is a bizarre cast that needs to be done for some starnge reason (vendor API's sometimes)
	SisterDerived *sdp = reinterpret_cast<SisterDerived *>(bdp);


    return 0;
}

