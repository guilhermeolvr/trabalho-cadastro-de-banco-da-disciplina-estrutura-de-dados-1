#include <conio.h>
using namespace std;
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <fstream>
#include <time.h>

 main()
{
FILE *registrosdobanco,*movimento,*consultadesaldo; //nome do arquivo

struct dataabertura{
    int ano;
    short mes;
    short dia;
} dataabertura;

struct datavencimento{
    int ano;
    short mes;
    short dia;
} datavencimento;


struct cadastro {     //dados do cliente
    char numconta [500];
    char nome [32];
    struct dataabertura dataabert;
    float limite;
    struct datavencimento datavenc;
    int tipoconta;
}cadastro;
  struct cadastro c; //transformando a struct 'cadastro' na variavel 'c'



 printf("\n---------- Cadastro de cliente -----------\n\n\n");  //recebendo os valores do cadastro do cliente

printf("digite o numero da conta:");
 fgets(c.numconta, 501, stdin);

printf("digite o nome da pessoa:");
 fgets(c.nome, 33, stdin);
 
printf("digite a data de abertura da conta no formato: (dd/mm/aa):"); 
scanf("%d%/c%d/c%d", &c.dataabert.dia, &c.dataabert.mes, &c.dataabert.ano);
 fflush(stdin);
c.tipoconta==0;
  
   
	 
	 //recebendo o tipo de conta
	 	 	 	
printf("digite o tipo da conta (1 - simples ou 2 - especial):\n");
scanf("%d", &c.tipoconta);


switch
(c.tipoconta)
{

case 1 :
    printf("Conta cadastrada com sucesso\n");
break;

case 2 :
printf("Digite o limite: ");
scanf("%.2f",&c.limite);
printf("Digite a data de vencimento: ");
scanf("%d%/%d/%d", &c.datavenc.dia, &c.datavenc.mes, &c.datavenc.ano);
break;
 
default:-
printf("O numero digitado nao condiz as especificacoes solicitadas ");
break;
}
 


  registrosdobanco = fopen("registrosdobanco.txt", "w"); //abertura do aqruivo 
  
  
  
  if (registrosdobanco == NULL)
     printf("\nErro na Abertura do arquivo");
     //cout<< "\nErro na abertura do arquivo";
  else
      { fwrite(&c, sizeof(struct cadastro), 1, registrosdobanco); }//escrevendo os dados do cadastro do arquivo
        if (ferror(registrosdobanco))
           printf("\nErro na escrita do arquivo");
           //cout <<"\nErro na escrita do arquivo ";











// b) escreva um subprograma que gere o arquivo movimento referente a um determinado dia;

movimento==0;

struct datamovimento{
    int ano;
    short mes;
    short dia;
} datamovimento;

struct movimentodia {     //dados do cliente
    struct datamovimento data;
	int tipodeoperacao;
    float valor;
	float saldo;       
} movimentodia;
 struct movimentodia m;

float saque,deposito;

printf("\n---------- Movimento do dia -----------\n\n\n");  //recebendo os valores do cadastro do cliente

printf("digite a data do movimento no formato: (dd/mm/aa):");
 fflush(stdin);
 scanf("%d%/%d/%d", &m.data.dia, &m.data.mes, &m.data.ano);


printf("digite o tipo de operação 1-Deposito 2-Saque :");
 fflush(stdin);
 scanf("%d", &m.tipodeoperacao);
 
printf("Digite o saldo: ");
scanf("%.2f",&m.saldo);


 
switch
(m.tipodeoperacao)
{

case 1 :
    printf("digite o valor do deposito\n");
    scanf("%.2f",&deposito);
    m.saldo += deposito;
    
break;

case 2 :
printf("Digite o valor do saque: ");
scanf("%.2f",&saque);
m.saldo -= saque;
break;
 
default:
printf("O numero digitado nao condiz as especificacoes solicitadas ");
break;
}

fread(&c, sizeof(struct cadastro), 1, registrosdobanco);
movimento = fopen("movimentododia.txt", "a+");



 if (movimento == NULL)
     printf("\nErro na Abertura do arquivo");
     //cout<< "\nErro na abertura do arquivo";
  else
      { fwrite(&m, sizeof(struct movimentodia), 1, movimento); //escrevendo os dados do movimento no arquivo
        if (ferror(movimento))
           printf("\nErro na Leitura do arquivo");
           //cout <<"\nErro na leitura do arquivo ";
        
		   }
		





 // c) desenvolva uma rotina que atualize o cadastro dos clientes a partir de um arquivo movimento e emita um relatório com o saldo atualizado de cada cliente segundo o intervalo informado; 
  
     fread(&m, sizeof(struct cadastro), 1, registrosdobanco);
      fwrite(&m, sizeof(struct movimentodia), 1, movimento);
	  
  	movimento = fopen("movimentododia.txt", "a+");
  	
  	
  
  
  
  

  
 //d) escreva uma rotina que liste todos os depósitos realizados na conta de um determinado cliente; 
  
  while (m.tipodeoperacao == 1)
    
   printf("deposito realizado no valo de :""%.2f" "em:""%s",deposito,m.data); 
   fprintf(movimento,"deposito realizado no valo de :""%.2f" "em:""%s",deposito,m.data);
   
   
   while (m.tipodeoperacao >= 3 ) 
   printf("a operacao realizada nao foi um deposito" );
   
   
   
   //e) construa uma rotina que atenda um número indeterminado de consultas de saldo - em cada consulta deverá ser fornecido um número da conta e deverá ser devolvido o saldo ou uma mensagem de conta inexistente.

   char numcontaaserconsultado[500];
   
    consultadesaldo = fopen("consultadesaldo.txt", "w");
 
  printf("digite o numero da conta que o saldo vai ser consultado");
  fgets(numcontaaserconsultado, 501, stdin);
  
  if (numcontaaserconsultado == c.numconta){
  
  	printf("o saldo na conta" "%s""e de" "%.2f",c.numconta,m.saldo);
  	fprintf(consultadesaldo,"o saldo na conta" "%s" "e de" "%.2f",c.numconta,m.saldo);
  
  
  }
    else {
   	printf(" a conta nao existe");
    }
    
getch();
}

