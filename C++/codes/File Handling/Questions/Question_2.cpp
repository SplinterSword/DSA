#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream fio;
    string line;
    fio.open("demo.txt", ios::trunc | ios::out | ios::in);
    while (fio)
    {
        getline(cin, line);
        if (line == "-1")
            break;
        fio << line << endl;
    }
    while (fio)
    {
        // Read a Line from File
        getline(fio, line);
        // Print line in Console
        cout << line << endl;
    }
    // Close the file
    fio.close();
    return 0;
}