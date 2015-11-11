/*=============================================================================
# Author:            He Shuwei
# Last modified:     2015-07-15 09:57
# Filename:         a.cpp
# Description: 
=============================================================================*/
 
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define lson l, mid, ls
#define rson mid, r, rs
#define ls (rt << 1) + 1
#define rs (rt << 1) + 2
#define ABS(a) ((a) < 0 ? (-(a)) : (a))
#define Min(a, b) ((a) > (b) ? (b) : (a))
#define Max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

const int MAXN = 100010;

struct Node{
    int v, nxt;
};

int n, m, E_cnt;
int head[MAXN];
int val[MAXN];
bool vis[MAXN];
long long dp[MAXN];
Node node[2 * MAXN];
long long sum, ans;

void init(){
    E_cnt = sum = 0;
    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    memset(node, 0, sizeof(node));
    memset(head, -1, sizeof(head));
}

void addEdge(int u, int v){
    node[E_cnt].v = v;
    node[E_cnt].nxt = head[u];
    head[u] = E_cnt++;
}

void dfs(int s){
    dp[s] = val[s];
    for(int i = head[s]; i + 1; i = node[i].nxt){
        if(vis[node[i].v]) continue;
        else vis[node[i].v] = true;
        dfs(node[i].v);
        dp[s] += dp[node[i].v];
    }
    ans = Min(ans, ABS(sum - 2 * dp[s]));
}

int main(){
    int dx = 1;
    while(scanf("%d%d", &n, &m) != EOF){
        if(!(n + m)) break;
        init();
        int va;
        for(int i = 1; i <= n; i++){
            scanf("%d", &va);
            val[i] = va;
            sum += va;
        }
        int u, v;
        for(int i = 0; i < m; i++){
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }
        ans = sum;
        vis[1] = true;
        dfs(1);
        printf("Case %d: %I64d\n", dx++, ans);
    }
    return 0;
}