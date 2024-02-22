//Vector is just an array with dynamic memory i.e. it increases or decreases its size according to the no. of elements
#include <iostream>
#include <vector> //header file to use vectors and its function.

using namespace std;

void display(vector<int> v)
{
    for (int i=0;i<v.size();i++) // vector_name.size() returns the size of the vector.
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return;
}

int main()
{
    vector<int> vec1; // this is how you declare a vector .This is zero length vector
    int element,size;
    cout<<"Enter the size of the vector you want-";
    cin>>size;
    vector<char> vec2(4); //4-element character vector
    vector<char> vec3(vec2); //4-element character vector using vec2
    vector<int> vec4(6,3); // 6-element vector of 3s. 1st argument is size of the vector and 2nd argument is the element which is to be put in the vector.
    for (int i=0;i<size;i++)
    {
        cout<<"Enter an element to add to this vector-";
        cin>>element;
        vec1.push_back(element); //vector_name.push_back(element which is to be inserted) is how you insert elements in the vectors.
    }
    display(vec1);
    display(vec4);
    vec1.pop_back(); //vector_name.pop_back() removes the last element of the vector
    display(vec1);
    vector<int> :: iterator iter = vec1.begin(); // This is how you declare an iterator and vector_name.begin() is the iterator pointing to the first element of the vector.
    vec1.insert(iter,5); //vector_name.insert(iterator,element) is used to insert an element in the designated spot.
    display(vec1);
    vec1.insert(iter+1,5,50); //iterator can be incremented or decreamented to point to different indexes. Also Vector_name.insert() can take upto 3 arguments 1st is the iterator, 2nd is the no. of times the element has to be inserted. 3rd is the element itself.
    display(vec1);
    return 0;
}