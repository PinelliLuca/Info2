#include"tree.h"
#include"elemtype.h"

void CheckBoolRec( Node* t1, const Node* muovi, bool** ris, int n) { //ris punta al puntatore legato a bool ris iniziale
	if (TreeIsEmpty(muovi))
		return;
	//if (t1 != muovi) {
		if (*TreeGetRootValue(t1) + *TreeGetRootValue(muovi) == n)
			**ris = true; //funzione void, aggiorno questo per concludere la ricorsione
	//}
	CheckBoolRec(t1, TreeLeft(muovi), ris, n); //scorro tutto il secondo albero alla ricerca del nodo corretto
	CheckBoolRec(t1, TreeRight(muovi), ris, n); 
}

void CheckRec(const Node* t1, const Node* t2, bool* ris, int n) {
	if (TreeIsEmpty(t1))
		return;
	if (!(*ris)) { //se ris è tornato true da CheckBoolRec inutile proseguire: termino (return finale implicito)
		CheckBoolRec(t1, t2, &ris, n); 
		//aggiorno il nodo del primo albero, il quale rimarrà fisso mentre scorrerò i nodi del secondo
		CheckRec(TreeLeft(t1), t2, ris, n); 
		CheckRec(TreeRight(t1), t2, ris, n);
	}
}

bool CheckSumN(const Node* t, int n) {
	if (TreeIsEmpty(t) || (TreeIsEmpty(TreeLeft(t)) && TreeIsEmpty(TreeRight(t))))
		return false;
	bool ris = false;
	CheckRec(t, t, &ris, n);
	return ris;
}