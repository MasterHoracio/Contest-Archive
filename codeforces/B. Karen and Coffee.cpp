#include <cstdio>

using namespace std;

const int LIMITS = 2e5 + 10;

struct node{
	node(){
		n_nodes = 0;
		admissible = 0;
	}
	int n_nodes, admissible;	
}tree[LIMITS * 4];

void update_tree(int izq, int der, int l, int r, int root){
	
	if(izq == l && der == r){
		tree[root].n_nodes++;
		return;
	}
	
	int mid = (l + r) / 2;
	
	if(der <= mid){//ESTA A LA IZQUIERDA
		update_tree(izq, der, l, mid, root * 2);
	}else if(izq > mid){//ESTA A LA DERECHA
		update_tree(izq, der, mid + 1, r, root * 2 + 1);
	}else{//ESTA EN EL RANGO
		update_tree(izq, mid, l, mid, root * 2);
		update_tree(mid + 1, der, mid + 1, r, root * 2 + 1);
	}
}

void relax(int l, int r, int root, int k){
	if(l == r){
		if(tree[root].n_nodes >= k)
			tree[root].admissible = 1;
		return;
	}
	
	int mid = (l + r) / 2;
	
	tree[root * 2].n_nodes += tree[root].n_nodes;
	relax(l, mid, root * 2, k);
	
	tree[root * 2 + 1].n_nodes += tree[root].n_nodes;
	relax(mid + 1, r, root * 2 + 1, k);
	
	tree[root].admissible = tree[root * 2].admissible + tree[root * 2 + 1].admissible;
}

int query(int izq, int der, int l, int r, int root){
	if(izq == l && der == r){
		return tree[root].admissible;
	}
	int ans = 0;
	int mid = (l + r) / 2;
	if(der <= mid){
		ans = query(izq, der, l, mid, root * 2);
	}else if(izq > mid){
		ans = query(izq, der, mid + 1, r, root * 2 + 1);
	}else{
		ans = query(izq, mid, l, mid, root * 2) + query(mid + 1, der, mid + 1, r, root * 2 + 1);
	}
	return ans;
}

int main(){
	int n, k, q, li, ri;
	
	scanf("%d %d %d",&n,&k,&q);
	
	for(int i = 0; i < n; i++){
		scanf("%d %d",&li,&ri);
		update_tree(li, ri, 1, 200000, 1);
	}
	
	relax(1, 200000, 1, k);
	
	for(int i = 0; i < q; i++){
		scanf("%d %d",&li,&ri);
		printf("%d\n",query(li, ri, 1, 200000, 1));
	}
	
	return 0;
}
