#include<iostream>
#include<vector>
using namespace std;
int main(){
	string line;
	while(1){
			cin.getline(line);
			stringstream linestream(line);
			linestream>>value;
			if(!value) break;
			vector<int> a(value);
			while(linestream>>value) a.push_back(value);
			cin.getline(line);linestream(line); linestream>>value;
			vector<int> b(value);
			while(linestream>>value) b.push_back(value);
			
