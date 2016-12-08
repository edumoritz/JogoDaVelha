#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define T 3
int vez;
int menu();
void jogar(int tabuleiro[T][T]);
void jogarCOM(int tabuleiro[T][T]);
void limpaTabu(int tabuleiro[T][T]);
void exibeTabu(int tabuleiro[T][T]);
int checaLocal(int tabuleiro[T][T], int linha, int coluna);
int checaLinha(int tabuleiro[T][T]);
int checaColuna(int tabuleiro[T][T]);
int checaDiagonal(int tabuleiro[T][T]);
int checaEmpate(int tabuleiro[T][T]);
int checaFinal(int tabuleiro[T][T], int vez);
void jogada(int tabuleiro[T][T]);
void jogadaCOM(int tabuleiro[T][T]);
void jogadaX(int tabuleiro[T][T], int ESC);
int main(){
	int tabuleiro[T][T], continuar;
	srand(time(NULL));
	
	do{
		vez = 1;
		continuar = menu();
		if(continuar == 2){
			jogar(tabuleiro);
		}
		if(continuar == 1){
			jogarCOM(tabuleiro);
		}
		
	}while(continuar);
	
	
	system("pause");
	return 0;
}
int menu(){
	int opcao;
	printf("\n1 - Jogar com Computador\n");
	printf("2 - Jogar como Player2\n");
	printf("0 - Sair\n");
	printf("Opcao: ");
	scanf("%d",&opcao);
	
	switch(opcao){
	case 1:
	case 2:
	case 0:
		break;
	default:
		printf("Opcao invalida. Tente novamente!\n");
	}
	return opcao;
}

void limpaTabu(int tabuleiro[T][T]){
	int linha, coluna;
	for(linha = 0; linha < T; linha++){
		for(coluna = 0; coluna < T; coluna++){
			tabuleiro[linha][coluna] = 0;
		}
	}
}
void exibeTabu(int tabuleiro[T][T]){
	int linha, coluna;
	printf("\n");
	
	for(linha = 0; linha < T; linha++){
		for(coluna = 0; coluna < T ; coluna++){
			if(tabuleiro[linha][coluna] == 0)
				printf("     ");
			else 
				if(tabuleiro[linha][coluna] == 1)
					printf("  X  ");
				else
					printf("  O  ");
			if(coluna != (T-1))
				printf("|");
		}
		printf("\n");
	}
	printf("\n");
}
void jogarCOM(int tabuleiro[T][T]){
	limpaTabu(tabuleiro);
	int escolha = 0;
	printf("\nEscolha a primeira jogada:\n1 - Player\n2 - COM\n");
	scanf("%d",&escolha);
	switch(escolha){
	case 1:
		system("cls");
		exibeTabu(tabuleiro);
		jogada(tabuleiro);
		exibeTabu(tabuleiro);
		break;
	case 2:
		system("cls");
		exibeTabu(tabuleiro);
		jogadaCOM(tabuleiro);
		exibeTabu(tabuleiro);
		break;
	default:
		printf("Opcao invalida. Tente novamente!\n");
		break;
	}
	system("cls");
	exibeTabu(tabuleiro);
	jogadaX(tabuleiro, escolha);
		
}
void jogar(int tabuleiro[T][T]){
	limpaTabu(tabuleiro);
	do{
		system("cls");
		exibeTabu(tabuleiro);
		jogada(tabuleiro);
		
	}while(checaFinal(tabuleiro, vez) != 1);
}
int checaLocal(int tabuleiro[T][T], int linha, int coluna){
	if(linha < 0 || linha > (T-1) || coluna < 0 || coluna > (T-1) || tabuleiro[linha][coluna] != 0)
		return 0;
	else
		return 1;
}
int checaLinha(int tabuleiro[T][T]){
	int linha, coluna,
        soma;
 
    for(linha = 0 ; linha < T ; linha++)
    {
        soma=0;
 
        for(coluna = 0 ; coluna < T ; coluna++)
            soma += tabuleiro[linha][coluna];
 
        if(soma==T || soma == (-1)*T)
            return 1;
    }
 
    return 0;
}
int checaColuna(int tabuleiro[T][T]){
	int linha, coluna,
        soma;
 
    for(coluna = 0 ; coluna < T ; coluna++)
    {
        soma=0;
 
        for(linha = 0 ; linha < T ; linha++)
            soma += tabuleiro[linha][coluna];
 
        if(soma==T || soma == (-1)*T)
            return 1;
    }
 
    return 0;
}
int checaDiagonal(int tabuleiro[T][T]){
	int linha,
        diagonal_principal=0,
        diagonal_secundaria=0;
 
    for(linha = 0 ; linha < T ; linha++)
    {
        diagonal_principal += tabuleiro[linha][linha];
        diagonal_secundaria += tabuleiro[linha][T-linha-1];
    }
 
    if(diagonal_principal==T || diagonal_principal==(-1)*T ||
       diagonal_secundaria==T || diagonal_secundaria==(-1)*T)
       return 1;
 
    return 0;
}
int checaEmpate(int tabuleiro[T][T]){
	int linha, coluna;
 
    for(linha = 0 ; linha < T ; linha++)
        for(coluna = 0 ; coluna < T ; coluna++)
            if(tabuleiro[linha][coluna] == 0)
                return 0;
 
    return 1;
}
int checaFinal(int tabuleiro[T][T], int vez){
	if(checaLinha(tabuleiro))
    {
        printf("Jogo encerrado. Jogador %d venceu !\n\n", (vez%2)+1);
        exibeTabu(tabuleiro);
		system("pause");
		system("cls");
        return 1;
    }
 
    if(checaColuna(tabuleiro))
    {
        printf("Jogo encerrado. Jogador %d venceu !\n\n", (vez%2)+1);
        exibeTabu(tabuleiro);
		system("pause");
		system("cls");
        return 1;
    }
 
    if(checaDiagonal(tabuleiro))
    {
        printf("Jogo encerrado. Jogador %d venceu !\n\n", (vez%2)+1);
        exibeTabu(tabuleiro);
		system("pause");
		system("cls");
        return 1;
    }
 
    if(checaEmpate(tabuleiro))
    {
        printf("Jogo encerrado. Ocorreu um empate! !\n\n");
        exibeTabu(tabuleiro);
		system("pause");
		system("cls");
        return 1;
    }
 
    return 0;
}
void jogadaCOM(int tabuleiro[T][T]){
	int linha, coluna;
    vez++;
	printf("\n--> Jogador %d \n", (vez % 2) + 1);
	
	do
    {
		linha = (1 + rand() % 3);
		linha--;
		coluna = (1 + rand() % 3);
		coluna--;
			if(checaLocal(tabuleiro, linha, coluna) == 0){
				linha = (1 + rand() % 3);
				linha--;
				coluna = (1 + rand() % 3);
				coluna--;
			}
	} while(checaLocal(tabuleiro, linha, coluna) == 0);
	if(vez%2)
		tabuleiro[linha][coluna] = -1;
	else
		tabuleiro[linha][coluna] = 1;
		
}
void jogada(int tabuleiro[T][T]){
	int linha, coluna;
    vez++;
    printf("\n--> Jogador %d \n", (vez % 2) + 1);
 
    do
    {
        printf("Linha: ");
        scanf("%d", &linha);
        linha--;
 
        printf("Coluna: ");
        scanf("%d", &coluna);
        coluna--;
 
        if(checaLocal(tabuleiro, linha, coluna) == 0)
            printf("Posicao ocupada ou inexistente, escolha outra.\n");
 
    } while(checaLocal(tabuleiro, linha, coluna) == 0);
 
    if(vez%2)
        tabuleiro[linha][coluna] = -1;
    else
        tabuleiro[linha][coluna] = 1;
}
void jogadaX(int tabuleiro[T][T], int ESC){
	int linha, coluna;
	if(ESC == 1){
		do{
			system("cls");
			jogadaCOM(tabuleiro);
			exibeTabu(tabuleiro);
			if(checaFinal(tabuleiro, vez) == 1){
				system("cls");
			}
			else {
				jogada(tabuleiro);
			}
		}while(checaFinal(tabuleiro, vez) != 1);
	}
	if(ESC == 2){
		do{
			system("cls");
			exibeTabu(tabuleiro);
			jogada(tabuleiro);
			
			if(checaFinal(tabuleiro, vez) == 1){
				system("cls");
			}
			else {
				jogadaCOM(tabuleiro);
			}
		}while(checaFinal(tabuleiro, vez) != 1);
	}
	
	if(vez%2)
        tabuleiro[linha][coluna] = -1;
    else
        tabuleiro[linha][coluna] = 1;
}