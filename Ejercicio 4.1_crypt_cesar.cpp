#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int modulo(int a,int b)
	{
    int q=a/b;
    int res=a-(q*b);

    if (res<0){
        q--;
        res=a-(q*b);
    }
    return res;
	}
    string encriptar(string cadena,int clave){
    	string Alfamin="abcdefghijklmnopqrstuvwxyz";
    	string crypt(cadena.length(),' ');
    	int indice;
    	for(int i=0;i<cadena.length();i++){
			for(int j=0;j<Alfamin.length();j++){
				if(cadena[i]==Alfamin[j]){
					indice=modulo(j+clave,Alfamin.length());
					crypt[i]=Alfamin[indice];
				}
			}
		}
	return crypt;
	}
	int main(){
		int clave;
		cout<<"Ingrese la clave: ";
		cin>>clave;
		string mensaje="because the practice of the basic movements of kata is the focus and mastery of self is the essence of matsubayashi ryu karate do i shall try to elucidate the movements of the kata according to my interpretation based on forty years of study";
		string mensaje_crp=encriptar(mensaje,clave);
		cout<<mensaje_crp;
	}
