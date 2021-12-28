#include <iostream>
#include <cmath>
using namespace std;


struct Coord{
    int x,y;
};

struct Rect{
    int a,b,c,d;
    Coord bl(){
        Coord bl;
        bl.x = a;
        bl.y = b;
        return bl;
    }

    Coord tr(){
        Coord tr;
        tr.x = c;
        tr.y = d;
        return tr;
    }
};

void init(Rect*rect, int a, int b, int c, int d){
    rect ->a = a;
    rect ->b = b;
    rect ->c = c;
    rect ->d = d;

};

int intersection(Rect w, Rect b){
    int f;
    f = max(0,(min(w.tr().x, b.tr().x) - max(w.bl().x, b.bl().x))) * max(0,(min(w.tr().y, b.tr().y) - max(w.bl().y, b.bl().y)));
   

    return f;
}

void rectAfterInter(Rect a, Rect b, int * pos){
    pos[0] = max(a.bl().x, b.bl().x); 
    pos[1] = max(a.bl().y, b.bl().y); 
    pos[2] = min(a.tr().x, b.tr().x); 
    pos[3] = min(a.tr().y, b.tr().y); 
}

int main(){
    Rect w, first, second;

    int a,b,c,d,e,f,g,h,i,j,k,l;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l;
    init(&w,a,b,c,d); init(&first,e,f,g,h); init(&second,i,j,k,l);

    Rect i_rect, i_rectII;
    int pos2[4];
    int pos[4];
    rectAfterInter(w,first, pos2); rectAfterInter(w,second, pos);

    
    init(&i_rect, pos2[0], pos2[1], pos2[2], pos2[3]);
    init(&i_rectII, pos[0], pos[1], pos[2], pos[3]);

    
    unsigned long long int w_area = (w.tr().x - w.bl().x) * (w.tr().y - w.bl().y);
    if (intersection(w,first) + intersection(w, second) - intersection(i_rect, i_rectII) >= w_area) cout << "NO";
    else cout << "YES";

    // cout << "\n" << " " << intersection(w,first) << " + " << intersection(w, second) << " - " << intersection(i_rect, i_rectII) << " = " << intersection(w,first) + intersection(w, second) - intersection(i_rect, i_rectII) << " vs "  << w_area;

    
}
