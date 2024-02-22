#include <iostream>
using namespace std;
int main() {
	int age;
	cout << "Enter your age-";
	cin >> age;
	if (age >= 18) { 
		cout << "Eligible for driving license\n";
	} else {
		if (age >= 16) {
			cout << "Eligible for learners" << endl;
		} else {
			cout << "not eligible\n";
		}
	}
	return 0;
}