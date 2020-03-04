#include "forward.cpp"
#include "backward.cpp"

#include <iostream>
using namespace std;

int main()
{
    cout<< "Thank you for using our program to determine your major and area."<<endl
        << "The program will first tell you your major, and then it will suggest an area of study to you"<<endl
        <<"Please answer all quetions to the best of your ability."
        << endl<< endl;

    int back;
    int forw;

    back = backward();
    forw = forward();

    cout << endl << endl << "The program has now completed. Thank you." <<endl;

    return 0;
}