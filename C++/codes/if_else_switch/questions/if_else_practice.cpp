#include <iostream>
using namespace std;
int main() {
	int g1;
	int g2;
	int g3;
	cout << "Enter the three sides you want to compare using a space-";
	cin >> g1 >> g2 >> g3;
	if (g1 == g2 and g2 == g3) {
		cout << "It is equilateral";
	} else if (g1 == g2 and g2 != g3) {
		cout << "It is isosceles";
	} else if (g1 != g2 and g2 == g3) {
		cout << "It is isosceles";
	} else if (g1 != g2 and g1 == g3) {
		cout << "It is isosceles";
	} else {
		cout << "It is scalene";
	}
  return 0;
}