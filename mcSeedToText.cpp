#include <iostream>
#include <map>
using namespace std;

int myPow(int x, unsigned int p)
{
  if (p == 0) return 1;
  if (p == 1) return x;
  
  int tmp = myPow(x, p/2);
  if (p%2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
}

int seed = 64149200;
string starts = "LiveOverflow";

int hashStr(string input){
    int h = -1764724434; // hash of LiveOverflow
    if(input.size()>0){
        for(int i=0;i<input.size();i++){
            h = h * 31 + (int) input[i];
        }
    }
    return h;
}

int maxLength = 8;
//This is the 'A' char 56
int minValue = 48;
//This is the 'z' char 122
int maxValue = 57;

bool increment(string & s){
    if((int) s[0]>maxValue){
        return false;
    }
    int n = s.size();
    s[n - 1] = (char) (s[n-1] + 1);
    if((int) s[n - 1] > maxValue){
        for(int i=n-1;i>0;i--){
            if((int) s[i] > maxValue){
                s[i] = (char) minValue;
                if(i>0)
                    s[i-1] = (char) (s[i-1] + 1);
            }
        }
    }
    
    return s[0]<=maxValue;

}

int findSeeds(){
    map<int, string> prevHashes;
    for(int j=1;j<=maxLength;j++){
        string s(j, (char) minValue);
        prevHashes.clear();

        while(increment(s)){
            //cout << s << endl;
            int h = hashStr(s);
            if(h == seed){
                cout << "LiveOverflow" << s << endl;
            }
            // I thought I was awesome but this doesn't work, might look later
            /*prevHashes.insert(pair<int,string>(h, s));
            int yHash = seed-(myPow(31, j+12)*h);
            if(prevHashes.find(yHash)!=prevHashes.end()){
                cout << "LiveOverflow" << prevHashes[yHash] << endl;
            }*/
        }

    }
    return 0;
}

int main(){
    cout << "Started!" << endl;
    findSeeds();

    //cout << hashStr("Bigc");
    //string a = "zz";
    //cout << increment(a) << " " << a << endl;
    return 1;
}