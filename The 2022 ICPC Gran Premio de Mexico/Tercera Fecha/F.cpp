#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL);
    int n, c, max_count = -1;
    map <string, int> words;
    map <string, int>::iterator it;
    string ans = "", str;

    cin >> n >> c;

    for(int i = 0; i < n; i++){
        cin >> str;
        for(int j = 0; j < c; j++){
            if(str[j] == '*'){
                for(int k = 97; k <= 122; k++){
                    str[j] = k;
                    words[str] += 1;
                }
            }
        }
    }
    
    for (it = words.begin(); it != words.end(); it++){
        if(it->second > max_count){
            max_count = it->second;
            ans = it->first;
        }else if(it->second == max_count && it->first < ans){
            ans = it->first;
        }
    }
    
    cout << ans << " " << max_count << endl;

    return 0;
}