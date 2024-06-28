#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    int RemainValue = (n % 2);
    
    if(0 == RemainValue)
    {
        cout << n << " is even" << endl;
    }
    else
    {
        cout << n << " is odd" << endl;
    }
    
    return 0;
}