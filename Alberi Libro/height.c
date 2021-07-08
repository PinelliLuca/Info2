#include"tree.h"
void TreeHeightRec(const Node *t, int h_curr, int *h_best) {
	//caso base termino
	if (TreeIsEmpty(t))
		return;
	//sono arrivato ad una foglio e controllo se devo aggiornare il best
	if (TreeIsLeaf(t)) {
		if (h_curr > *h_best) {
			*h_best = h_curr;
		}
	}
	//proseguo
	TreeHeightRec(TreeLeft(t), h_curr + 1, h_best);
	TreeHeightRec(TreeRight(t), h_curr + 1, h_best);
}
int TreeHeight(const Node* t) {
	int h = -1;
	TreeHeightRec(t, 0,&h);
	return h;
} //CORRETTO
//Ricorda: per far sì che la funzione principale ricordi un paramentro aggiornato da una ausiliaria
//deve essere passato per indirizzo e aggiornata, all'interno dell'ausiliaria, sempre e solo da puntatore.
//Solo nella chiamata ricorsiva viene passata per paramentro