#include <iostream>
#include <vector>
using namespace std;
int main()
{
    unsigned int i;
    vector<int> first;
    vector<int> second(4, 100);
    vector<int> third(second.begin(), second.end());
    vector<int> fourth(third);
    int myints[] = {16, 2, 77, 29};
    vector<int> fifth(myints, myints + sizeof(myints) / sizeof(int));
    for (vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        cout << ' ' << *it;
    return 0;
}