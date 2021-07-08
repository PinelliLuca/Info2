#include"tree.h"


Node* GetNodeWithMaximumKey(Node* n) {
	while (!TreeIsEmpty(TreeRight(n))) {
		n = TreeRight(n);
	}
	return n;
}

Node* DeleteBstNodeRec(Node* n, const ElemType* key) {
	if (TreeIsEmpty(n)) {
		return NULL;
	}
	//scorro fino a trovare il valore da eliminare
	if (ElemCompare(key, TreeGetRootValue(n)) < 0) {
		n->left = DeleteBstNodeRec(TreeLeft(n), key);
	}
	if (ElemCompare(key, TreeGetRootValue(n)) > 0) {
		n->right = DeleteBstNodeRec(TreeRight(n), key);
	}
	else {
		//caso 1: il nodo da eliminare è una foglia
		if (TreeIsLeaf(n)) {
			TreeDelete(n);
			return NULL;
		}
		//caso 2: il nodo da eliminare ha entrambi i figli
		else if (TreeLeft(n) && TreeRight(n)) {
			//trovo il predecessore
			Node* predecessor = GetNodeWithMaximumKey(TreeLeft(n));

			// Copio il valore del predecessore nel nodo corrente ed
			  // elimino il predecessore ricorsivamente. Il predecessore
			  // ha al più il figlio sinistro.
			ElemDelete(&n->value);
			n->value = ElemCopy(TreeGetRootValue(predecessor));
			n->left = DeleteBstNodeRec(TreeLeft(n), TreeGetRootValue(predecessor));
			return n;
		}

		//3:il nodo da eliminare ha solo un figlio
		else {
			//quale?
			Node* child = (TreeLeft(n)) ? TreeLeft(n) : TreeRight(n); //se esiste il figlio sx è il figlio sx altrimenti l'unico presente cioè il dx
			//scambio con variabile temporanea
			//curr assume il puntatore dell'albero originale n
			Node* curr = n;
			//n assume il valore del figlio scelto precedentemente
			n = child;
			//devo eliminare il valore in memoria contenuto ora in cur e non più in n
			ElemDelete(&curr->value);
			//ritorno l'albero originale ora modificato

			return n;
		}
	}
}

Node* DeleteBstNode(Node* n, const ElemType* key) {
	return DeleteBstNodeRec(n, key);
}