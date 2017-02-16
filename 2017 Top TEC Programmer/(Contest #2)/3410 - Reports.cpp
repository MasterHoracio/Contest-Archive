#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

template <typename T1, typename T2>
struct less_second {
    typedef pair<T1, T2> type;
    bool operator ()(type const&a, type const&b) const {
        return a.first < b.first;
    }
};


int main(){
	map <int, int> mapa;
	int n, year, cant;

	scanf("%d",&n);

	while(n--){
		scanf("%d %d",&year,&cant);
		(!mapa[year]) ? mapa[year] = cant : mapa[year] += cant;
	}

	vector<pair<int, int> > mapcopy(mapa.begin(), mapa.end());
	sort(mapcopy.begin(), mapcopy.end(), less_second<int, int>());

	for(int i = 0; i < mapcopy.size(); i++)
		printf("%d %d\n",mapcopy[i].first, mapcopy[i].second);

	return 0;
}