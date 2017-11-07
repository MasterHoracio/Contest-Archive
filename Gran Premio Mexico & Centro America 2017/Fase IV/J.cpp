#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

map <int ,int> parent;//save the number of parents
map <int, int> n_node;//save the number of nodes

void makeset(int s){
    parent[s] = s;
    n_node[s] = 0;
}

int _find(int f){
    if(parent[f] == f)
        return f;
    else
        return _find(parent[f]);
}

void _union(int p, int q){
    int setp, setq;
    setp = _find(p);
    setq = _find(q);

    if(setp == setq)
        return;

    if(n_node[setp] > n_node[setq]){
        parent[setq] = setp;
    }else if(n_node[setq] > n_node[setp]){
        parent[setp] = setq;
    }else{
        parent[setp] = setq;
        n_node[setq]++;
    }

}

int countSubsets(char c){
    map<int, int> szsubset;
    int par;

    for(int i = 'A'; i <= c; i++){
        par = _find(i);
        if(!szsubset[par])
            szsubset[par] = true;
    }

    return szsubset.size();
}

int main(){
    char str[3], c;
    bool read = false;
    int len, answ;

    while(gets(str)){
        len = strlen(str);
        if(len == 0){
            answ = countSubsets(c);
            parent.clear();
            n_node.clear();
            printf("%d\n",answ);
        }else if(len == 1){
            c = str[0];
            read = true;
            for(int i = 'A'; i <= c; i++)
                makeset(i);
        }else{
            _union(str[0], str[1]);
        }
    }

    answ = countSubsets(c);
    parent.clear();
    n_node.clear();
    printf("%d\n",answ);

    return 0;
}
