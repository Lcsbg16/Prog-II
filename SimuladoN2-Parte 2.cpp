#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<time.h>
struct ficha{
	char codigo[20];
	char setor[20];
	int set;
	char tipo[20];
	int tp;
	int idade;
	char sexo[20];
	int sex;
	int nota;
	char retorno[20];
	int ret;
	
};

void preencher(int n, ficha *paciente){
	int inicio=(rand()%100)+1001;
	for(int i=0;i<n;i++){
		paciente[i].set=(rand()%3)+1;
		paciente[i].tp=rand()%2;
		paciente[i].idade=(rand()%53)+18;
		paciente[i].sex=rand()%2;
		paciente[i].nota=rand()%101;
		paciente[i].ret=rand()%3;
		if(paciente[i].set==1){
			sprintf(paciente[i].setor,"Radiologia");
			if(paciente[i].tp==0){
				sprintf(paciente[i].codigo,"%dRPL",inicio+i);
			}
			if(paciente[i].tp==1){
				sprintf(paciente[i].codigo,"%dRPA",inicio+i);
			}	
		}
		if(paciente[i].set==2){
			sprintf(paciente[i].setor,"Ultrassom ");
			if(paciente[i].tp==0){
				sprintf(paciente[i].codigo,"%dUPL",inicio+i);
			}
			if(paciente[i].tp==1){
				sprintf(paciente[i].codigo,"%dUPA",inicio+i);
			}		
		}
		if(paciente[i].set==3){
			sprintf(paciente[i].setor,"Tomografia");
			if(paciente[i].tp==0){
				sprintf(paciente[i].codigo,"%dTPL",inicio+i);
			}
			if(paciente[i].tp==1){
				sprintf(paciente[i].codigo,"%dTPA",inicio+i);
			}			
		}
		
		if(paciente[i].tp==0){
			sprintf(paciente[i].tipo,"Plano     ");
		}		
		if(paciente[i].tp==1){
			sprintf(paciente[i].tipo,"Particular");
		}
		if(paciente[i].sex==0){
			sprintf(paciente[i].sexo,"Masculino");
		}
		if(paciente[i].sex==1){
			sprintf(paciente[i].sexo,"Feminino ");
		}		
		
		if(paciente[i].ret==0){
			sprintf(paciente[i].retorno,"Sim   ");
		}	
		if(paciente[i].ret==1){
			sprintf(paciente[i].retorno,"Talvez");
		}
		if(paciente[i].ret==2){
			sprintf(paciente[i].retorno,"Nao   ");
		}					
	}
}
void imprimir (int n, ficha *paciente){
	printf("Codigo \t\t Setor \t\t Tipo \t\tIdade \t   Sexo \t Nota \t Retornaria\n");
	printf("********************************************************************************************\n");
	for (int i=0;i<n;i++){
		printf("%s \t %s \t %s \t %d \t %s \t %d \t %s  \n",paciente[i].codigo,paciente[i].setor,paciente[i].tipo,paciente[i].idade,paciente[i].sexo,paciente[i].nota,paciente[i].retorno);
	}
}
//Percentual clientes do setor de Radiologia que deu notas maiores que 70
float percentrad70;
float q3(int n, ficha *paciente){
	float totrad=0,totrad70=0;
	for (int i=0;i<n;i++){
		if(paciente[i].set==1){
			totrad++;
			if(paciente[i].nota>70){
				totrad70++;
			}
		}
	}
	percentrad70=totrad70/totrad*100;
	return percentrad70;
}
//4 – Calcule a média das notas dadas pelos clientes Particulares
float medianotaPA;
float q4(int n, ficha *paciente){
	float totnotaPA=0,totPA=0;
	for (int i=0;i<n;i++){
		if(paciente[i].tp==1){
			totnotaPA+=paciente[i].nota;
			totPA++;
		}
	}
	medianotaPA=totnotaPA/totPA;
}
//5 – Calcule o percentual de clientes do tipo Plano que indicaram que retornariam Não.
float percentnaopl;
float q5(int n, ficha *paciente){
	float totpl=0,totnao=0;
	for (int i=0;i<n;i++){
		if(paciente[i].tp==0){
			totpl++;
			if(paciente[i].ret==2){
				totnao++;
			}
		}
	
	}
	percentnaopl=totnao/totpl*100;
	return percentnaopl;


}

//6 – Verifique e apresente todos os dados do atendimento que teve a menor nota.
int imenor;
int q6(int n, ficha *paciente){
	int menor=101;
	for (int i=0;i<n;i++){
		if(paciente[i].nota<menor){
			menor=paciente[i].nota;
			imenor=i;
		}
	}
	return imenor;
}


void resultado(float rq3,float rq4,float rq5,float rq6,ficha *paciente){
	printf("\n3-Percentual de clientes do setor de Radiologia que deu notas maiores que 70 => %.2f%%.",percentrad70);
	printf("\n4-A media das notas dadas pelos clientes Particulares => %.2f.",medianotaPA);
	printf("\n5-Percentual de clientes do tipo Plano que indicaram que nao retornariam => %.2f%%.",percentnaopl);
	printf("\n6-Menor Nota:\n%s \t %s \t %s \t %d \t %s \t %d \t %s  \n",paciente[imenor].codigo,paciente[imenor].setor,paciente[imenor].tipo,paciente[imenor].idade,paciente[imenor].sexo,paciente[imenor].nota,paciente[imenor].retorno);	
}
void grava(int n,ficha *paciente){
	FILE *pont_arq;
	pont_arq = fopen("Pacientes.txt", "w");
	if(pont_arq == NULL)
	{
		printf("Erro na abertura do arquivo!");
	}
	int i;
		fprintf(pont_arq,"======================================================================\n");
	for(i=0;i<n;i++){
		fprintf(pont_arq,"%s \t %s \t %s \t %d \t %s \t %d \t %s  \n",paciente[i].codigo,paciente[i].setor,paciente[i].tipo,paciente[i].idade,paciente[i].sexo,paciente[i].nota,paciente[i].retorno);
	}
	fprintf(pont_arq,"======================================================================\n");
	fprintf(pont_arq,"\n3-Percentual de clientes do setor de Radiologia que deu notas maiores que 70 => %.2f%%.",percentrad70);
	fprintf(pont_arq,"\n4-A media das notas dadas pelos clientes Particulares => %.2f.",medianotaPA);
	fprintf(pont_arq,"\n5-Percentual de clientes do tipo Plano que indicaram que nao retornariam => %.2f%%.",percentnaopl);
	fprintf(pont_arq,"\n6-Menor Nota:\n%s \t %s \t %s \t %d \t %s \t %d \t %s  \n",paciente[imenor].codigo,paciente[imenor].setor,paciente[imenor].tipo,paciente[imenor].idade,paciente[imenor].sexo,paciente[imenor].nota,paciente[imenor].retorno);
	
	fprintf(pont_arq,"Dados gravados com sucesso!");
	fclose(pont_arq);
	
}
main(){
	float rq3,rq4,rq5,rq6;
	ficha paciente[123];
	preencher(126,paciente);
	imprimir(126,paciente);
	rq3=q3(123,paciente);
	rq4=q4(123,paciente);
	rq5=q5(123,paciente);
	rq6=q6(123,paciente);
	resultado(rq3,rq4,rq5,rq6,paciente);
	grava(123,paciente);
}
