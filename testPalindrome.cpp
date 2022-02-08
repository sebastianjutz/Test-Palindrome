// Name: Sebastian Utz
// Class: CS 3305/Section W03
// Term: Fall 2021
// Instructor: Dr. Hossain
// Assignment: 4 Part 2
#include <iostream>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cassert>
#include <cctype>
#include <string>

void printMenu()
{
    using namespace std;
    
    cout  << '\n' << "The Commands" << '\n';
    cout << "1. Test Character-By-Character Palindrome" << '\n';
    cout << "2. Test Word-By-Word Palindrome" << '\n';
    cout << "Q. Quit" << '\n';
}

char getCommand()
{
    char command;
    std::cin >> command;
    return command;
}

int main()
{
	char command;
	do
	{
		printMenu();
		command = getCommand();
		if(command == '1')
		{
			std::queue<char> testQ;
			std::stack<char> testS;
			std::queue<char> unalteredInput;
			char nextChar;
			int check = 0;
			std::cout << "Enter the line you want checked to see if it is a ";
			std::cout << "palindrome based on characters:" << std::endl;

			do
			{
			    std::cin >> nextChar;
			    unalteredInput.push(nextChar);
			    if(isalpha(nextChar))
		        {
				    testQ.push(toupper(nextChar));
				    testS.push(toupper(nextChar));
		        }
			}while(std::cin.peek() != '\n');
			while(!testQ.empty() && !testS.empty())
			{
				if(testQ.front() != testS.top())
				{
					++check;
				}
				testQ.pop();
				testS.pop();
			}
			std::cout << '\n' << "You selected:    Option 1";
			std::cout << '\n' << "You entered:     ";
			while(!unalteredInput.empty())
			{
			    std::cout << unalteredInput.front();
			    unalteredInput.pop();
			}
			std::cout << '\n' << "Judgement:       ";
			if(check == 0)
			{
				std::cout << "Palindrome." << '\n';
			}
			else
			{
				std::cout << "Not Palindrome." << '\n';
			}
		}
		else if(command == '2')
		{
			std::queue<std::string> testQ;
			std::stack<std::string> testS;
			std::queue<std::string> unalteredInput;
			std::string nextWord;
			int check = 0;
			std::cout << "Enter the line you want checked to see if it is a ";
			std::cout << "palindrome based on words:" << std::endl;
			
			do
			{
			    std::cin >> nextWord;
			    unalteredInput.push(nextWord);
			    testQ.push(nextWord);
			    testS.push(nextWord);
			}while(std::cin.peek() != '\n');
			while(!testQ.empty() && !testS.empty())
			{
				if(testQ.front().compare(testS.top()) != 0)
				{
					++check;
				}
				testQ.pop();
				testS.pop();
			}
			std::cout << '\n' << "You selected:    Option 2";
			std::cout << '\n' << "You entered:     ";
			while(!unalteredInput.empty())
			{
			    std::cout << unalteredInput.front();
			    unalteredInput.pop();
			}
			std::cout << '\n' << "Judgement:       ";
			if(check == 0)
			{
				std::cout << "Palindrome." << '\n';
			}
			else
			{
				std::cout << "Not Palindrome." << '\n';
			}
		}
		else if(command == 'Q')
		{
			std::cout << "Bye";
		}
		else if(command == 'q')
		{
		    command = 'Q';
		}
		else
        {
            std::cout << "Invalid Command" << '\n';
        }
	}while(command != 'Q');
	return 0;
}