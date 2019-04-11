#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    vector<int32_t> v;
    int n, i; 
    ifstream ifs{ string{ argv[1] } };
    bool sorted = true;

    while(true){
       ifs >> n;
       if(ifs.eof()) break;
       v.push_back(n);
    }

    for (i = 0; i < (int)v.size()-1; ++i) {
        if(v[i] > v[i+1]) {
            sorted = false;
            break;
        }
    }
    
    if(sorted)
        cout << i+1 << " | true\n";
    else 
        cout << i+1 << " | false\n";
}
