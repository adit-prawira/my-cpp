//
// Created by Aditya Prawira on 19/2/21.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector <int> vector1;
    vector <int> vector2;

    vector1.push_back(10);
    vector1.push_back(20);

    cout << "\nvector1:"<< endl;
    cout << vector1.at(0) << endl;
    cout << vector1.at(1) << endl;
    cout << "vector1 contains"<< vector1.size() << " elements" << endl;

    vector2.push_back(100);
    vector2.push_back(200);

    cout << "\nvector2:"<< endl;
    cout << vector2.at(0) << endl;
    cout << vector2.at(1) << endl;
    cout << "vector2 contains"<< vector2.size() << " elements" << endl;
    
}
