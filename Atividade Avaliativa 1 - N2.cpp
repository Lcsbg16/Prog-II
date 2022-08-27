#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
#include <locale.h>

struct ficha {
	int code;
	int membros;
	char tipo[20];
	int tp;
	int bene;
	float rendafam;
	float rendapess;
	char direito[20];
};
void preencher(int n,ficha*aux){
	int inicio;
	inicio=(rand()%75)+1001;
	for(int i=0;i<n;i++){
		aux[i].code=inicio+i;
		aux[i].membros=(rand()%6)+1;
		aux[i].tp=rand()%4;
		aux[i].bene=(rand()%4)+1;
		aux[i].rendafam=(rand()%3551)+450;
		if(aux[i].tp==0){
			sprintf(aux[i].tipo,"EFCC ");
		}
		if(aux[i].tp==1){
			sprintf(aux[i].tipo,"ConPS");
		}
		if(aux[i].tp==2){
			sprintf(aux[i].tipo,"TrInf");
		}				
		if(aux[i].tp==3){
			sprintf(aux[i].tipo,"MEI  ");
		}
		aux[i].rendapess=aux[i].rendafam/aux[i].membros;
				
}
}
void sit(int n, ficha *aux){
	for(int i=0;i<n;i++){
		sprintf(aux[i].direito,"Sim");
		if((aux[i].rendafam>3135)||(aux[i].rendapess>522.5)){
				sprintf(aux[i].direito,"Nao");	
						
		}
		if(aux[i].bene==3)sprintf(aux[i].direito,"Nao");
		
	}
}

void apresenta(int n, ficha *aux){
	for(int i=0;i<n;i++) {
		printf("%d\t%d\t%s\t%d\t%10.2f\t%10.2f\t%s\n",aux[i].code,aux[i].membros,aux[i].tipo,aux[i].bene,aux[i].rendafam,aux[i].rendapess,aux[i].direito);
	}
}
//4 – Percentual de Solicitantes com renda familiar acima de meio salário mínimo por pessoa.
void q4(int n, ficha *aux){
	for(int i=0;i<n;i++){
		
	}
	
}



void grava(int n,ficha *aux){
	FILE *pont_arq;
	pont_arq = fopen("arquivo_palavra.txt", "w");
	if(pont_arq == NULL)
	{
		printf("Erro na abertura do arquivo!");
	}
	int i;
		fprintf(pont_arq,"======================================================================\n");
	for(i=0;i<n;i++){
		fprintf(pont_arq,"%d\t%d\t%s\t%d\t%10.2f\t%10.2f\t%s\n",aux[i].code,aux[i].membros,aux[i].tipo,aux[i].bene,aux[i].rendafam,aux[i].rendapess,aux[i].direito);
	}
	fprintf(pont_arq,"======================================================================\n");
	fprintf(pont_arq,"Dados gravados com sucesso!");
	fclose(pont_arq);
	
}

main(){
	ficha aux[75];
	preencher(75,aux);
	sit(75,aux);
	apresenta(75,aux);
	grava(75,aux);
}
