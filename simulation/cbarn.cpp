#include <iostream>
#include <vector>

using namespace std;


int main(){
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);


    int n; cin >> n;

    vector<int>vi;

    int temp;
    int count = 0;

    for(int i = 0; i < n; i++){
        cin >> temp; vi.push_back(temp);
    }
    int general; int currMin;
    rec:
    general = 0;
    for(int i = 0; i < vi.size(); i++){
        general += (i * vi.at(i));
    }
    if(count == 0) currMin = general;
    else currMin = min(general, currMin);
    count++;
    vi.push_back(vi.at(0)); // cout << vi.at(0) << " atat \n"
    vi.erase(vi.begin()); // cout << *(vi.begin())
    if(count < n) goto rec;
    cout << currMin;
    return 0;
}


//TODO:
// how to rearrange array for any given vi[0];
// 
// 