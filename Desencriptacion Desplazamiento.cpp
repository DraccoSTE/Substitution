#include <bits/stdc++.h>
using namespace std;

string alfabeto = "abcdefghijklmnopqrstuvwxyz";

string desencriptar_clave(string txt, int key){
	string copy_txt = txt;
	for (int i = 0; i <  copy_txt.size(); i++){
		if (copy_txt[i] == ' ') continue;
		copy_txt[i] = alfabeto[(int(copy_txt[i])-97+key) % alfabeto.size()];
	}
	return copy_txt;
}

bool verify_txt(string txt){
	int op;
	cout << "\n" << txt <<"\n\nEste texto guarda sentido?\n1 - Si\n0 - No (Try again)\n\nOpcion: ";
	cin >> op;
	if (op == 1) return true;
	return false;
}

string desencriptar(string txt){
	
	// Criptanalisis
	
	map <char, int> frecuencia;
	vector <pair <int, char> > frecuencia_sort;
	string english_statics = "etaoinshrdlcumwfgypbvkjxqz";
	
	for (int i = 0; i < txt.size(); i++){
		if (txt[i] == ' ') continue;
		frecuencia[txt[i]] ++;
	}
	
	for (auto it = frecuencia.begin(); it != frecuencia.end(); it ++){
		frecuencia_sort.push_back(make_pair(it->second, it->first));
	}
	
	sort(frecuencia_sort.begin(), frecuencia_sort.end());
	
	
	// Desencriptacion
	int key;
	string try_txt;
	
	for (int i = 0; i < english_statics.size(); i ++){
		
		for (int j = frecuencia_sort.size()-1; j >= 0; j--){
			
			key = (int(frecuencia_sort[j].second) - int(english_statics[i]));
			if (key < 0) key += alfabeto.size();

			try_txt = desencriptar_clave(txt, alfabeto.size() - key);
			if (verify_txt(try_txt)){
				return try_txt;
			}
			
		}
	}
	
	cout << "\n\nWe cant find the answer :(\n\n";
	
	return "";
}

int main(){
	
	string txt;
	cout << "Insert English text: \n";
	getline(cin, txt);
	
	desencriptar(txt);
	
	/*
	desencriptar("wx bn cpbt xh bxrwpta x b p egduthhxdcpa qphfjtiqpaa eapntg");
	desencriptar("wx x pb p rdda vjn iwpi zcdl adi du iwxcvh");
	desencriptar("ij nz gsjfoe ipx zpv hpjoh");
	*/

	
	return 0;
}
