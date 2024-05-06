#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct st_no{ 
	int id;
	char status[10];
	char data[10];
	char horario[5];
	struct st_no *prox; // ponteiro
};
	typedef struct st_no no; // definindo um tipo "no"(como int, float, char...)
		
	void inicia(no *P){ // inicializando lista vazia
    	P->id = 0;
    	P->prox = NULL;	
    	strcpy(P->status, "");
    	strcpy(P->data, "");
    	strcpy(P->horario, "");
}
	
		void exibe(no *P){
		no *T = P; // T aponta para o primeiro elemnto da lista
		
		if(P->id == 0){
			printf("LISTA VAZIA!!");
		} else{
				do{
		    printf("=====================\n");
            printf("iD: %d\n", T->id);
            printf("Status: %s\n", T->status);
            printf("Data: %s\n", T->data);
            printf("horario: %s\n", T->horario);
            printf("=====================\n");
			T = T->prox;
		}while(T != NULL);	
	}
		printf("\n\n");
	}
	void inserirFim(no *P){
    no *novo = (no*) malloc(sizeof(no)); 
    no *T = P;

    printf("Informe o iD do Job: ");
    scanf("%d", &novo->id);

    printf("Informe o STATUS do Job: ");
    scanf("%s", novo->status);

    printf("Informe a DATA do Job (dd/MM/yyyy): ");
    scanf("%s", novo->data);

    printf("Informe o HORARIO do Job (HH:mm): ");
    scanf("%s", novo->horario);

    novo->prox = NULL;

    if (T->id == 0) { // se a lista estiver vazia
        *P = *novo; // copia os valores do novo nó para o primeiro nó da lista
    } else {
        while (T->prox != NULL) {
            T = T->prox;
        }
        T->prox = novo; // adiciona o novo nó ao final da lista
    }
    system("cls");
}

	no* retirarInicio(no *P){
		
		if(P->id == 0){
			printf("Lista esta vazia");
		}
		else{
			no *T = P;
    			P = T->prox;
    			free(T);
		}		
		return P;	
	}
	
	
int main(){
	
	int opcao;
	
	no *P = (no*) malloc(sizeof(no)); // alocando na memoria um ponteiro que aponta para uma estrutura "no" - malloc separa na memoria o tamanho da struct
	
	inicia(P); // chamada de função para inserção de valores
	
		do{
		
		printf("----- LISTA DE JOBS ----\n");
		printf(" 1 - Inserir no FIM da lista: \n");
		printf(" 2 - Retirar no INICIO da lista: \n");
		printf(" 3 - Retirar no FIM da lista: \n");
		printf(" 4 - Retirar no MEIO da lista: \n");
		printf(" 5 - Exibir a lista: \n");
		printf(" 0 - Sair: \n");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 0:
				printf("\nFinalizando o programa!!");
				break;
			case 1: // inserir no fim
				inserirFim(P);
				break;
			case 2: // retirar do inicio
				P = retirarInicio(P);
				break;
			case 3:
				retirarFim(P);
				break;
			case 5: // exibir
				exibe(P);
				break;
			default:
			printf("Opcao invalida!!\n");
			system("pause");
		}
	}while(opcao != 0);
	
	
	free(P); // desalocando o ponteiro
	P = NULL;
	
	return 0;
}
