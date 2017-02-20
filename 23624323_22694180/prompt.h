#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
 
void mostrar_prompt() {
	int i,ultima_barra, aux2, fallo;
	char aux;
	char *aux3, *login;
	char nombre_host[256], dir_actual[1000], carpeta_actual[1000];
	fallo=0;
	login=getenv("USER");
	if(login==NULL){
		printf("no hay user\n");
		fallo=1;
	}
	aux2=gethostname(nombre_host, 256);
	if (aux2==-1){
		perror("no hay host\n");
		fallo=1;
	}
	aux3=getcwd(dir_actual, 1000);
	if (aux3 == NULL){
		perror("no hay dir\n");
		fallo=1;
	}

	if(!fallo){
		i=0;
		while( (aux=dir_actual[i])!= 0 ){
			if (aux=='/') ultima_barra=i;
			i++;
		}
		if(ultima_barra==0) strcpy(carpeta_actual, dir_actual);
		else strcpy(carpeta_actual, &dir_actual[ultima_barra+1]);
		printf("[%s@%s:~/%s]$> ", login, nombre_host, carpeta_actual);
		fflush(stdout);
	}else{
		printf("$");
		fflush(stdout);
	}
}

