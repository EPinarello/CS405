// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>

int main()
{
	std::cout << "EPinarello Module Two" << std::endl;
	std::cout << "Buffer Overflow Example" << std::endl;

	// TODO: The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
	//  even though it is a constant and the compiler buffer overflow checks are on.
	//  You need to modify this method to prevent buffer overflow without changing the account_order
	//  varaible, and its position in the declaration. It must always be directly before the variable used for input.

	const std::string account_number = "CharlieBrown42";
	//const size_t MAXIMUM_CHARS = 20;
	char user_input[20];
	//std::string user_input[20];
	std::cout << "Enter a value, not to exceed 20 characters: ";


	if (std::cin.getline(user_input, 20)) { //use get line to limit character input to 20 and prevent overflow
		std::cout << "You entered: " << user_input << std::endl; //determine if character input is met and display input
		//account number remains the same and is displayed
	
	}
	else {
		//user_input.erase(MAXIMUM_CHARS);
			std::cout << "Error. Character limit exceeded" << std::endl; //if character limit is exceeded, error message displayed
			exit; //account number remains the same and program is exited
	}

	std::cout << "Account Number = " << account_number << std::endl;
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

