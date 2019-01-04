#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct{
    int n, v, w;
}Item;

bool cmp(Item a, Item b){
    return a.v/a.w > b.v/b.w;
}

int main(int argc, char *argv[]){
    int n, W;
    scanf("%d%d", &n, &W);
    Item ite[n];
    for (int i=0; i<n; i++) {
        scanf("%d%d", &ite[i].v, &ite[i].w);
        ite[i].n = i+1;
    }
    sort(ite, ite+n, cmp);
    
    int maxV=0;
    for (int i=0; i<n; i++) {
        if (ite[i].v > ite[maxV].v) {
            maxV = i;
        }
    }
    
    vector<int> okna, nkna;
    for (int V=0; V<1e9; V++) {
        for (int i=0; i<n; i++) {
            
        }
    }
    sort(okna.begin(), okna.end());
    printf("%d\n", (int)okna.size());
    for (int i=0; i<okna.size(); i++) {
        printf("%d%c", okna[i], (i<okna.size()-1)? ' ':'\n');
    }
    return 0;
}
