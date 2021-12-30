#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main(){
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int n, a, b, g;
    vector<int> vec = {0,1,2};

    cin >> n;
    vector<int> counter(3);

    
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> g; --a; --b; --g;

        swap(vec.at(a), vec.at(b));
        
        counter[vec[g]]++;
        
    }
    cout << max(max(counter[0], counter[1]),counter[2]);
    



}