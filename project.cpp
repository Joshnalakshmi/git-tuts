#include <iostream>
using namespace std;
int main(int argc, char* argv[]) {
    // Print the number of arguments
    cout << "Total arguments: " << argc << endl;
    int sum=0;
    for (int i = 0; i < argc; ++i) {
        sum=sum+atoi(argv[i]);
        cout << "Argument " << i << ": " << argv[i] << endl;
    }
    cout<<"sum:"<<sum;
    return 0;
}