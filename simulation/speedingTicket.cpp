#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
//seg error -> .push_back vs [index]?
struct segment{
    int distance, speed;
};


vector<int> lieBetween(vector<segment> dl, pair<int,int> velocity){
    vector<int> nice;
    for(int i  = 0; i < dl.size(); i++){
        if (dl.at(i).distance >= velocity.first && dl.at(i).distance <= velocity.second){
            nice.push_back(i); //it - &ds
        }
    }
    // nice.push_back(velocity.first);
    // nice.push_back(velocity.second);
    return nice;

}

int main(){
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout); 

    int n,m; cin >> n >> m;
    vector<segment>dl, ds;
    segment curr;

    
    int ds_count = 0; int dl_count = 0; int temp;

    for (int i = 0; i < n; i++){
        cin >> temp >> curr.speed;
        dl_count += temp;
        curr.distance = dl_count;
        dl.push_back(curr);
    }

    for (int i = 0; i < m; i++){
        cin >> temp >> curr.speed;
        ds_count += temp;
        curr.distance = ds_count;
        ds.push_back(curr);
    }


int whateva = 0; int currentMax = 0;
     for(vector<segment>::iterator it = ds.begin(); it != ds.end(); ++it){
         pair<int,int> pr;
         pr.first = (it-1) -> distance;
         pr.second = it -> distance; 
         cout << "\n" << pr.first << " " << pr.second << "\n";
         for(int k : lieBetween(dl, pr)){
            cout << k << " ";
            whateva = (it -> speed) - dl.at(k).speed;

            currentMax = max(currentMax, whateva);
         }
         cout << "\n";
    }

// cout << currentMax;
    


}