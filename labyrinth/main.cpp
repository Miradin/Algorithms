#include <iostream>
using namespace std;

char a[50][50];
int xm, ym;
bool solved = false;

void f(int i, int j) {
    if (i<0 || j<0 || i>=xm || j>=ym || solved) return;
    char c = a[i][j];
    if (c=='#' || c=='*' || c=='B') {solved = c=='B'; return;}

    if (c==' ') a[i][j]='*';
    f(i+1, j);
    f(i, j-1);
    f(i-1, j);
    f(i, j+1);
    if (!solved) a[i][j]=' ';
}
int main() {
    int i=0, j=0, xs, ys;
    char c;
    while (cin.get(c)) {
        if (c=='\n') {xm=i-1; i=0; j++; continue;}
        if (c=='A') {xs=i; ys=j;}
        a[i++][j]=c;
    }
    ym=j;
    f(xs, ys);
    for(int j=0; j<ym; j++) {for(int i=0; i<xm; i++) cout<<a[i][j]; cout<<'\n';}
}
