#define _CTR_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

/*n  regine, mai in conflitto tra loro.
Tavola di n_size x n_size, le regine attaccano su stessa riga, stessa colonna, diagonali*/
typedef struct {
	size_t side;
	bool* row; //row[i]=true significa che la riga i-esima è sotto attacco
	bool* col;
	bool* diag_p; //diag_p[i]=true diagonale principale i-esima è sotto attacco
	bool* diag_s;
	int* placing; //vettore che memorizza la posizione di ogni regina, data da (placing[i],i) con i in [0,side-1].
				//Quindi dato l'indice di colonna i, in placing[i] ho l'indice di riga in cui è stata posizionata la regina
} Chessboard;
static void PrintChessboard(const Chessboard* board) {
	for (int r = 0; r < (int)(board->side); ++r) {
		for (int c = 0; c < (int)(board->side); ++c) {
			if (board->placing[c] != -1 && r == board->placing[c])
				printf("[Q]");
			else
				printf("[ ]");
		}
		puts("");
	}
	puts("");
}
static void PlaceQueensRec(Chessboard* board, int i, int n_queens, int placed_queens, int* nsol) {
	//caso base: ho posizionato tutte le regine
	if (placed_queens == n_queens) {
		(*nsol)++;
		printf("Sol %d\n", *nsol);
		PrintChessboard(board);
		return;
	}
	for (int p = i; p < (int)(board->side * board->side); ++p) {
		//p indice di casella-> indice di matrice pos
			//tramite p calcolo gli indici di riga e colonna
		int r = p / board->side;
		int c = p % board->side;

		//condizioni
		if (!board->row[r] && !board->col[c] && !board->diag_s[r + c] && !board->diag_p[r - c + board->side - 1]) {
			board->row[r] = board->col[c] = board->diag_p[r - c + board->side - 1] = board->diag_s[r + c] = true;
			board->placing[c] = r; //ricorda: placing vettore di [0,side-1] con indice di colonna setto l'indice di riga in cui è posizionata la regina
			//invoco per la prossima regina
			PlaceQueensRec(board, i + 1, n_queens, placed_queens + 1, nsol);
			//rimuovo la regina per la prossima chiamata
			board->row[r] = board->col[c] = board->diag_p[r - c + board->side - 1] = board->diag_s[r + c] = false;
			board->placing[c] = -1;
		}
	}
}
int PlaceQueens(int chessboard_side, int n_queens) {
	int cs = chessboard_side;
	Chessboard board = { .side = cs,
		.row = calloc(cs,sizeof(bool)),.col = calloc(cs,sizeof(bool)),
		.diag_p = calloc(2 * cs - 1,sizeof(bool)),
		.diag_p = calloc(2 * cs - 1,sizeof(bool)),
		.placing = malloc(cs * sizeof(int)) };
	memset(board.placing, -1, chessboard_side * sizeof(int)); //pongo a -1 tutti i valori di regine piazzate
	int nsol = 0;
	int ncall = 0;
	PlaceQueensRec(&board, 0, n_queens, 0, &nsol);
	return nsol;
}

int main() {
	int s;
	s = PlaceQueens(3, 2);
	printf("\nSoluzioni: %d", s);
	s = PlaceQueens(3, 3);
	printf("\nSoluzioni: %d", s);
	s = PlaceQueens(4, 3);
	printf("\nSoluzioni: %d", s);
}

//esercizio non funzionante: problema di memoria
//probabile errore di distrazione, idea corretta