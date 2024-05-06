#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>

struct st_no{ 
	int id;
	char status[15];
	char data[15];
	char horario[8];
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
			system("cls");
			printf("ERRO: LISTA VAZIA!!");
			sleep(1.5);
			system("cls");
		} else{
				do{
		    printf("=====================\n");
            printf("iD: %d\n", T->id);
            printf("Status: %s\n", T->status);
            printf("Data: %s\n", T->data);
            printf("horario: %s\n", T->horario);
            printf("=====================\n");
			T = T->prox;
			printf("\n");
		}while(T != NULL);	
	}
	}
	
	void exibeJob(){
		system("cls");
		
		printf(" Em um sistema SAP, um 'JOB' refere-se a um conjunto de tarefas\nautomatizadas (constru�das por programadores ABAP) \nque s�o executadas em um hor�rio e dia programado.");
		printf("\n\n Essas tarefas podem incluir: processamento de dados;\nexecu��o de relat�rios; integra��o de sistemas etc.\n");
		printf("Os jobs s�o frequentemente usados para automatizar processos \nrepetitivos e melhorar a efici�ncia do sistema. \nCabe ao Consultor BASIS cadastr�-los corretamente.");
		
		printf("\n\n");
		system("pause");
		system("cls");
	}
	
	void inserirFim(no *P){
	system("cls");
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
        *P = *novo; // copia os valores do novo n� para o primeiro n� da lista
    } else {
        while (T->prox != NULL) {
            T = T->prox;
        }
        T->prox = novo; // adiciona o novo n� ao final da lista
    }
    system("cls");
}

	no* retirarInicio(no *P){
		
		if(P->id == 0){
			system("cls");
			printf("ERRO: LISTA VAZIA!!");
			sleep(1.5);
			system("cls");
		}
		else{
			no *T = P;
    			P = T->prox;
    			free(T);
    			
    	system("cls");
		printf("Retirando do inicio da lista...");
		sleep(1);
		system("cls");	
		}
	
				
		return P;	
	}
	
	void retirarFim(no *P){
		no *ant;
		no *T = P;
		
		if(P->id == 0){
			system("cls");
			printf("ERRO: LISTA VAZIA!!");
			sleep(1.5);
			system("cls");
		} else {
			while(T->prox != NULL){
			ant = T;
			T = T->prox;			
		}	
		ant->prox = NULL;
		
		free(T);
		
		system("cls");
		printf("Retirando do fim da lista...");
		sleep(1);
		system("cls");	
		}
		
		
	}
	
	void retirarMeio(no *P){
		no *ant;
		no *T = P;
		int valor;
		
			if(P->id == 0){
			system("cls");
			printf("ERRO: LISTA VAZIA!!");
			sleep(1.5);
			system("cls");
		} else {
		exibe(P);
		printf("Informe o iD do JOB que deseja retirar: ");
		scanf("%d", &valor);
		 
		while(T->id != valor){
			ant = T;
			T = T->prox;			
		}
		ant->prox = T->prox;
		T -> prox = NULL;
		
		system("cls");
		printf("Retirando o JOB de iD: %d", valor);
		sleep(2);
		system("cls");	
		}
	}
	
int main(){
	
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	int opcao;
	
	no *P = (no*) malloc(sizeof(no)); // alocando na memoria um ponteiro que aponta para uma estrutura "no" - malloc separa na memoria o tamanho da struct
	
	inicia(P); // chamada de fun��o para inser��o de valores
	
		do{
		
		printf("----- LISTA DE JOBS ----\n");
		printf(" 1 - Inserir no FIM da lista: \n");
		printf(" 2 - Retirar do INICIO da lista: \n");
		printf(" 3 - Retirar do FIM da lista: \n");
		printf(" 4 - Retirar do MEIO da lista: \n");
		printf(" 5 - Exibir a lista: \n");
		printf(" 6 - Exibir dados de um JOB: \n");
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
			case 4:
				retirarMeio(P);
				break;
			case 5: // exibir
				exibe(P);
				break;
			case 6:
				exibeJob();
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
