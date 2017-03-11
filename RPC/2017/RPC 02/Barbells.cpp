#include <cstdio>
#include <map>

#define maxn 15

using namespace std;

typedef long long int lld;

lld barbells[maxn], plates[maxn];

int main(){
	lld limit, left, rigth, weight, temp;
	map <lld, lld>::iterator it;
	map <lld, lld> weights;
	int nbarbells, nplates;

	scanf("%d %d",&nbarbells, &nplates);

	for(int i = 0; i < nbarbells; i++)
		scanf("%lld",&barbells[i]);

	limit = 1;
	for(int i = 0; i < nplates; i++){
		scanf("%lld",&plates[i]);
		limit *= 3;
	}

	for(int i = 0; i < limit; i++){
		weight = i;
		left = rigth = 0;
		for(int j = 0; j < nplates; j++){
			temp = weight % 3;
			if(temp == 0) left += plates[j];
			else if(temp == 1) rigth += plates[j];
			weight /= 3;
		}
		if(left == rigth){
			for(int j = 0; j < nbarbells; j++)
				if(!weights[barbells[j] + left + rigth])
					weights[barbells[j] + left + rigth] = 1;
		}
	}

	for(it = weights.begin(); it != weights.end(); it++)
		printf("%lld\n", it -> first);

	return 0;
}