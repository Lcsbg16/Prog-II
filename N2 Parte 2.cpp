#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
#include <locale.h>

struct ficha{
	char codigo[20];
	char regiao[20];
	int reg;
	char tipo[20];
	int tp;
	int moradores;
	char interesse[20];
	int inter;
	char rede[20];
	int red;
	float consumo;
	float conMes;
	float conMor;	
};
float cons_med_pos; //q3
int imenor; // q4
float percent_indiferente; //q5
float percent_neg_rede,percent_pos_nrede;// q6

void preencher(int n, ficha *gas){
	for(int i=0;i<n;i++){
		gas[i].reg=(rand()%3)+1;
		gas[i].tp=rand()%2;
		gas[i].moradores=(rand()%6)+1;
		gas[i].inter=rand()%3;
		gas[i].red=rand()%2;
		gas[i].consumo=(rand()%19)+6;
		gas[i].conMes=gas[i].consumo/12;
		gas[i].conMor=gas[i].conMes/gas[i].moradores;
		//Regiao e Codigo
		if(gas[i].reg==1){
			sprintf(gas[i].regiao,"Aroeira ");
			if(gas[i].tp==0){
				sprintf(gas[i].codigo,"%dAC",230020+i);
			}
			if(gas[i].tp==1){
				sprintf(gas[i].codigo,"%dAA",230020+i);
			}			
		}
		if(gas[i].reg==2){
			sprintf(gas[i].regiao,"Visconde");
			if(gas[i].tp==0){
				sprintf(gas[i].codigo,"%dVC",230020+i);
			}
			if(gas[i].tp==1){
				sprintf(gas[i].codigo,"%dVA",230020+i);
			}			
		}
		if(gas[i].reg==3){
			sprintf(gas[i].regiao,"Miramar ");
			if(gas[i].tp==0){
				sprintf(gas[i].codigo,"%dMC",230020+i);
			}
			if(gas[i].tp==1){
				sprintf(gas[i].codigo,"%dMA",230020+i);
			}			
		}
		
		//Tipo
		if(gas[i].tp==0){
			sprintf(gas[i].tipo,"Casa");
		}
		if(gas[i].tp==1){
			sprintf(gas[i].tipo,"Apto");
		}
		//Interresse
		if(gas[i].inter==0){
			sprintf(gas[i].interesse,"Indiferente");
		}
		if(gas[i].inter==1){
			sprintf(gas[i].interesse,"Positivo   ");
		}
		if(gas[i].inter==2){
			sprintf(gas[i].interesse,"Negativo   ");
		}
		//Rede
		if(gas[i].red==0){
			sprintf(gas[i].rede,"SIM");
		}		
		if(gas[i].red==1){
			sprintf(gas[i].rede,"NAO");
		}												
	}
}



void apresentar(int n, ficha *gas){
	printf(" Codigo \t Regiao \tTipo \tMoradores \t Interresse \t Rede \t ConMes \tConMor\n");
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	for (int i=0;i<n;i++){		
	printf("%s\t%s\t%s\t    %d\t\t  %s\t %s\t  %.1f\t\t%.2f\n",gas[i].codigo,gas[i].regiao,gas[i].tipo,gas[i].moradores,gas[i].interesse,gas[i].rede,gas[i].conMes,gas[i].conMor);
}
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
}

//3 – O consumo médio dos pesquisados com interesse positivo.
float q3(int n, ficha *gas){
	float totpos=0,totcons;
	for (int i=0;i<n;i++){
		if(gas[i].inter==1){
			totpos++;
			totcons+=gas[i].conMor;
		}
	cons_med_pos=totcons/totpos;
	return cons_med_pos;	
}
}
//4 – O pesquisado de menor consumo com todos os seus dados
int q4(int n,ficha *gas){
	int i;
	float menorconsumo=3;
	for (i=0;i<n;i++){
		if(gas[i].conMor<menorconsumo){
			menorconsumo=gas[i].conMor;
			imenor=i;
		}
		}
	}
//5 – Percentual de pesquisados indiferentes a implantação.
float q5(int n, ficha *gas){
	float totindi=0;
	for (int i=0;i<n;i++){
		if(gas[i].inter==0){
			totindi++;
		}
	}
	percent_indiferente=totindi/n*100;
	return percent_indiferente;
}
//6 – O percentual de pesquisados negativos que tem rede instalada e positivo que não tem rede instalada.
void q6(int n, ficha *gas){
	float totneg=0,totnegrede=0;
	float totpos=0,totposrede=0;
	for (int i=0;i<n;i++){
		if(gas[i].inter==2){
			totneg++;
			if(gas[i].red==0){
				totnegrede++;	
			}
		}
		if(gas[i].inter==1){
			totpos++;
			if(gas[i].red==1){
				totposrede++;	
			}			
		}
	}
	percent_neg_rede=totnegrede/totneg*100;
	percent_pos_nrede=totposrede/totpos*100;
}


void resultado(float rq3,int rq4,float rq5,ficha *gas){
	printf("3- O consumo por morador medio dos pesquisados com interesse positivo:%.2f\n",cons_med_pos);
	printf("-------------------------------------------------------------------------------------------------------\n");
	printf("4- O pesquisado de menor consumo por morador com todos os seus dados:\n");
	printf("%s\t%s\t%s\t    %d\t\t  %s\t %s\t  %.1f\t\t%.2f\n",gas[imenor].codigo,gas[imenor].regiao,gas[imenor].tipo,gas[imenor].moradores,gas[imenor].interesse,gas[imenor].rede,gas[imenor].conMes,gas[imenor].conMor);
	printf("-------------------------------------------------------------------------------------------------------\n");	
	printf("5- Percentual de pesquisados indiferentes a implantação: %.2f%%.\n",percent_indiferente);
	printf("-------------------------------------------------------------------------------------------------------\n");
	printf("6- O percentual de pesquisados negativos que tem rede instalada   : %.2f%%.\n   O percentual de pesquisados positivo que não tem rede instalada: %.2f%%.\n",percent_neg_rede,percent_pos_nrede);		
}

void grava(int n,ficha *gas){
	FILE *pont_arq;
	pont_arq = fopen("Gas.txt", "w");
	if(pont_arq == NULL)
	{
		printf("Erro na abertura do arquivo!");
	}
	int i;
		fprintf(pont_arq,"======================================================================\n");
	for(i=0;i<n;i++){
		fprintf(pont_arq,"%s\t%s\t%s\t    %d\t\t  %s\t %s\t  %.1f\t\t%.2f\n",gas[i].codigo,gas[i].regiao,gas[i].tipo,gas[i].moradores,gas[i].interesse,gas[i].rede,gas[i].conMes,gas[i].conMor);
	}
	fprintf(pont_arq,"======================================================================\n");
	fprintf(pont_arq,"3- O consumo por morador medio dos pesquisados com interesse positivo:%.2f\n",cons_med_pos);
	fprintf(pont_arq,"-------------------------------------------------------------------------------------------------------\n");
	fprintf(pont_arq,"4- O pesquisado de menor consumo por morador com todos os seus dados:\n");
	fprintf(pont_arq,"%s\t%s\t%s\t    %d\t\t  %s\t %s\t  %.1f\t\t%.2f\n",gas[imenor].codigo,gas[imenor].regiao,gas[imenor].tipo,gas[imenor].moradores,gas[imenor].interesse,gas[imenor].rede,gas[imenor].conMes,gas[imenor].conMor);
	fprintf(pont_arq,"-------------------------------------------------------------------------------------------------------\n");
	fprintf(pont_arq,"5- Percentual de pesquisados indiferentes a implantação: %.2f%%.\n",percent_indiferente);
	fprintf(pont_arq,"-------------------------------------------------------------------------------------------------------\n");
	fprintf(pont_arq,"6- O percentual de pesquisados negativos que tem rede instalada   : %.2f%%.\n   O percentual de pesquisados positivo que não tem rede instalada: %.2f%%.\n",percent_neg_rede,percent_pos_nrede);			
	fprintf(pont_arq,"Dados gravados com sucesso!");
	fclose(pont_arq);
	
}

main(){
	float rq3,rq5;
	int rq4;
	srand(time(NULL));
	ficha gas[118];
	preencher(118,gas);
	apresentar(118,gas);
	rq3=q3(118,gas);
	rq4=q4(118,gas);
	rq5=q5(118,gas);
	q6(118,gas);
	resultado(rq3,rq4,rq5,gas);	
	grava(118,gas);	
}
