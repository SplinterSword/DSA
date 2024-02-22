#include <iostream>
using namespace std;
int main() {
	char letter;
	cout << "Enter the letter:";
	cin >> letter;

	switch (letter) {
	case 'a':
		cout << "It is a vowel" << endl;
		break;
	case 'e':
		cout << "It is a vowel" << endl;
		break;
	case 'i':
		cout << "It is a vowel" << endl;
		break;
	case 'o':
		cout << "It is a vowel" << endl;
		break;
	case 'u':
		cout << "It is a vowel" << endl;
	default:
		cout << "It is consonant\n" << endl;
		break;
	}
	return 0;
}