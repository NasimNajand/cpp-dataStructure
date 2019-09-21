#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

void print(vector<int> &vec)
{
	cout << "{";
	for(auto i = vec.begin(); i != vec.end(); i++)
	{
		cout << *i;
		if(i != vec.end()-1) cout << ", ";
	}	
	cout << "}";
	cout<<endl;
	
}
void diceSumHelper(int dice, int diceSum, vector<int> &chosen)
{
    if(dice==0){
        if(diceSum==0) {
            print(chosen);
        }
    }else if (diceSum >= dice*1 && diceSum <= dice*6){
        //chosen
        for(int i=1;i<=6;i++){
            chosen.push_back(i);
        //explore
            diceSumHelper(dice-1,diceSum-i,chosen);
            
        //unchosen
            chosen.pop_back();
          
        }
    }
}

void diceSum(int dice, int diceSum)
{
    vector<int> v;
    diceSumHelper(dice, diceSum, v);
}
int main() 
{
	diceSum(3,10);
    return 0;
}

