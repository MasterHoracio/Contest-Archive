#include <bits/stdc++.h>

using namespace std;

const int limits = 1000000 + 10;
const int maxn = 2097151;

int min_tree[maxn], arr[limits], max_tree[maxn];

int build_min_tree(int node, int start, int end){
	if(start == end){
		min_tree[node] = arr[start];
		return min_tree[node];
	}
	int mid = (start + end)/2;
	min_tree[node] = min(build_min_tree(node * 2, start, mid), build_min_tree((node * 2) + 1, mid + 1, end));
	return min_tree[node];
}

int build_max_tree(int node, int start, int end){
	if(start == end){
		max_tree[node] = arr[start];
		return max_tree[node];
	}
	int mid = (start + end)/2;
	max_tree[node] = max(build_max_tree(node * 2, start, mid), build_max_tree((node * 2) + 1, mid + 1, end));
	return max_tree[node];
}

int min_query(int left, int right, int start, int end, int node){
	if(start >= left && end <= right){//overlap
		return min_tree[node];
	}
	if(right < start || left > end){
		return INT_MAX;
	}
	int mid = (start + end)/2;
	int query = min(min_query(left, right, start, mid, node * 2), min_query(left, right, mid + 1, end, (node * 2) + 1 ));
	return query;
}

int max_query(int left, int right, int start, int end, int node){
	if(start >= left && end <= right){//overlap
		return max_tree[node];
	}
	if(right < start || left > end){
		return -9999999;
	}
	int mid = (start + end)/2;
	int query = max(max_query(left, right, start, mid, node * 2), max_query(left, right, mid + 1, end, (node * 2) + 1 ));
	return query;
}

int main(){
	cin.tie(0);
    ios::sync_with_stdio(0);
	int n, w, k, mini, maxi, dif_min, dif_max;
	bool check;
	
	while(cin >> n >> w >> k){
		if(n == 0 && w == 0 && k == 0)
			break;
		
		for(int i = 0; i < n; i++)
			cin >> arr[i];
		
		build_min_tree(1, 0, n - 1);
		build_max_tree(1, 0, n - 1);
		
		check = true;
		
		for(int i = w; i < n && check; i++){
			mini = min_query(i - w, i - 1, 0, n - 1, 1);
			maxi = max_query(i - w, i - 1, 0, n - 1, 1);
			dif_min = abs(arr[i] - mini);
			dif_max = abs(arr[i] - maxi);
			if(dif_min > k || dif_max > k)
				check = false;
		}
		
		(check) ? cout << "Yes.\n" : cout << "No.\n";
		
	}
	
	return 0;
}
