#include "list.h"
#include<iostream>
using namespace std;
int main() {
    List a;

    bool isStop = false;
    while(!isStop) {
        int n; cin >> n;
        switch (n)
        {
            double x; int idx;
            case -1:
                isStop = true;
                break;
            case 0:
                cin >> x;
                a.add(x);
                break;
            case 1:
                cin >> x;
                a.remove_first(x);
                break;
            case 2:
                cin >> x;
                a.remove_all(x);
                break;
            case 3:
                cin >> idx >> x;
                a.replace(idx, x);
                break;
            
            default:
                break;
        } 
    }
    a.Xuat();
}