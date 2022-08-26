#include <iostream>
#include <sstream>
#include <map>

using namespace std;

void countFreq(const string s){
    stringstream str;
    str << s;
    map<string, int>Freq;
    string word;
    while(str >> word) {
        Freq[word]++;
    }
    
    map<string, int>::iterator it;
    for(it = Freq.begin(); it != Freq.end(); it++){
        cout << it->first << " " << it->second << endl;
    }
}

int main()
{
    
    const string s = "my name is Khan my bame is Khan";
    
    countFreq(s);
    

    return 0;
}