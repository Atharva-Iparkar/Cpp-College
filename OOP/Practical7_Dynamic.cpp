#include <iostream>
#include <map>
using namespace std;
int main () {
typedef map<string, int> mapType;
mapType populationMap;

int n;
cout<<"Enter the size of the map : ";
cin>>n;
for (int i=0; i<n; i++) {
string state;
int population;
cout<<"Enter name of the state : ";
cin>>state;
cout<<"Enter population of the state : ";
cin>>population;
populationMap.insert(pair<string, int>(state, population));
}

mapType :: iterator iter;
cout<<"\nSize of population map is : "<<populationMap.size()<<endl;

string statename;
cout<<"Enter name of the state : ";
getline(cin>>ws, statename);
iter = populationMap.find(statename);
if (iter != populationMap.end())
cout<<statename<<"'s population is : "<<iter -> second<<endl;
else
cout<<"Key is not in the population Map"<<endl;
populationMap.clear();
return 0;
}

