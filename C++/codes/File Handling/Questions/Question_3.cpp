#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream outfile("find.txt");
    for (int i = 0; i < 70; i++)
    {
        outfile << i;
    }
    cout << "Done";
    outfile.close();
    return 0;
}