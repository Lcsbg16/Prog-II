#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
#include <locale.h>

struct ficha{
	char codigo[20];
	char tipo[20];
	int tp;
	int ano;
	char campo[20];
	int camp;
	float HC;
	int HC_aux;
	float HP;
	float prod;
	float coef;	
};
float med_hp_sm;
int imaior;
float med_prod_1,med_prod_2,med_prod_3;
float percent_marlim_m800,percent_roncador_m800;
void preencher(int n, ficha *plat){
	int inicio;
	inicio=(rand()%12)+101;
	for (int i=0;i<n;i++){
		plat[i].tp=(rand()%3)+1;
		plat[i].ano=(rand()%20)+2000;
		plat[i].camp=(rand()%3)+1;
		plat[i].HC_aux=rand()%2;
		plat[i].HP=rand()%3601;
		plat[i].prod=(rand()%1501)+1000;
		if(plat[i].tp==1){
			sprintf(plat[i].tipo,"Fixa            ");
			sprintf(plat[i].codigo,"%dFX%2.d",inicio+i,plat[i].ano-2000);
		}
		if(plat[i].tp==2){
			sprintf(plat[i].tipo,"Navio Sonda     ");
			sprintf(plat[i].codigo,"%dNS%2.d",inicio+i,plat[i].ano-2000);
		}
		if(plat[i].tp==3){
			sprintf(plat[i].tipo,"Semi Submersível");
			sprintf(plat[i].codigo,"%dSS%2.d",inicio+i,plat[i].ano-2000);
		}
		if(plat[i].camp==1)	{
			sprintf(plat[i].campo,"Marlim");	
		}
		if(plat[i].camp==2)	{
			sprintf(plat[i].campo,"Albacora");	
		}					
		if(plat[i].camp==3)	{
			sprintf(plat[i].campo,"Roncador");	
		}
		
		if(plat[i].HC_aux==0){
			plat[i].HC=8760;
		}
		if(plat[i].HC_aux==1){
			plat[i].HC=17520;
		}
		plat[i].coef=(plat[i].prod/(plat[i].HC-plat[i].HP))*1000;				
	}
}
//2 – A média de Horas paradas das Plataformas do tipo Semi Submersível
void q2(int n, ficha *plat){
	float totsm=0,totsmhp=0;
	for (int i=0;i<n;i++){
		if(plat[i].tp==3){
			totsm++;
			totsmhp+=plat[i].HP;
		}
	}
	med_hp_sm=totsmhp/totsm;
}
//3 – A plataforma de maior coeficiente com todos os seus dados.
void q3(int n, ficha *plat){
	float maior=0;
	for (int i=0;i<n;i++){
		if(plat[i].coef>maior){
			maior=plat[i].coef;
			imaior=i;
		}
	}
	
}
//4 - O percentual de Plataformas dos Campos de Roncador e Marlim com HP menor que 800.
void q4(int n, ficha *plat){
	float tothpm800=0,tot_camp1_menor800=0,tot_camp3_menor800=0;
	for (int i=0;i<n;i++){
		if(plat[i].HP<800){
			tothpm800++;
			if(plat[i].camp==1){
				tot_camp1_menor800++;
			}
			if(plat[i].camp==3){
				tot_camp3_menor800++;
			}			
		}
	}
	percent_roncador_m800=tot_camp3_menor800/tothpm800*100;
	percent_marlim_m800=tot_camp1_menor800/tothpm800*100;	
}
//5 - A média de produção das plataformas de cada campo.
void q5(int n, ficha *plat){
	float totcamp1=0,totprod1=0;
	float totcamp2=0,totprod2=0;
	float totcamp3=0,totprod3=0;
	for (int i=0;i<n;i++){
		if(plat[i].camp==1){
			totcamp1++;
			totprod1+=plat[i].prod;
		}	
		if(plat[i].camp==2){
			totcamp2++;
			totprod2+=plat[i].prod;
		}
		if(plat[i].camp==3){
			totcamp3++;
			totprod3+=plat[i].prod;
		}				
	}
	med_prod_1=totprod1/totcamp1;
	med_prod_2=totprod2/totcamp2;
	med_prod_3=totprod3/totcamp3;
}





void resultado(int n, ficha *plat){
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");	
	printf("\n2)A média de Horas paradas das Plataformas do tipo Semi Submersível:%.1f.\n\n",med_hp_sm);
	printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("\n3)A plataforma de maior coeficiente com todos os seus dados:");
	printf("\n%s \t %s \t %d \t %s \t %.0f \t %.0f \t %.0f \t\t %.2f\n",plat[imaior].codigo,plat[imaior].tipo,plat[imaior].ano,plat[imaior].campo,plat[imaior].HC,plat[imaior].HP,plat[imaior].prod,plat[imaior].coef);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	printf("\n4)O percentual de Plataformas do Campo de Marlim => %.2f%%.",percent_marlim_m800);
	printf("\n  O percentual de Plataformas do Campo de Roncador => %.2f%%.\n",percent_roncador_m800);
	printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");	
	printf("\n5)A média de produção das plataformas de cada campo:\n");
	printf("Marlim  : %.1f.\n",med_prod_1);
	printf("Albacora: %.1f.\n",med_prod_2);
	printf("Roncador: %.1f.\n",med_prod_3);
	
}

void imprimir(int n, ficha *plat){
	printf("Código \t\t Tipo \t\t\t Ano \t Campo \t\t HC \t HP \t Produção \t Coeficiente\n");
	printf("-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-\n");
	for (int i=0;i<n;i++){
		printf("%s \t %s \t %d \t %s \t %.0f \t %.0f \t %.0f \t\t %.2f\n",plat[i].codigo,plat[i].tipo,plat[i].ano,plat[i].campo,plat[i].HC,plat[i].HP,plat[i].prod,plat[i].coef);
	}
}

void grava(int n,ficha *plat){
	FILE *pont_arq;
	pont_arq = fopen("plataformas.txt", "w");
	if(pont_arq == NULL)
	{
		printf("Erro na abertura do arquivo!");
	}
	int i;
		fprintf(pont_arq,"======================================================================\n");
	for(i=0;i<n;i++){
		fprintf(pont_arq,"%s \t %s \t %d \t %s \t %.0f \t %.0f \t %.0f \t\t %.2f\n",plat[i].codigo,plat[i].tipo,plat[i].ano,plat[i].campo,plat[i].HC,plat[i].HP,plat[i].prod,plat[i].coef);	
	}
	fprintf(pont_arq,"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");	
	fprintf(pont_arq,"\n2)A média de Horas paradas das Plataformas do tipo Semi Submersível:%.1f.\n\n",med_hp_sm);
	fprintf(pont_arq,"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	fprintf(pont_arq,"\n3)A plataforma de maior coeficiente com todos os seus dados:");
	fprintf(pont_arq,"\n%s \t %s \t %d \t %s \t %.0f \t %.0f \t %.0f \t\t %.2f\n",plat[imaior].codigo,plat[imaior].tipo,plat[imaior].ano,plat[imaior].campo,plat[imaior].HC,plat[imaior].HP,plat[imaior].prod,plat[imaior].coef);
	fprintf(pont_arq,"\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
	fprintf(pont_arq,"\n4)O percentual de Plataformas do Campo de Marlim => %.2f%%.",percent_marlim_m800);
	fprintf(pont_arq,"\n  O percentual de Plataformas do Campo de Roncador => %.2f%%.\n",percent_roncador_m800);
	fprintf(pont_arq,"\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");	
	fprintf(pont_arq,"\n5)A média de produção das plataformas de cada campo:\n");
	fprintf(pont_arq,"Marlim  : %.1f.\n",med_prod_1);
	fprintf(pont_arq,"Albacora: %.1f.\n",med_prod_2);
	fprintf(pont_arq,"Roncador: %.1f.\n",med_prod_3);
	fprintf(pont_arq,"======================================================================\n");
	fprintf(pont_arq,"Dados gravados com sucesso!");
	fclose(pont_arq);
	
}



main(){
	setlocale(LC_ALL, "portuguese");
//	srand(time(NULL));
	ficha plat[12];
	preencher(12,plat);
	q2(12,plat);
	q3(12,plat);
	q4(12,plat);
	q5(12,plat);
	imprimir(12,plat);
	grava(12,plat);
	resultado(12,plat);

}
