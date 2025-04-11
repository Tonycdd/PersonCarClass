#include <iostream>
#include "System.h"


int main()
{
	try
	{

		//imam problem s cheteneto na inforamciq s getline() -> pri xorata vurvi ok
		// no za kolite trqbva da natiskash space, kogato ne izleze nishto na ekrana

		System current(3,2);
		current.print();

	}
	catch (const std::exception& e)
	{
		std::cerr << e.what();
	}

}

