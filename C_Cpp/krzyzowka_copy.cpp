#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;


int policzWymiarSlow(){							//funkcja zliczaj�ca i zwracaj�ca ilo�� s��w w pliku 1.txt
	ifstream plik("1.txt");
	if (!plik) {
		cerr << "Error: nie mozna otworzyc pliku \"1.txt\"." << endl;
		exit(-1);
	}
	string slowo;
	int n = 0;
	while (plik >> slowo) n++;
	//cout << "W pliku 1.txt znaleziono " << n << " slow." << endl;			//pomocnicze drukowanie
	return n;
}
void sortuj(string* tab, int n) {				//sortowanie tablicy string'�w wed�ug d�ugo�ci string'a
	bool zmiana; 
	do {
		zmiana = false;
		for (int i = 0; i < n - 1; ++i) {
			//string a = (tab[i]);
			//string b = (tab[i + 1]);
			//int sA = tab[i].size();
			//int sB = tab[i + 1].size();
			if (tab[i].size() < tab[i + 1].size()) {
				swap(tab[i], tab[i + 1]);
				zmiana = true;
			}
		}
	} while (zmiana);
}
void drukuj(string* tab, int n){				//funkcja drukuj�ca tablic� string'�w
	for (int i = 0; i < n; i++){
		cout << tab[i] << endl;
	}
}
void drukuj(char* e[25][79]){					//funkcja drukuj�ca tablic� char
	for (int i = 0; i < 25; ++i){
		for (int j = 0; j < 79; ++j){
			cout << *e[i][j];
		}	cout << endl;
	}
}
/*
bool wstawPoziomo(char *e[][79], int indexWierszy, int indexKolumn, char litera, string slowo){
	if (isalpha(*e[indexWierszy][indexKolumn + 1] || isalpha(*e[indexWierszy][indexKolumn - 1]){ //test czy skrzyzowanie z wyrazem poziomym
		return false;
	else

		return true;
	}
}
*/


int main() {


	int wymiarSlow = policzWymiarSlow();					//zmienna przetrzymuj�ca ilo�� s��w w pliku 1.txt
	string *tabSlow = new string[wymiarSlow];				//utworzenie dynamicznej jednowymiarowej tablicy string'�w o wymiarze ilo�ci s��w
	ifstream plik("1.txt");
	for (int i = 0; i < wymiarSlow; i++){					//wpisanie s��w do tablicy string'�w
		plik >> tabSlow[i];
	}

	//drukuj(tabSlow, wymiarSlow);							//pomocnicze drukowanie

	sortuj(tabSlow, wymiarSlow);							//sortowanie tablicy s��w od najd�u�szego do najkr�tszego

	//cout << endl;											//pomocnicze drukowanie
	//drukuj (tabSlow, wymiarSlow);							//pomocnicze drukowanie

	//definicja 'ekran' i wype�nienie znakami "\0"
	const int W(25), K(79);
	char *ekran[W][K];
	for (int i = 0; i < W; ++i){
		for (int j = 0; j < K; ++j){
			ekran[i][j] = "\0";
		}
	}

	//"wpisanie" pierwszego, najd�u�szego s�owa z tablicy string�w (tabSlow) do ~�rodka tablicy wska�nik�w ekran
	const int s1stL = tabSlow[0].size();
	for (int i = 0; i < s1stL; ++i){
		ekran[12][38 + i - (s1stL / 2)] = &tabSlow[0][i];
	}
	
	//wyszukanie wsp�lnych liter dla kolejnego s�owa z tablicy string'�w
	int n = 0;
	for (int indexSlow = 1; indexSlow < wymiarSlow; ++indexSlow){
		for (size_t indexLiter = 0; indexLiter < tabSlow[indexSlow].size(); ++indexLiter){
			char literaSlowa = tabSlow[indexSlow][indexLiter];
			for (int indexWierszyEkran = 0; indexWierszyEkran < W; ++indexWierszyEkran){
				for (int indexKolumnEkran = 0; indexKolumnEkran < K; ++indexKolumnEkran){
					if (literaSlowa == *ekran[indexWierszyEkran][indexKolumnEkran]);
						//if (!wstawPoziomo(ekran, indexWierszyEkran, indexKolumnEkran, literaSlowa, tabSlow[indexSlow]));
					
					}
				}

		}
	}
	cout << n << endl;
	



	/*
	cout << "Projekt nr 1 \"Krzy��wka\" z przedmiotu Programowanie w j�zykach C i C++\n"
	<< "autor: Piotr Prystupa, s12463, grupa 11cn\"
	<< "PJWSTK 2013/2014" << endl;
	*/
	
	delete[] tabSlow;
	
}