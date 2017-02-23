#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int tc, n, one, student, ans, search, temp;
	vector <int> circle, order_circle;
	bool change[1005];

	scanf("%d",&tc);

	while(tc--){
		scanf("%d",&n);
		fill(change, change + n, false);

		for(int i = 0; i < n; i++){
			scanf("%d",&student);
			circle.push_back(student);
			if(student == 1){
				one = i;
			}
		}

		for(int i = one; i < n; i++)
			order_circle.push_back(circle[i]);
		for(int i = 0; i < one; i++)
			order_circle.push_back(circle[i]);

		ans = 0;

		if(order_circle[1] == n){
			temp = order_circle[0];
			order_circle[0] = order_circle[1];
			order_circle[1] = temp;
			change[0] = true;
			change[1] = true;
			ans += 2;
		}

		for(int i = 0; i < n; i++){
			if(change[i])
				continue;
			(order_circle[i] == n) ? search = 1 : search = order_circle[i] + 1;
			//buscamos a la derecha
			if(i + 1 < n && order_circle[i + 1] == search){
				continue;
			}else{
				if(order_circle[0] == search)
					continue;
			}
			//buscamos a la izquierda
			if(i - 1 >= 0 && order_circle[i - 1] == search){
				temp = order_circle[i];
				order_circle[i] = order_circle[i - 1];
				order_circle[i - 1] = temp;
				change[i] = true;
				change[i - 1] = true;
				ans += 2;
				i--;
				continue;
			}else{
				if(order_circle[n - 1] == search){
					temp = order_circle[n - 1];
					order_circle[n - 1] = order_circle[i];
					order_circle[i] = temp;
					change[i] = true;
					change[n - 1] = true;
					ans += 2;
					i--;
					continue;
				}
			}
			//buscamos a la derecha de su derecha
			if(i + 2 < n && order_circle[i + 2] == search){
				temp = order_circle[i + 1];
				order_circle[i + 1] = order_circle[i + 2];
				order_circle[i + 2] = temp;
				change[i + 1] = true;
				change[i + 2] = true;
				ans += 2;
				i--;
				continue;
			}else{
				if(i == n - 1 && order_circle[1] == search){
					temp = order_circle[1];
					order_circle[1] = order_circle[0];
					order_circle[0] = temp;
					change[0] = true;
					change[1] = true;
					ans += 2;
					i--;
					continue;
				}else if(i == n - 2 && order_circle[0] == search){
					temp = order_circle[0];
					order_circle[0] = order_circle[n - 1];
					order_circle[n - 1] = temp;
					change[0] = true;
					change[n - 1] = true;
					ans += 2;
					i--;
					continue;
				}
			}
		}
		printf("%d\n",ans);
		circle.clear();
		order_circle.clear();
	}
	return 0;
}