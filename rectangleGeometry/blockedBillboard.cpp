#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;


struct rectangle{
    int x,y, x1, y1;
    int area(){
        return (x1 - x) * (y1 -y);
    }
};

int intersect(rectangle st, rectangle obs){
    return max(0, (min(st.x1, obs.x1) - max(st.x, obs.x))) * max(0,(min(st.y1, obs.y1) - max(st.y, obs.y)));
}

int main(){

    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);

    rectangle first;
    rectangle second;
    rectangle obs;

    cin >> first.x >> first.y >> first.x1 >> first.y1;
    cin >> second.x >> second.y >> second.x1 >> second.y1;
    cin >> obs.x >> obs.y >> obs.x1 >>obs.y1;

    cout << first.area() + second.area() - intersect(first, obs) - intersect(second,obs);
 

}
