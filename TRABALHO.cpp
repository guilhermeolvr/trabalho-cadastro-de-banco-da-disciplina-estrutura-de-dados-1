#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include <locale.h>

 struct Cliente{
    char nome[100];
    int conta[5];
    float saldo;
    
  };

 typedef Cliente cliente ;

int movimento=0;
int comparacoes=0;

void insertionsort(cliente* c, int tam);
void selectionsort (cliente* c, int tam);
void menu(cliente* c, int tam);
void imprime(cliente* c,int tam);

 int main(){
   
   cliente *vetor;
   int nclientes,op;
   float t;
   

   printf("Digite a quantidade de Clientes:");
   scanf("%d",&nclientes);
   
   vetor = (cliente*)malloc(nclientes*sizeof(cliente));

   for(int i = 0; i<nclientes;i++){
       printf("Digite um nome para o Cliente:\n");
       fflush(stdin);
       gets(vetor[i].nome);
       
       printf("Digite o numero da conta do cliente:\n");
       scanf("%d",&vetor[i].conta);
       printf("Digite o saldo do cliente:\n");
       scanf("%f",&vetor[i].saldo);
       printf("\n\n");
   }

  
 do{
  
  
  
  printf("0 - Sair\n");
  printf("1 - Ordenar clientes pelo Selection Sort \n");
  printf("2 - Ordenar clientes pelo Insection Sort \n");
  printf("3 - imprimir clientes digitados\n");
  printf("Digite uma opcao: \n");
  scanf("%i",&op);
  
  getchar();

  switch (op){
    case 0:
     printf("Programa finalizado!");
    break;
    case 1:
    t=clock();
    selectionsort(vetor,nclientes);
    imprime( vetor, nclientes);
    t= clock()- t;
    printf("tempo de execucao:%2.f\n",t);
    printf("comparacoes entre os saldos no selectionsort:%i\n",comparacoes);
    printf("movimentos entre os saldos no selectionsort:%i\n\n",movimento);
    break;
    case 2:
    t=clock();
    insertionsort(vetor,nclientes);
    imprime( vetor, nclientes);
    t= clock()- t;
    printf("tempo de execucao:%2.f\n",t);
    printf("comparacoes entre os saldos no inserctionsort:%i\n",comparacoes);
    printf("movimentos entre os saldos inserctionsort:%i\n\n",movimento);
    break;
    case 3:
    imprime(vetor, nclientes);
    break;
  }
  
  
  }while(op!=0);


   return 1;
 }



void insertionsort(cliente* c, int tam){
	int i,j;
  cliente aux;
	for (i= 1; i<tam; i++){
		aux = c[i];
		for( j=i; j>0 && aux.saldo <c[j-1].saldo; j--) movimento++;
		c[j]= c [j-1];comparacoes ++;
		c[j]=aux;
	}
  
}


void selectionsort (cliente* c, int tam){
     int i, j, menor;
     cliente troca;
     for(i=0; i < tam-1; i++){
          menor = i;
          
          for(j= i + 1; j< tam; j++){
               if(c[j].saldo< c[menor].saldo)
               menor = j;
               comparacoes++;
          }
          if (i != menor){
               troca = c[i];
               c[i]=c[menor];
               c[menor]= troca;
               movimento++;
          }
     }


}



void imprime(cliente* c, int tam){ //imprime os clientes digitados sem estar na ordem
	
	int i;
	
	printf("\n--------------Ordem Atual de Clientes:--------------\n\n");
	
	for(i = 0; i < tam; i++)
	{	
		printf("Nome: %s Numero da Conta: %d\nSaldo:R$%.2f\n\n",c[i].nome,c[i].conta,c[i].saldo);
		
	}
	

}
