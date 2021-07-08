#include"tree.h"

Node* BstInsertRec(const ElemType* e, Node* n) {
	//caso base
	if (TreeIsEmpty(n)) { 
		return TreeCreateRoot(e, TreeCreateEmpty(), TreeCreateEmpty());
	}
	if (ElemCompare(e, TreeGetRootValue(n)) <= 0) {
		//va a sinistra e assegno il nuovo nodo
		n->left = BstInsertRec(e, TreeLeft(n));
	}else {//oppure
		//va a destra e assegno il nuovo nodo
		n->right = BstInsertRec(e, TreeRight(n));
	}
	//necessario per aggiornare i valori puntati. Dopo aver fatto il return del caso base rientra nella funzione con
	//n->right e poi continua con return n
	return n;
}