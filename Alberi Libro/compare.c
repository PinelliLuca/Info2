#include"tree.h"
#include<stdlib.h>
#include<stdbool.h>

bool TreeAreIdentical(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return true;
	}
	if (TreeIsEmpty(t1) || TreeIsEmpty(t2)) {
		return false;
	}
	return ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) == 0 && //elemento corrente
		TreeAreIdentical(TreeLeft(t1), TreeLeft(t2)) && //chiamata ricorsiva a sx
		TreeAreIdentical(TreeRight(t1),TreeRight(t2)); //chiamata ricorsiva dx
}
//CORRETTO
//Ricorda chiamata ricorsiva per aggiornare (sx e dx) gli elemtni puntati da comparare
