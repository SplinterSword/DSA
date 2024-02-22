#include <iostream>
#include <list> //header file to use list
using namespace std;

void display(list<int> l)
{
    list<int> :: iterator iter; //this is how you declare a iterator where iter is the iterator name.
    for (iter=l.begin();iter!=l.end();iter++) //list_name.begin() and list_name.end() give the iterator to the 1st and the last element of the linked list respectively.
    {
        cout<<*iter<<" "; // iterator can be increament to access the next element of the linked list.
    }
    cout<<endl;
    return;
}
int main()
{
    list<int> list1; //List of 0 length
    list1.push_back(5); //List_name.push_back(element) is how you add elements at the end of the list.
    list1.push_back(4);
    list1.push_back(3);
    list1.push_back(2);
    list1.push_back(1);
    display(list1);
    list<int> list2(3); //Empty list of size 3
    list<int> :: iterator it;
    for(it=list2.begin();it!=list2.end();it++) // you can use for loop to insert elements in the list
    {
        int a;
        cout<<"Enter the element in list 2-";
        cin>>a;
        *it=a;
    }
    display(list2);
    list1.pop_back(); // removes the last element of the linked list.
    display(list1);
    list1.pop_front(); // removes the first element of the linked list.
    display(list1);
    list1.remove(3); // removes the argument element from the linked list. If there is more than 1 occurance of the argument element than all the occurances of the element is removed. 
    display(list1);
    list1.sort(); // this is how we sort the list in the ascending order.
    display(list1);
    list1.merge(list2); // this is how you merge to 2 list. the argument list is merged at the end of the mentioned list
    display(list1);
    list1.reverse(); // this is how you reverse the mentioned the list.
    display(list1);
    return 0;
}