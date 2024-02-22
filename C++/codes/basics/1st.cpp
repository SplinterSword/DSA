#include <iostream> //include is used to include files and iostream is simple input and output file
using namespace std; //assign namespace as std for the whole program
int main() { // { is used at the start of a function as it signifies the start point } is used to signify the end point of a function
	int amount1; //This is the declaration of the variable
	int amount2;
	cout << "The amount given by Father="; //cout is used to display the output and << is exertion and /n or endl modifier is necessary for line break
	cin >> amount1; //cin is used to take inputs and \n or endl modifier is inbuild
	cout << "The amount given by Mother="; //to write a sentence use "" not '' as '' used to dermine datatype char
	cin >> amount2;
	int total = amount1 + amount2;
	cout << "the total amount is=" << total << endl;
    cout << sizeof(total); //sizeof() function tells us about the size in bytes in memory block is taken by a variable or a number
    long int c; //long int is datatype of int which have 8 bytes instead of 4
    short int d; //short int is datatype of int which have 2 bytes instead of 4
    return 0; // return 0 is used to end the function of main()
}