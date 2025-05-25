#include "Tree.h"
#include "Graph.h"
#include <fstream>

using namespace std;
int main() {
	cout << "Vrsi se kreiranje stabla na osnovu txt fajl,ispis je level order:" << endl;
	Tree t;
	string UlazniFajl = "Upis.txt";
	ifstream Ulaz(UlazniFajl);
	string linija;
	int b = 0;
	int c = 0;

	while (getline(Ulaz, linija)) {
		ListString* ulaz = CreateStringList(linija);
		if (t.GetRoot() == nullptr) t.EnterEmptyTree(ulaz);
		else t.EnterTree(ulaz);
		DeleteList(ulaz);

	}
	Ulaz.close();

	t.PrintLevelOrder();

	cout << "Ako zelite da dodate novi programski stek unesite 1,ako zelite brisanje programskog steka unesite 2," << endl;
	cout<< "ako zelite prikaz suseda za graf pritisnite 3:"<<endl;
	cin >> b;
	cin.ignore();
	cout << endl;
	if (b == 1) {
		cout << "Unesite programski stek:" << endl;
		string get;
		getline(cin, get);
		ListString* ulaz = CreateStringList(get);
		if (t.GetRoot() == nullptr) t.EnterEmptyTree(ulaz);
		else t.EnterTree(ulaz);
		DeleteList(ulaz);
		t.PrintLevelOrder();

	}

	if (b == 2) {

		cout << "Unesite programski stek za brisanje:" << endl;
		string get1;
		getline(cin, get1);
		cin.clear();
		//cin.ignore();

		ListString* ulaz1 = CreateStringList(get1);
		t.DeleteLine(ulaz1);

		DeleteList(ulaz1);
		t.PrintLevelOrder();



	}

	if (b == 3) {
		Graph g(t);
		g.Ispis();
	}


	return 0;
}