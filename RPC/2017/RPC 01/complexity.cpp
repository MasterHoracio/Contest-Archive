#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

template <typename T1, typename T2>
struct less_second {
    typedef pair<T1, T2> type;
    bool operator ()(type const&a, type const&b) const {
        return a.second < b.second;
    }
};

int main(){
	map <char, int> mapa;
	string str;
	int len, ans = 0, min = 0;

	cin >> str;

	len = str.length();

	for(int i = 0; i < len; i++){
		if(!mapa[str[i]]){
			mapa[str[i]] = 1;
			ans++;
		}else{
			mapa[str[i]]++;
		}
	}

	vector<pair<char, int> > mapcopy(mapa.begin(), mapa.end());
	sort(mapcopy.begin(), mapcopy.end(), less_second<char, int>());

	for(int i = 0; i < ans - 2; i++){
		min += mapcopy[i].second;
	}

	cout << min << "\n";
}