# include <stdio.h>
# include <stdlib.h> 
# include <time.h>
# include "mapa.h"

MAPA m;
POSICAO p;
POSICAO f;


int main(){
	lerMapa(m);
	
	encontrarJogador(&m, &p);
	
	char tecla;
	
	do {
		 desenharMapa(&m);
		 scanf(" %c", &tecla);
		 movimentar(tecla);
		 fantasmas(&m, &f);
		
	} while (!acabou());
	liberarMapa(&m);
	
	return 0; 
}

	void lerMapa(MAPA* m) {
		
		FILE* arq;
		arq = fopen("mapa1.txt", "r");
		if(arq == 0) {
			printf("Erro na leitura do mapa");
			exit(1);
		}
		
		fscanf(arq, "%d %d", &(m->linhas), &(m->colunas));
		alocarMapa(m);
		
		for(int i = 0; i < m->linhas; i++) {
			fscanf(arq, "%s", m->matriz[i]);
		}
		
		fclose(arq);
		
	}
	
	void alocarMapa(MAPA* m) {
		m->matriz[i] = malloc(sizeof(char*) * m->linhas);
		
		for(int i = 0; i < m->mlinhas; i++) {
			m->matriz[i] = malloc(sizeof(char) * m->colunas + 1);
			
		}
	}
	
void desenharMapa(MAPA* m) {
		for(int i = 0; i < m->linhas; i++) {
			for(int j = 0; j < m->colunas; j++) {
				printf("%c", m->matriz[i][j]);
			}
			printf("\n");	
		}
	}
	
	void liberarMapa(MAPA* m) {
		for(int i = 0; i < m->linhas; i++) {
			free(m->matriz[i]);
		}
		free(m);
	}
	
int acabou () {
	return 0;
}

int encontrarJogador(MAPA* m, POSICAO* p) {
	for(int i = 0; i < m->linhas; i++) {
		for (int j = 0; j < m->colunas; j++) {
			if(m->matriz[i][j] == HEROI) {
				p->x = i;
				p->y = j;
				return 1;
			}
		}
	}
	
	return 0;
}

void movimentar(char direcao) {
	int proximox = p.x;
	int proximoy = p.y;
	
	switch (direcao) {
		
		case ESQUERDA:
		proximoy--;
		break;
		
		case CIMA:
			proximox++;
			break;
			
		case BAIXO:
			proximox++;
			break;
			
		case DIREITA:
			proximoy++;
			break;
			
	}
	
	if(!podeAndar(proximox, proximoy)){
		return;
	}
	
	m.matriz[proximox][proximoy] = HEROI;
	m.matriz[p.x][p.y] = VAZIO;
	
	p.x = proximox;
	p.y = proximoy;
	
}

int podeAndar(int novox, int novoy){
	if (m.matriz[novox][novoy] == PAREDE_V) {
		return 0;
	}
	if (m.matriz[novox][novoy] == PAREDE_H) {
		return 0;
	}
		if (m.matriz[novox][novoy] == PILULA) {
		return 0;
	}
		if (m.matriz[novox][novoy] == FANTASMA) {
		return 0;
	}
	return 1;
}

void fantasmas(MAPA* m, POSICAO* f) {
		for(int i = 0; i < m->linhas; i++) {
		for (int j = 0; j < m->colunas; j++) {
			if(m->matriz[i][j] == FANTASMA) {
				f->x = i;
				f->y = j;
			}
	
			movimentarFantasma(i, j);
		}
	}
}

void movimentarFantasma(int xAtual, int yAtual) {
	srand(time(0));
	int posicao = rand() % 4;
	int opcoes[4][2] = {
		
			{ xAtual, yAtual + 1}, //baixo
			{ xAtual + 1, yAtual}, //dir
			{ xAtual, yAtual - 1}, //esq
			{ xAtual - 1, yAtual}  //cima

}
	if podeAndarFantasma(opcoes[posicao][0], opcoes[posicao][1]){
		(&m)->matriz[f.x][f.y] = VAZIO;
		(&m)->matriz[x][y] = FANTASMA;
		f.x = x;
		f.y = y;
		
	}
}

int podeAndarFantasma(int x, int y){
	if (m->matriz[x][y] == PAREDE_V) {
		return 0;
	}
	if (m->matriz[x][y] == PAREDE_H) {
		return 0;
	}
	if (m->matriz[x][y] == FANTASMA) {
		return 0;
	}
		if (m->matriz[x][y] == PILULA) {
		return 0;
	}
	
	
	return 1;
	
}


