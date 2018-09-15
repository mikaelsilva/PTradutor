#include <iostream>
#include <vector>
#include <algorithm>
#include <ctype.h>
#include <string>

using namespace std;



int main (){
	pair <string,int> temp;
	vector < pair<string,int> > vetor;
	int i,ok=0,sair=0;
	string palavra;

	while(sair == 0){
	cout<<"AQUI"<<"\n";
	cin>>temp.first>>temp.second;
	for(i=0;i<(int)vetor.size();i++){
		if(temp.first ==  vetor[i].first){
			vetor[i].second++;
			ok=1;
		}
	}

	if(ok!=1){
		temp.second=1;
		vetor.push_back(temp);
		ok=0;
	}
	cin>>sair;
}

	for(i=0;i<(int)vetor.size();i++){
		cout<<vetor[i].first<<" e "<<vetor[i].second<<"\n";
	}

	return 0;
}





/*
vector <int> vetor;
	vetor.push_back(valor);
	vetor.push_back(valor);
	vetor.pop_back();
	sort(vetor.begin(),vetor.end());
	vetor.clear();
*/

/*
	pair<string,int> vetorPair;
	vetorPair.first = "UMASTRING";
	vetorPair.second = valor;
	
	if(vetorPair.second > 9){
		cout<<"DEU CERTO"<<"\n";
	}

	//make_pair
	sort(vetorPair.begin(),vetorPair.end());
*/