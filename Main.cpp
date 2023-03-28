#include <iostream>
#include <string>

bool is_palindrome(std::string word) {
	for (int i = 0; i < word.length() / 2; i++) 
		if (std::tolower(word[i]) != std::tolower(word[word.length() - i - 1]))
			return false;
	return true;
}

int punct_marks(std::string str) {
	int counter = 0;
	for (int i = 0; i < str.length(); i++)
		if (str[i] == ' ' || str[i] == '.' || str[i] == ',' || str[i] == '!' || str[i] == '?')
			counter++;
	return counter;
}

std::string sub_str(std::string str, char sym) {
	std::string new_str;
	int pos = str.rfind(sym);
	if (pos >= 0 && pos < str.length())
		new_str = str.substr(pos);
	return new_str;
}

int main() {
	std::string str;
	char sym;

	//Task 25.1. A string of repeating symbols
	std::cout << "\tTask 25.1. A string of repeating symbols\nEnter a string -> ";
	std::getline(std::cin, str);
	std::cout << "Enter a symbol to search -> ";
	std::cin >> sym;
	std::string sym_str;
	for (int i = 0; i < str.length(); i++)
		if (str[i] == sym)
			sym_str += sym;
	if (sym_str.length())
		std::cout << "Result string: " << sym_str << "\n\n";
	else
		std::cout << "No matches found!" << "\n\n";


	// Task 25.2. Palindrome
	std::cout << "\tTask 25.2. Palindrome\nEnter a word -> ";
	std::cin >> str;
	std::cout << "The word \"" << str << "\" is" << (is_palindrome(str) ? " " : " not ") << "a palindrome" << "\n\n";


	// Task 25.3. Punctuation marks and spaces
	std::cout << "\tTask 25.3. Punctuation marks and spaces\nEnter a string -> ";
	std::cin.ignore();
	std::getline(std::cin, str);
	std::cout << "Counting all the following punctuation marks . , ! ? and all spaces...\n";
	std::cout << "Total found: " << punct_marks(str) << "\n\n";


	// Task 25.4. A substring
	std::cout << "\tTask 25.4. A substring\nEnter a string -> ";
	std::getline(std::cin, str);
	std::cout << "Enter a symbol to search -> ";
	std::cin >> sym;
	if(sub_str(str, sym).length())
		std::cout << "Result substring: " << sub_str(str, sym) << "\n\n";
	else
		std::cout << "No matches found!" << "\n\n";


	return 0;
}