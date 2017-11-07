#include <algorithm>
#include <iostream>
#include <sstream>
#include <cctype>
#include <vector>
#include <string>

/*
    if      0       number
    if      1       word
*/

using namespace std;

const int maxn = 110;

bool isNumber(string str){
    int len = str.length(), start;
    if(str[0] == '-' && len == 1)
        return false;
    else if(str[0] == '-')
        start = 1;
    else
        start = 0;
    for(int i = start; i < len; i++)
        if( (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') )
            return false;
    return true;
}

bool cmp(string first, string second){
    int i = 0;
    while((i < first.length()) && (i < second.length())){
        if(tolower (first[i]) < tolower (second[i])) 
            return true;
        else if(tolower (first[i]) > tolower (second[i]))
            return false;
        i++;
    }

    if(first.length() < second.length())
        return true;
    else 
        return false;
}

int main(){
    int len, index, in, iw, lens;
    string list, sub, answ;
    vector <string> words;
    vector <int> numbers;
    bool tipo[maxn];

    while(getline(cin, list)){
        len = list.length();
        if(len == 1)
            break;
        istringstream iss(list);
        in = iw = index = 0;
        answ = "";
        do{
            iss >> sub;
            lens = sub.length();
            if(isNumber(sub.substr(0, lens - 1))){
                tipo[index++] = false;
                numbers.push_back(atoi(sub.substr(0, lens - 1).c_str()));
            }else{
                tipo[index++] = true;
                words.push_back(sub.substr(0, lens - 1));
            }
        }while(iss);

        index--;
        if(tipo[index] == true)
            words.pop_back();
        else
            numbers.pop_back();

        sort(words.begin(), words.end(), cmp);
        sort(numbers.begin(), numbers.end());

        for(int i = 0; i < index; i++){
            if(tipo[i] == false){
                answ += to_string(numbers[in++]);
            }else{
                answ += words[iw++];
            }
            answ += (i + 1 < index ) ? ", " : ".";
        }

        cout << answ << endl;
        
        words.clear();
        numbers.clear();
    }

    return 0;
}