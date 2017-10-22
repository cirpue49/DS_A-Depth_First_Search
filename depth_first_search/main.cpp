//
//  main.cpp
//  depth_first_search
//
//  Created by 村上候助 on 2017/10/22.
//  Copyright © 2017 村上候助. All rights reserved.
//

#include <iostream>
#include <stdio.h>

#define n_max 100

using namespace std;

int n, t = 0;
int M[n_max][n_max], color[n_max], d[n_max], f[n_max];

void encode_graph(int n){
    int i, j, id, num, node;
    
    //initialize with 0
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            M[i][j] = 0;
        }
    }
    
    for (i = 0; i < n; i++){
        scanf("%d", &id);
        scanf("%d", &num);
        for(j = 0; j < num; j++){
            scanf("%d", &node);
            M[id-1][node-1] = 1;
        }
    }
}

void dfs(int u){
    color[u] = 1;
    d[u] = ++t;
    for (int v = 0; v < n; v++){
        if((M[u][v]) && (color[v] == 0)){
            dfs(v);
        }
    }
    color[u] = 2;
    f[u] = ++t;
}

void dfs_init(int n){
    for(int i = 0; i < n ; i++){
        color[i] = 0;
    }
    dfs(0);
}


int main(int argc, const char * argv[]) {
    scanf("%d", &n);
    
    encode_graph(n);
    
    dfs_init(n);
    
    for(int i = 0; i < n; i++){
        cout<<i+1<<" "<<d[i]<<" "<< f[i]<<endl;
    }
    
//    std::cout << "Hello, World!\n";
    return 0;
}
