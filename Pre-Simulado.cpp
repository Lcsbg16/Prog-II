#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
#include <locale.h>

struct ficha {
	char codigo[20];
	char tipo[20];
	int tp;
	int dia;
	int mes;
	int horas;
	float valor;
};
float percent_menor_40h=0;
float med_horas_man,med_horas_rep,med_horas;
int imv;
void preencher (int n,ficha *os){
	int inicio;
	inicio=(rand()%1001)+1000;
	for(int i=0;i<n;i++){
		os[i].tp=rand()%2;
		os[i].horas=(rand()%81)+20;
		if(os[i].tp==0){
			sprintf(os[i].tipo,"Manutencao");
			sprintf(os[i].codigo,"OS%dM",inicio+i);
		}
		if(os[i].tp==1){
			sprintf(os[i].tipo,"Reparo    ");
			sprintf(os[i].codigo,"OS%dR",inicio+i);
		}
		
	}
}
void data(int n, ficha *os){
	for(int i=0;i<n;i++){
		os[i].dia=(rand()%30)+1;
		os[i].mes=(rand()%12)+1;	
	}
}
void val(int n, ficha *os){
	for(int i=0;i<n;i++){
		if(os[i].tp==0){
			os[i].valor=os[i].horas*100+500;
		}
		else
			os[i].valor=os[i].horas*150+750;
	}
}

//O percentual de Serviços com duração menor que 40 Horas.
float q3(int n, ficha *os){
	float totmen40;
	for(int i=0;i<n;i++){
		if(os[i].horas<40){
			totmen40++;
		}
	}
	percent_menor_40h=totmen40/n *100;
	return percent_menor_40h;
}


//A média de Horas das OS’s de cada tipo e geral.
void q4(int n,ficha *os){
	float toth=0,tothman=0,totman=0,tothrep=0,totrep=0;
	for(int i=0;i<n;i++){
		toth+=os[i].horas;
		if(os[i].tp==0){
			tothman=tothman+os[i].horas;
			totman++;
		}
		if(os[i].tp==1){
			totrep++;
			tothrep+=os[i].horas;
		}		
	}
	med_horas_man=tothman/totman;
	med_horas_rep=tothrep/totrep;
	med_horas=toth/n;
}
// A OS de maior custo com todas as suas informações.
void q5(int n,ficha *os){
	float maior=0;
	for(int i=0;i<n;i++){
		if(maior<os[i].valor){
			maior=os[i].valor;
			imv=i;
		}
	}
}
void resultado(float rq3,ficha *os){
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("3)O percentual de Serviços com duração menor que 40 Horas:%.2f%%.\n",percent_menor_40h);
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("4)A media de Horas das OSs do tipo:\n");
	printf("Manutencao:%.1f horas.\n",med_horas_man);
	printf("Reparo    :%.1f horas.\n",med_horas_rep);
	printf("Geral     :%.1f horas.\n",med_horas);
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("OS de maior valor com todas suas informacoes:\n");
	printf("%s \t %s \t %4.2d/%.2d \t %d \t %8.2f\n",os[imv].codigo,os[imv].tipo,os[imv].dia,os[imv].mes,os[imv].horas,os[imv].valor);
}
void imprimir(int n, ficha *os){
	for(int i=0;i<n;i++){
		printf("%s \t %s \t %4.2d/%.2d \t %d \t %8.2f\n",os[i].codigo,os[i].tipo,os[i].dia,os[i].mes,os[i].horas,os[i].valor);
	}
}

void grava(int n,ficha *os){
	FILE *pont_arq;
	pont_arq = fopen("OS.txt", "w");
	if(pont_arq == NULL)
	{
		printf("Erro na abertura do arquivo!");
	}
	int i;
		fprintf(pont_arq,"======================================================================\n");
	for(i=0;i<n;i++){
		fprintf(pont_arq,"%s \t %s \t %4.2d/%.2d \t %d \t %8.2f\n",os[i].codigo,os[i].tipo,os[i].dia,os[i].mes,os[i].horas,os[i].valor);	
	}
	fprintf(pont_arq,"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");	
	fprintf(pont_arq,"3)O percentual de Serviços com duração menor que 40 Horas:%.2f%%.\n",percent_menor_40h);
	fprintf(pont_arq,"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	fprintf(pont_arq,"4)A media de Horas das OSs do tipo:\n:");
	fprintf(pont_arq,"Manutencao:%.1f horas.\n",med_horas_man);
	fprintf(pont_arq,"Reparo    :%.1f horas.\n",med_horas_rep);
	fprintf(pont_arq,"Geral     :%.1f horas.\n",med_horas);
	fprintf(pont_arq,"======================================================================\n");
	fprintf(pont_arq,"OS de maior valor com todas suas informacoes:\n");
	fprintf(pont_arq,"%s \t %s \t %4.2d/%.2d \t %d \t %8.2f\n",os[imv].codigo,os[imv].tipo,os[imv].dia,os[imv].mes,os[imv].horas,os[imv].valor);
	
	fprintf(pont_arq,"Dados gravados com sucesso!");
	fclose(pont_arq);
	
}




main(){
	srand(time(NULL));
	ficha os[42];
	float rq3;
	preencher(42,os);
	data(42,os);
	val(42,os);
	imprimir(42,os);
	rq3=q3(42,os);
	q4(42,os);
	q5(42,os);
	grava(42,os);
	resultado(42,os);
}
