#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main()
{
    int arr[10];
    for(int i=0; i<20; i+=2){
        arr[i/2] = i;
    }

    cout << "Array:\n";
    for(int i=0; i<10; i++){
        cout << arr[i] << " ";
    }

    list <int> l;
    for(int i=1; i<20; i+=2){
        l.push_back(i);
    }

    list <int> :: iterator p;
    cout << "\n\nList:\n";
    for(p=l.begin(); p!=l.end(); p++){
        cout << *p << " ";
    }

    list <int> l2;
    for(int i=0; i<10; i++){
        l2.push_back(arr[i]);
    }

    l.merge(l2);

    vector <int> v;

    for(p=l.begin(); p!=l.end(); p++){
        v.push_back(*p);
    }

    cout << "\n\n";

    for(int i=0; i<20; i++){
        cout << v[i] << " ";
    }

    cout << "\nEND.";

    return 0;
}
