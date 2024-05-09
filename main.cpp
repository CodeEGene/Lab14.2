#include <iostream>
#include <string>
#include <limits>

using namespace std;

int charcnt(char* ptr, char c);
//This function, when given a C - string reference and a character, returns the number of times that the specified
//character occurred in the string.

int repeat(char* ptr);
//This function, when given a C - string reference, returns the number of repeated characters IN SEQUENCE that
//occur in the string.For example, the string “Mississippi” has three repeated characters :

void reverse(char* ptr);
//This function(from problem 7.8), when given a C - string, will reverse that character string.For example, "Harry"
//becomes "yrraH"

int main() {
	const int MAX_INPUT_LENGTH = 81;
	char input[MAX_INPUT_LENGTH];
	string line;
	char ch;


	cout << "Enter a string: ";
	cin.getline(input, MAX_INPUT_LENGTH);

	cout << "Enter a character: ";
	ch = cin.get();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');




	int charCount = charcnt(input, ch);
	int repeatCount = repeat(input);

	cout << "The character '" << ch << "' appears " << charCount << " times in the string." << endl;
	cout << "There are " << repeatCount << " repeated characters in the string." << endl;

	reverse(input);
	cout << "The reverse string is: " << input << endl;
}

int charcnt(char* ptr, char c) {
	int count = 0;
	while (*ptr != '\0') {
		if (*ptr == c) {
			count++;
		}
		ptr++;
	}
	return count;
}

int repeat(char* ptr) {
	int count = 0;
	char prev = '\0';
	int repeatCount = 0;

	while (*ptr != '\0') {
		if (*ptr != ' ' && *ptr == prev) {
			repeatCount++;
		}
		else {
			if (repeatCount > 1) {
				count++;
			}
			repeatCount = 1;
		}
		prev = *ptr;
		ptr++;
	}
	if (repeatCount > 1) {
		count++;
	}
	return count;
}

void reverse(char* ptr) {
	int length = 0;
	while (ptr[length] != '\0') {
		length++;
	}
	for (int i = 0; i < length / 2; i++) {
		char temp = ptr[i];
		ptr[i] = ptr[length - i - 1];
		ptr[length - i - 1] = temp;
	}
}
