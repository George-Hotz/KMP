
#include "./src/kmp.h"

int main(){
    string source = "Welcome to my github : https://github.com/George-Hotz";
    
    string target1 = "Welcome";
    int pos1 = kmp_find(source, target1);
    cout << "KMP pos1: " << pos1 << endl;

    string target2 = "George-Hotz";
    int pos2 = kmp_find(source, target2);
    cout << "KMP pos2: " << pos2 << endl;
}