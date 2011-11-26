#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
string a[1000];
double dec(string n){
	int l = n.length();
	long int a=0;
	for(int i=0; i < l; i++){
		if(n[i] == '1'){
			a+=pow(2,(double)l-i-1);
		}
	}
	return a;
}
string bin(int n){
	string x = "";
	while(n!=0){
		x = char(n%2+48) + x;
		n=n/2;
	}
	return x;
}
int main(){
	int count = 0;
	int count9 = 0;
	double suma9 = 0;
	int imax;
	ifstream dane;
	dane.open("dane.txt");
	int max=0;
	for(int i=0; i<1000; i++){
		getline(dane, a[i]);
		if(a[i][a[i].length()-1] == '0'){
		count++;
		}
		if(dec(a[i]) > max){
		max = dec(a[i]);
		}
		if(a[i].length() == 9){
			count9++;
			suma9+=dec(a[i]);
		}
	}
	
	cout << count << endl << max << endl << bin(max) << endl << count9 << endl << bin(suma9);
	cin >> a[1];
}