#include<bits/stdc++.h>

using namespace std;

bool consistent(string S, int len){
	bool consistent = true;
	for(int i = 0; i < len - 1; i++)
		if(S[i] != S[i+1])
			consistent = false;
	return consistent;
}

int countReplacement(char start, char goal, map<char, list<char> > replacements){
	map<char, list<char> >::iterator itt;
	list<char>::iterator itc;
	set <char>::iterator its;
	
	queue <pair<char, int> > BFS;
	pair <char, int> current;
	bool found = false;
	set <char> visited;
	int steps = 0;
	
	visited.clear();
	
	itt = replacements.find(start);
	if(itt != replacements.end()){
		BFS.push(make_pair(start, steps));
	}
	
	while(!BFS.empty() && !found){
		current = BFS.front();
		BFS.pop();
		visited.insert(current.first);
		
		if(current.first == goal){
			found = true;
			steps = current.second;
		}else{
			itt = replacements.find(current.first);
			if(itt != replacements.end()){
				for(itc = replacements[current.first].begin(); itc != replacements[current.first].end(); itc++){
					itt = replacements.find(*itc);
					its = visited.find(*itc);
					if((itt != replacements.end() && its == visited.end()) || (*itc == goal)){
						BFS.push(make_pair(*itc, current.second + 1));
					}
				}
			}
		}
		
	}
	
	if(found == false){
		return 0;
	}else{
		return steps;
	}
}

int main(){
	int T, K, len, steps, g_steps, min_steps;
	map <char, list<char> > replacements;
	set <char>::iterator it;
	set <char> characters;
	bool possible;
	string S, C;
	
	//freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout); 
	
	cin >> T;
	for(int i = 0; i < T; i++){
		cin >> S;
		len = S.length();
		
		cin >> K;
		replacements.clear();
		characters.clear();
		for(int j = 0; j < K; j++){
			cin >> C;
			replacements[C[0]].push_back(C[1]);
			characters.insert(C[0]);
			characters.insert(C[1]);
		}
		for(int j = 0; j < len; j++)
			characters.insert(S[j]);
		
		if(consistent(S, len)){
			cout << "Case #" << i + 1 << ": 0" << endl;
		}else{
			min_steps = INT_MAX;
			for (it = characters.begin(); it != characters.end(); it++){
				possible = true;
				g_steps = 0;
				for(int j = 0; j < len && possible; j++){
					if(S[j] != *it){
						steps = countReplacement(S[j], *it, replacements);
						if(steps == 0){
							possible = false;
						}else{
							g_steps += steps;
						}
					}
				}
				if(possible){
					min_steps = min(min_steps, g_steps);
				}
    		}
    		if(min_steps != INT_MAX){
    			cout << "Case #" << i + 1 << ": " << min_steps << endl;
			}else{
				cout << "Case #" << i + 1 << ": -1" << endl;
			}
		}
	}
	
	return 0;
}
