#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

char palavrasSortidas[10][50] = {
	{"NEYMAR"},
	{"OLHO"},
	{"VERMELHO"},
	{"CHIMARRAO"},
	{"PROGRAMADOR"},
	{"BAHIA"},
	{"MEDICO"},
	{"ESTRADA"},
	{"COELHO"},
	{"PARALELEPIPEDO"}
};

char dicasSortidas[10][50] = {
	{"Jogador de futebol"},
	{"Parte do corpo"},
	{"Cor"},
	{"Bebida"},
	{"Area de TI"},
	{"Estado"},
	{"Profissao"},
	{"Via de circulacao"},
	{"Animal"},
	{"Figura geometrica"}
};

void inicializarAcertos(char palavra[], char acertos[]) {
	int i;
	
	for(i = 0; i < strlen(palavra); i++) {
	acertos[i] = '_';
	}
	acertos[i] = '\0';
}

void escolhePalavra(char palavra[], char dica[], int op) {
	char palavraSecreta[50], dicas[50];
	int indice;
	
	switch (op) {
		case 1:
			indice = rand() % 10;
			
			strcpy(palavra, palavrasSortidas[indice]);
			strcpy(dica, dicasSortidas[indice]);
			break;
		case 2:
			printf("%20s \n\n", "JOGO DA FORCA");
			printf("Digite a palavra secreta: ");
			scanf("%s", palavraSecreta);
			
			for (int i = 0; i < strlen(palavraSecreta); i++) {
		        palavraSecreta[i] = toupper(palavraSecreta[i]);
		    }
			strcpy(palavra, palavraSecreta);
			
			printf("Digite a dica: ");
			scanf("%s", dicas);
			
			dicas[0] = toupper(dicas[0]);
			strcpy(dica, dicas);
			break;
	}
	system("cls");
}

int venceu(char acertos[]) {
	for (int i = 0; i < strlen(acertos); i++) {
		if (acertos[i] == '_') {
			return 0;
		}
	}
	return 1;
}

int perdeu(int tentativas) {
	return tentativas == 0 ? 1 : 0;
}

int validarJogada(char palavra[], char acertos[], char letra) {
	int acertou = 0;
	
	for (int i = 0; i < strlen(palavra); i++) {
		if (palavra[i] == letra) {
			acertos[i] = letra;
			acertou = 1;
		}
	}
	return acertou;
}

void imprimeAcertos(char acertos[], char dica[]) {
	printf("Palavra: ");
	for (int i = 0; i < strlen(acertos); i++) {
		printf("%c ", acertos[i]);
	}
	
	printf("\n\nDica: %s", dica);
	printf("\n\n");
}

void forca(int tentativas) {
	printf("%20s \n\n", "JOGO DA FORCA");
	printf(" +-----+ \n");
	switch(tentativas) {
		case 0:
			printf(" |     O \n");
			printf(" |    /|\\ \n");
			printf(" |    / \\ \n");
			break;
		case 1:
			printf(" |     O \n");
			printf(" |    /|\\ \n");
			printf(" |    / \n");
			break;
		case 2:
			printf(" |     O \n");
			printf(" |    /|\\ \n");
			printf(" | \n");
			break;
		case 3:
			printf(" |     O \n");
			printf(" |    /| \n");
			printf(" | \n");
			break;
		case 4:
			printf(" |     O \n");
			printf(" |     | \n");
			printf(" | \n");
			break;
		case 5:
			printf(" |     O \n");
			printf(" | \n");
			printf(" | \n");
			break;
		case 6:
			printf(" | \n");
			printf(" | \n");
			printf(" | \n");
			break;
	}
	printf("=== \n\n");
}

void exibirProgresso(char acertos[], int tentativas, char dica[]) {
	forca(tentativas);
	imprimeAcertos(acertos, dica);
	
	printf("Tentativas restantes %d \n\n", tentativas);
}

void jogar(char palavra[], char acertos[], char dica[]) {
	int tentativas = 6;
	char letra;
	
	
	do {
		exibirProgresso(acertos, tentativas, dica);
		fflush(stdin);
		
		printf("Digite uma letra: ");
		scanf("%c", &letra);
		
		int acertou = validarJogada(palavra, acertos, toupper(letra));
		
		if (!acertou) tentativas--;
		
		system("cls");
	} while (!venceu(acertos) && !perdeu(tentativas));
	
	if (venceu(acertos)) {
		exibirProgresso(acertos, tentativas, dica);
		printf("Parabens!! voce acertou a palavra %s \n\n", palavra);
	} else {
		exibirProgresso(acertos, tentativas, dica);
		printf("Voce errou :( a palavra era %s \n\n", palavra);
	}
}

int main() {
	srand(time(NULL));
	char palavra[50], acertos[50], dica[50], continuarJogando;
	int op;
	
	while (1) {
		printf("%15s \n\n", "MENU FORCA");
		printf("1- Sortear palavra \n");
		printf("2- Digitar palavra \n\n");
		printf("Digite uma opcao: ");
		scanf("%d", &op);
		
		fflush(stdin);
		system("cls");
		
		escolhePalavra(palavra, dica, op);
		inicializarAcertos(palavra, acertos);
		jogar(palavra, acertos, dica);
		
		fflush(stdin);
		
		printf("Jogar novamente? (s/n): ");
		scanf("%c", &continuarJogando);
		
		if (toupper(continuarJogando) == 'N') {
			printf("\nEncerrando... \n");
			return 0;
		} else {
			system("cls");
		}
	}
}