#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::string> Dictionary;
std::vector<std::string> IgnoreList;
std::vector<std::string> Solutions;

#define nprint(x) (std::cout << x << std::endl)
#define print(x) (std::cout << x);

struct Word
{
	std::string init; std::string fin;
};

void QCompute(Word word);
void ACompute(Word word);

int main()
{

	Dictionary.push_back("cot");
	Dictionary.push_back("dot");
	Dictionary.push_back("tain");
	Dictionary.push_back("thin");
	Dictionary.push_back("then");
	Dictionary.push_back("thee");


	Word word;

	print("First Word: ");
	std::cin >> word.init;
	print("Second Word: ");
	std::cin >> word.fin;

	ACompute(word);

	system("PAUSE");
}

void QCompute(Word word)
{
	if (word.init.length() == word.fin.length())
	{
		system("cls");
		print("Original: ");
		nprint(word.init);

		for (int i = 0; i < word.init.length(); i++)
		{
			if (word.init[i] != word.fin[i])
			{
				word.init[i] = word.fin[i];
				std::cout << "[" << i + 1 << "] " << word.init << std::endl;
			}
		}
	}
	
	else
	{
		nprint("Words of different size!");
	}
}

void ACompute(Word word)
{
	if (word.init.size() == word.fin.size())
	{
		for (int i = 0; i < word.init.size(); i++)
		{
			if (word.init[i] != word.fin[i])
			{
				std::string newString = word.init;
				//std::cout << newString << ":";
				newString[i] = word.fin[i];
				//std::cout << newString << std::endl;

				if (std::find(Dictionary.begin(), Dictionary.end(), newString) != Dictionary.end())
				{
					Solutions.push_back(newString);
					Word newWord;
					newWord.init = newString;
					newWord.fin = word.fin;
					std::cout << "Final Word: " << word.fin << std::endl;
					std::cout << newString << std::endl;
					ACompute(newWord);
					break;
				}
			}
		}
	}

	else
	{
		printf("\nIncorrect Word Lengths!\n");
		std::cout << word.init << " + " << word.fin;
	}
}
