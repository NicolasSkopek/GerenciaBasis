#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>


struct st_lista{ 
	int id;
	char nome[20];
	char autor[20];
	struct st_lista* prox;
};

typedef struct st_lista fila;
fila* inicio = NULL;
fila* fim = NULL;

fila* criarFila(){ // cria a fila
	fila* f = (fila*) malloc(sizeof(fila));
		f->id = 0;
    	strcpy(f->nome, "");
    	strcpy(f->autor, "");
    	f->prox = NULL;	
	return f;
}

void sortFila(fila** head_ref) {
    if (*head_ref == NULL || (*head_ref)->prox == NULL) {
        return;
    }

    fila *sorted = NULL;
    fila *current = *head_ref;

    while (current != NULL) {
        fila *next = current->prox;

        if (sorted == NULL || sorted->id >= current->id) {
            current->prox = sorted;
            sorted = current;
        } else {
            fila *temp = sorted;
            while (temp->prox != NULL && temp->prox->id < current->id) {
                temp = temp->prox;
            }
            current->prox = temp->prox;
            temp->prox = current;
        }

        current = next;
    }

    *head_ref = sorted;
}

void enqueue(fila* f){ // inserir no fim da fila
	fila* novo = (fila*) malloc(sizeof(fila)); 
	system("cls");
	printf("Informe o iD da Request: ");
    scanf("%d", &novo->id);

    printf("Informe o NOME da Request: ");
    scanf("%s", novo->nome);

    printf("Informe o AUTOR da Request: ");
    scanf("%s", novo->autor);

	novo->prox = NULL; // novo valor da fila não apontará para ninguem
	
	if(inicio == NULL){ // se a fila estiver vazia
		printf("Inserindo o primeiro da fila\n");
		inicio = novo; // simplesmente o inicio e novo apontarão para o mesmo elemento
		fim = novo;
	}else{ // se não
		fim->prox = novo; // o valor no fim agora apontará para o novo
		fim = novo; // o fim agora aponta para o novo, ja que ele é o novo fim da fila
	}
}

int dequeue(fila* f){ // retirar valor do começo da fila
	system("cls");	
	if(inicio == NULL){ // se a fila estiver vazia	
		printf("ERRO: FILA VAZIA!!\n"); 
		sleep(1.5);
		system("cls");
		return 0;
	}else{ // se não
		fila* T = inicio; // ponteiro T do tipo fila apontará para o inicio
		inicio = T->prox; // inicio agora apontará para onde T aponta, ou seja, uma struct após o primeiro
		free(T);
		printf("Removendo Request!!\n");
		sleep(1.5);
	}
}

fila* clear(fila* f){ // limpar a fila inteira
	fila* q = inicio;
		if(inicio == NULL){
		system("cls");
		printf("ERRO: FILA VAZIA!!\n"); 
		sleep(1.5);
		system("cls");
		return;	
	}
	else {
		while(q != NULL){
		fila*  T = q->prox;
		free(q);
		q = T;
		inicio = NULL;
		fim = NULL;
	}
		system("cls");
		printf("Fila limpa!!\n");
		sleep(1.5);
}
	free(f);
	return f;	
}

void Exibe(fila* f){ // exibe a fila
	fila* T = inicio;
	
	if(inicio == NULL){
		system("cls");
		printf("ERRO: FILA VAZIA!!\n"); 
		sleep(1.5);
		system("cls");
		return;	
	}
	else{
		while(T != NULL){
		printf("====================\n");
		printf("iD: %d\n", T->id);
		printf("Nome: %s\n", T->nome);
		printf("Autor: %s\n", T->autor);
		printf("====================\n");
		T = T->prox;
	}
	}	
		printf("\n");
		system("pause");
}

void exibeRequest(){
		system("cls");
		
		printf(" Em um sistema SAP, uma 'REQUEST' refere-se a uma ferramente essencial \npara agruprar e gerenciar alterações no sistema SAP.");
		printf("\n\n Essa ferramentas são veementemente utilizadas em;\nambientes de desenvolvimento(DEV), qualidade(QAS) e produção(PRD)\n");
		printf("Existem diferentes tipos de requests mas as\nmais comuns são Change Requests e Transport Requests. \nCabe ao Consultor BASIS cadastrá-las corretamente.");
		
		printf("\n\n");
		system("pause");
		system("cls");
	}

//////////////////////////////////////////////////////////////////////////////////

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
            printf("Horario: %s\n", T->horario);
            printf("=====================\n");
			T = T->prox;
			printf("\n");
		}while(T != NULL);	
	}
	}
	
	void exibeJob(){
		system("cls");
		
		printf(" Em um sistema SAP, um 'JOB' refere-se a um conjunto de tarefas\nautomatizadas (construídas por programadores ABAP) \nque são executadas em um horário e dia programado.");
		printf("\n\n Essas tarefas podem incluir: processamento de dados;\nexecução de relatórios; integração de sistemas etc.\n");
		printf("Os jobs são frequentemente usados para automatizar processos \nrepetitivos e melhorar a eficiência do sistema. \nCabe ao Consultor BASIS cadastrá-los corretamente.");
		
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
	
	void alterarCor(){
		   system("cls");	
		   int n;
		   int opcao;
		   HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
						
						printf("----- CUSTOMIZAÇÃO  ----\n"); 
						printf("[1] - LETRAS Vermelhas: \n");
						printf("[2] - LETRAS Verdes: \n");
						printf("[3] - LETRAS Azuis: \n");
						printf("[0] - Voltar para o MENU GERÊNCIA BASIS: \n");
						printf(" Opção: "); 
						scanf("%d", &n);

						switch(n){
							case 0:
								system("cls");
								return;
							case 1:
								SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
								break;
							case 2:
								SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
								break;
							case 3:
								SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
								break;
							default:
								printf("Opção inválida");
								break;
						}
		system("cls");
	}
	
	void alterarTamanho(){
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_FONT_INFOEX fontInfo;
    fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);
    GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);

    //tamanho da fonte em 24x12 pixels
    fontInfo.dwFontSize.X = 30;
    fontInfo.dwFontSize.Y = 26;

    SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);
	}
	
///////////////////////////////////////////////////////////////////////////////
	
void menuRequests(fila *f){
	int opcao = 0;

	do{
		system("cls");
		printf("----- FILA DE REQUESTS  ----\n"); 
		printf(" [1] - Inserir uma Request (enqueue): \n");
		printf(" [2] - Remover uma Request (dequeue): \n");
		printf(" [3] - Exibir a Fila: \n");
		printf(" [4] - Limpar a Fila: \n");
		printf(" [5] - Ordenar a fila: \n");
		printf(" [6] - O que é uma Request?: \n");
		printf(" [0] - Retornar para MENU GERÊNCIA BASIS: \n");
		printf(" Opção: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 0:
				system("cls");
				return;
				break;
			case 1:
				enqueue(f);		
				break;
			case 2:
				dequeue(f);
				break;
			case 3:
				system("cls");
				Exibe(f);
				break;
			case 4:
				f = clear(f);
				break;
			case 5:
				system("cls");
                sortFila(&inicio);
                printf("Fila ordenada por iD!\n");
                system("pause");
                break;
            case 6:
				exibeRequest();
				break;
			default:
				system("cls");
				printf("Opção inválida!!\n\n");
				system("pause");
				system("cls");
				break;
		}
		
	}while(opcao != 0);
}


void menuJobs(no *P){
	system("cls");
	
	int opcao;
	
	do{
		
	printf("----- LISTA DE JOBS  ----\n"); 
	printf(" [1] - Inserir no FIM da lista: \n");
	printf(" [2] - Retirar do INICIO da lista: \n");
	printf(" [3] - Retirar do FIM da lista: \n");
	printf(" [4] - Retirar do MEIO da lista: \n");
	printf(" [5] - Exibir a lista: \n");
	printf(" [6] - O que é um JOB?: \n");
	printf(" [0] - Retornar para MENU GERÊNCIA BASIS: \n");
	printf(" Opção: ");
	scanf("%d", &opcao);
	
	switch(opcao){
			case 0:
				system("cls");
				return;
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
				system("cls");
				retirarMeio(P);
				break;
			case 5: // exibir
				system("cls");
				exibe(P);
				system("pause");
				system("cls");
				break;
			case 6:
				exibeJob();
				break;
			default:
				system("cls");
				printf("Opção inválida!!\n\n");
				system("pause");
				system("cls");
				break;
		}
		
	}while(opcao != 0);
	
	system("cls");
	
}
	
	
int main(){
	alterarTamanho();
    
	setlocale(LC_ALL, "Portuguese_Brazil");
	
	int opcao;
	
	no *P = (no*) malloc(sizeof(no)); // alocando na memoria um ponteiro que aponta para uma estrutura "no" - malloc separa na memoria o tamanho da struct
	
	inicia(P); // chamada de função para inserção de valores
	
	fila* f;
	f = criarFila();
	
		do{
		
		printf("----- MENU GERÊNCIA BASIS  ----\n"); 
		printf(" [1] - LISTA de JOBS: \n");
		printf(" [2] - FILA de REQUESTs: \n");
		printf(" [3] - Customização: \n");
		printf(" [0] - Sair do Gerência Basis: \n");
		printf(" Opção: ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 0:
				printf("\nFinalizando o programa!!");
				break;
			case 1: // inserir no fim
				menuJobs(P);
				break;
			case 2: // retirar do inicio
				menuRequests(f);
				break;
			case 3:		
				alterarCor();	
				break;
			default:
				system("cls");
				printf("Opção inválida!!\n\n");
				system("pause");
				system("cls");
				break;
		}
	}while(opcao != 0);
	
	
	free(P); // desalocando o ponteiro
	P = NULL;
	
	return 0;
}
