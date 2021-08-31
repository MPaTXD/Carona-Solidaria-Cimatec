#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
struct carro {
	char placacarro [9];
	char modelocarro [15];
	char corcarro [10];
	int anocarro;
};
struct endereco {
	char bairro [30];
	char complemento [35];
};
struct usuarios {	
	char nome [30];
	int cpf;
	int senha;
	char email [30];
	struct carro car;
	struct endereco end;
	char numerocelular [10];
	float nota;
	int dispmot;
	int dispcarona;
	int registmotorista;	
	int carro;
	int numviagens;
};
int motorista (struct usuarios vetmotorista[], int jy){
	system ("cls");
	int u, z,i, o=25, nuta;
	do {	
	if (vetmotorista[jy].carro == 0){
		system ("cls");
		printf ("Voc� n�o registrou um carro, para atuar como motorista.\n\n");
		break;
	}
	printf(" #         #                                                   \n");
    printf(" ##       ##    ###  #####  ###   #####  #  ### #####    #     \n");
    printf(" # #     # #   #   #   #   #   #  #   #  # #      #     # #    \n");
    printf(" #  #   #  #   #   #   #   #   #  ####   #  ###   #    #   #   \n");
    printf(" #   # #   #   #   #   #   #   #  #   #  #     #  #   #######  \n");
    printf(" #    #    #    ###    #    ###   #    # #  ###   #  #       # \n");
    printf("\n");
	printf ("\n\n|======== Bem vindo, usu�rio %s ! Voc� realizou login como motorista ========|\n", vetmotorista[jy].nome);
	printf ("Para escolher uma op��o do menu, digite o n�mero correspondente\n\n|==== 1 - Fornecer carona ====|\n|===== 2 - Solicita��es de carona =====|\n");
	printf ("|===== 3 - Verificar sua avalia��o =====|\n\n Digite 0 para voltar ao menu principal.");
	scanf ("%d", &o);
	switch (o)
	{
		case 1: 
				system ("cls");
				fflush (stdin);
				if (vetmotorista[jy].dispmot == 0){
					printf ("Agora voc� est� dispon�vel para fornecer caronas! Receber� solicita��es dos usu�rios que o requisitarem.");
					vetmotorista[jy].dispmot = 1;
					} else if (vetmotorista[jy].dispmot == 2) {
						printf ("Voc� est�, atualmente, fornecendo carona para a institui��o CIMATEC \n \n Deseja encerrar a viagem? Caso sim, digite 1. \n");
						scanf ("%d", &u);
						if (u == 1){
							system ("cls");
							printf ("Avalie seu passageiro! Digite a nota dele\n");
							scanf ("%f", &nuta);
							if (nuta >= 0 && nuta <= 5){
							vetmotorista[jy].nota =+ nuta;
							vetmotorista[jy].dispmot = 0;
							vetmotorista[jy].numviagens++;
						} else { 
							printf ("Sua nota foi inv�lida! Iremos considerar ela como 0. \n");
							vetmotorista[jy].dispmot = 0;
							vetmotorista[jy].numviagens++;
						}
				}					
			} else {
				printf ("\n\nVoc� est� com a carona em aberto! V� at� a tela de solicita��es de carona, para escolher um caroneiro\n");
			}
				break;				
		case 2:  
				system ("cls");
				printf ("Aqui est�o suas solicita��es de carona \n\n");
				for (i = 0; i < 100; i++){ 
					if (vetmotorista[i].dispcarona == 1){			
						printf ("Nome do caroneiro: %s \n N�mero do celular: %s \n E-mail: %s \n", vetmotorista[i].nome, vetmotorista[i].numerocelular,  vetmotorista[i].email);
						printf ("Endere�o: %s \n Complemento do endere�o: %s \n\n",  vetmotorista[i].end.bairro, vetmotorista[i].end.complemento);
						printf ("Avalia��o do usu�rio: %f", vetmotorista[i].nota/vetmotorista[i].numviagens);
						printf ("Deseja fornecer carona solid�ria para este usu�rio? \n Digite 1 para fornecer.");
						scanf ("%d", &z);
						if (z == 1){
							vetmotorista[jy].dispmot = 2;
							vetmotorista[i].dispcarona = 2;
							vetmotorista[i].registmotorista = jy; // O n�mero, no caso, corresponde a posi��o dos vetores, para que os perfis respectivos possam ser chamados em qualquer momento nas diferentes functions
							vetmotorista[jy].registmotorista = i;
						} else {
							printf ("Usu�rio recusado \n\n");
						}	
					}
				}				
				break;				
		case 3: 
				system ("cls");
				printf ("Sua avalia��o, de 1 a 5 estrelas, segundo os usu�rios, corresponde a \n: %f estrelas!", vetmotorista[jy].nota/vetmotorista[jy].numviagens);
				break;
		default:
				printf ("Op��o inv�lida!");
				system ("cls");
				break;						
		}
	} while (o != 0); 
}
int carona (struct usuarios vetcarona[], int jj){
	system ("cls");
	int r = 1, ki, viaj, yp, canc, notaa;
	do {	
	system ("cls");
	printf ("\n\n |======== Bem vindo, usu�rio %s, voc� realizou login como caroneiro! ========|\n\n", vetcarona[jj].nome);
	if (vetcarona[jj].dispcarona == 0){
			printf ("=== Atualmente dispon�vel ===\nPara escolher uma op��o do menu, digite o n�mero correspondente\n\n|==== 1 - Solicitar carona ====|\n|===== 2 - Verificar sua avalia��o =====|\n |==== 3 - Alterar endere�o ====|\n \n");
		} else if (vetcarona[jj].dispcarona == 2){
			 printf ("=== Atualmente recebendo carona ===\nPara escolher uma op��o do menu, digite o n�mero correspondente\n\n|==== 1 - Carona atual ====|\n|===== 2 - Verificar sua avalia��o =====|\n |==== 3 - Alterar endere�o ====|\n\n");
		} else {
			printf ("=== Carona solicitada ===\nPara escolher uma op��o do menu, digite o n�mero correspondente\n\n|==== 1 - Cancelar solicita��o ====|\n|===== 2 - Verificar sua avalia��o =====|\n |==== 3 - Alterar endere�o ====|\n \n");
		}
	printf ("Digite 0 para voltar para o menu principal\n");
	scanf ("%d", &r);
	switch (r)
	{
		case 1:
				if (vetcarona[jj].dispcarona == 0){
					system ("cls");
					printf ("Deseja solicitar uma carona? \n Voc� ir� realizar uma solicita��o para os motoristas dispon�veis\n");
					printf ("Digite 1 para solicitar\n");
					scanf ("%d", &ki);
					if (ki == 1){
					printf ("Solicita��o realizada! Aguarde algum motorista aceitar voc�\n");
						vetcarona[jj].dispcarona = 1;
					}
				} else if (vetcarona[jj].dispcarona == 2){
					system ("cls");
					printf ("Sua viagem atual � com o motorista de seguintes informa��es: \n Nome do motorista: %s \n Destino: CIMATEC \n  E-mail do motorista: %s\n", vetcarona[vetcarona[jj].registmotorista].nome, vetcarona[vetcarona[jj].registmotorista].email);
					printf ("Placa do carro: %s \n Modelo do carro: %s \n Cor do carro: %s \n Celular do motorista: %s \n ", vetcarona[vetcarona[jj].registmotorista].car.placacarro, vetcarona[vetcarona[jj].registmotorista].car.modelocarro, vetcarona[vetcarona[jj].registmotorista].car.corcarro, vetcarona[vetcarona[jj].registmotorista].numerocelular);
					printf ("Avalia��o do motorista: %d\n\n", vetcarona[vetcarona[jj].registmotorista].nota/vetcarona[vetcarona[jj].registmotorista].numviagens);
					printf ("A viagem j� foi encerrada? Digite 1 se sim");
					scanf ("%d", &viaj);
					if (viaj == 1){
						vetcarona[jj].dispcarona = 0;
						printf ("Avalie o seu motorista. Digite seu n�mero de estrelas, de 1 a 5 \n");
						scanf ("%f", &notaa);
						if (notaa >= 0 && notaa <= 5){
							vetcarona[vetcarona[jj].registmotorista].nota = notaa;
							vetcarona[jj].numviagens++;
						} else {
							system ("cls");
							printf ("A nota � inv�lida, consideraremos a nota como 0!");
							vetcarona[jj].numviagens++;
						}		
					}
				} else {
					system ("cls");
					printf ("\nDeseja cancelar a solicita��o de carona? \n Digite 1 para cancelar\n");
					scanf ("%d", &canc);
					system ("cls");
					if (canc == 1){
						printf ("Sua solicita��o foi cancelada!\n");
						vetcarona[jj].dispcarona = 0;	
					}
				} 
				break;
		case 2:
				system ("cls");
				printf ("Sua avalia��o pelos outros usu�rios � : %f \n ", vetcarona[jj].nota/vetcarona[jj].numviagens);
				break;
		case 3: 
				system ("cls");
				printf ("Deseja alterar seu endere�o? Digite 1 se sim \n \n");
				scanf ("%d", &yp);
				if (yp == 1){
					printf ("Digite seu novo endere�o \n Digite o bairro \n");
					fflush (stdin);
					fgets (vetcarona[jj].end.bairro, 30, stdin);
					fflush (stdin);
					printf ("\n Agora o complemento do endere�o");
					fgets (vetcarona[jj].end.complemento, 35, stdin);
					fflush (stdin);
				} 
				break;
		default:
				system ("cls");
				printf ("Op��o inv�lida!");
				break;
			}
	} while (r != 0);
}
int tela1 (struct usuarios vetor1[], int j){
	int choose;
	system("cls");
	printf("Login realizado com sucesso!\n");
	printf("\n");
    printf("&&&&   &&&&  &       &       &       &  &  &   &  &&&&&    &&&  \n");
    printf("&   &  &     &&     &&        &     &   &  &&  &  &    &  &   & \n");
    printf("&&&&   &&&&  & &   & &   &&&   &   &    &  & & &  &    &  &   & \n");
    printf("&   &  &     &  & &  &   &&&    & &     &  &  &&  &    &  &   & \n");
    printf("&&&&   &&&&  &   &   &           &      &  &   &  &&&&&    &&&  \n");
	printf("\n");
	printf("%s",vetor1[j].nome);
	printf("========= \nVoc� agora, deve selecionar se atuar� como motorista ou se receber� a carona \n=========\n");
	printf("\n Digite 1, caso seja um motorista \n Digite 2 para receber a carona\n");
	scanf ("%d", &choose);
	switch (choose){
		case 1:
			motorista (vetor1, j);
			break;
		case 2:
			carona (vetor1, j);
			break;
		default:
				system ("cls");
				printf ("Op��o inv�lida!");		
				break;
	}		
}
int login (struct usuarios vet[]){
	int i, cp, senha1;
	system ("cls");
	printf("=========================================================================\n");
	printf("+ @@@@@ @@@@  @        @       @@@@  @@@@    @     @@@    @@@  @  @   @ +\n");
    printf("+   @   @     @       @ @      @   @ @       @    @   @  @     @  @@  @ +\n");
    printf("+   @   @@@@  @      @   @     @   @ @@@@    @    @   @  @ @@  @  @ @ @ +\n");
    printf("+   @   @     @     @@@@@@@    @   @ @       @    @   @  @  @  @  @  @@ +\n");
    printf("+   @   @@@@  @@@@ @       @   @@@@  @@@@    @@@@  @@@    @@@  @  @   @ +\n");
    printf("=========================================================================\n");
	printf("DIGITE SEU CPF       =\nSEGUIDO DA SUA SENHA =\n");
	printf("======================\n");
	printf("\n");
	scanf ("%d\n", &cp);
	for (i=0; i < 100; i++){
		if (cp == vet[i].cpf){
			scanf ("%d", &senha1);
			if (senha1 == vet[i].senha){
				system ("cls");
				tela1 (vet, i);
			} else {
				system ("cls");
				printf ("Senha inv�lida.");
			}	
		} else
			system ("cls"); 
			("CPF n�o registrado.");
	}
}
int registrar (struct usuarios vet[], int x){
	int i,cpfi, carru;
	printf("                              *********************************************************************************************************\n");
	printf("                              *  *****  *****  *         *        ****   *****    *****   *****   ****  *  **** ***** *****   ***     *\n");
	printf("                              *    *    *      *        * *       *   *  *        *   *   *      *      * *       *   *   *  *   *    *\n");
	printf("                              *    *    *****  *       *****      *   *  *****    ****    *****  * ***  *  ****   *   ****   *   *    *\n");
	printf("                              *    *    *      *      *     *     *   *  *        *   *   *      *   *  *      *  *   *   *  *   *    *\n");
	printf("                              *    *    *****  ***** *       *    ****   *****    *    *  *****   ****  *  ****   *   *    *  ***     *\n");
	printf("                              *********************************************************************************************************\n");
	printf("                              *                                                                                                       *\n");
	printf("                              *-----------------------------> INFORME SEU CPF (LIMITE DE 11 DIGITOS) <--------------------------------*\n");
	printf("\n");
	printf("                              ");
	scanf ("%d",&cpfi);
	for (i=0; i < 100; i++){
		if (vet[i].cpf == cpfi){
			printf ("CPF j� registrado!\n");
			break;
		} else {
			vet[x].cpf = cpfi;
		}
	}
	printf("\n");
	fflush(stdin);
	printf("                              *---------------------------------------> INFORME SEU NOME <--------------------------------------------*\n");
	printf("\n");
	printf("                              ");
	fgets (vet[x].nome, 30, stdin);
	printf("\n");
	fflush(stdin);
	printf("                              *---------------------------------------> INFORME SEU EMAIL <-------------------------------------------*\n");
	printf("\n");
	printf("                              ");
	fgets (vet[x].email, 30, stdin);
	printf("\n");
	fflush(stdin);
	printf("                              *---------------------------------> INFORME SEU N�MERO DE CELULAR <-------------------------------------*\n");
	printf("\n");
	printf("                              ");
	fgets (vet[x].numerocelular, 10, stdin);
	printf("\n");
	fflush(stdin);
	printf("                              *------------------------------> AGORA INFORME SEU ENDERE�O E BAIRRO <----------------------------------*\n");
	printf("\n");
	printf("                              ");
	fgets (vet[x].end.bairro, 30, stdin);
	printf("\n");
	fflush(stdin);
	printf("                              *------------------------------> INFORME O COMPLEMENTO PARA O ENDERE�O <---------------------------------*\n");
	printf("\n");
	printf("                              ");
	fgets (vet[x].end.complemento, 35, stdin);
	printf("\n");
	fflush(stdin);
	system("cls");
	printf("                                                      *******************************************************\n");
	printf("                                                      * #####     #      #####  #####  #####        ####### *\n");
	printf("                                                      * #    #   # #     #   #    #    #                  # *\n");
	printf("                                                      * #####   #####    ####     #    #####        ####### *\n");
	printf("                                                      * #      #     #   #   #    #    #            #       *\n");
	printf("                                                      * #     #       #  #    #   #    #####        ####### *\n");
	printf("                                                      *******************************************************\n");
	printf("\n");
	printf("                                                      VOC� POSSUI UM CARRO?\n");
	printf("\n");
	printf("                                                      ------------------------\n");
	printf("                                                      --> SE POSSUI DIGITE 1 -\n");
	printf("                                                      --> SE N�O DIGITE 2    -\n");
	printf("                                                      ------------------------\n");
	printf("                                                      ");
	scanf ("%d", &carru);
	fflush(stdin);
	if (carru == 1){
		vet[x].carro = 1;
		system("cls");
		printf("                                              ====================================================================\n");
		printf("                                              *   ####  #####  #   #      ####     #      #####  #####    ###    *\n");
		printf("                                              *  #      #      #   #     #        # #     #   #  #   #   #   #   *\n");
		printf("                                              *   ####  #####  #   #     #       #####    ####   ####    #   #   *\n");
		printf("                                              *      #  #      #   #     #      #     #   #   #  #   #   #   #   *\n");
		printf("                                              *  ####   #####   ###       #### #       #  #    # #    #   ###    *\n");
		printf("                                              ====================================================================\n");
		printf("\n");
		printf("                                              *= DIGITE AS INFORMA��ES DO SEU CARRO || INFORME A PLACA DO CARRO =*\n");
		printf("\n");
		printf("                                              ");
		fgets (vet[x].car.placacarro, 8, stdin);
		fflush(stdin);
		printf("\n");
		printf("                                              *==================> INFORME O MODELO DO CARRO <===================*\n");
		printf("\n");
		printf("                                              ");
		fgets (vet[x].car.modelocarro, 15, stdin);
		fflush(stdin);
		printf("\n");
		printf("                                              *====================> INFORME A COR DO CARRO <====================*\n");
		printf("\n");
		printf("                                              ");
		fgets (vet[x].car.corcarro, 10, stdin);
		fflush(stdin);
		printf("\n");
		printf("                                              *=============> INFORME O ANO DE FABRICA��O DO CARRO <=============*\n");
		printf("\n");
		printf("                                              ");
		scanf ("%d", &vet[x].car.anocarro);
		fflush(stdin);		
	}
	system("cls");
	printf("                                                    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("                                                    !  @@@@  @   @      @        @@@@  @@@@@  @   @  @  @     @     !\n");
	printf("                                                    ! @      @   @     @ @      @      @      @@  @  @  @    @ @    !\n");
	printf("                                                    !  @@@   @   @    @   @      @@@   @@@@@  @ @ @  @@@@   @   @   !\n");
	printf("                                                    !     @  @   @   @@@@@@@        @  @      @  @@  @  @  @@@@@@@  !\n");
	printf("                                                    ! @@@@    @@@   @       @   @@@@   @@@@@  @   @  @  @ @       @ !\n");
    printf("                                                    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    printf("\n");
	printf("                                                    -> PARA COMPLETAR SEU CADASTRO <-\n");
	printf("                                                    -> CRIE UMA SENHA\n\n");
	printf("                                                    ");
	scanf ("%d", &vet[x].senha);
	fflush (stdin);
	system ("cls");	
}
main (){
	struct usuarios Usuariox [100];
	int z,k, num = 0;
	setlocale (LC_ALL, "Portuguese");
	int menu = 1;
	z = 0;
	do {
	system("MODE con cols=168 lines=60");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("                                                                                                                                                 \n");
	printf("                                 **********************************************************************************************************\n");
	printf("                                 *                                                                             ################           *\n");
	printf("                                 *                                                                            #  ############  #          *\n");
	printf("                                 *              #     #        ###     #####     #####                       #  #            #  #         *\n");
	printf("                                 *             # #   # #      #   #    #   #     #                          #  #              #  #        *\n");
	printf("                                 *            #   # #   #     #   #    ####      #####                     #  #                #  #       *\n");
	printf("                                 *           #     #     #    #   #    #   #     #                      # #   ##################   # #    *\n");
	printf("                                 *          #             #    ###     #    #    #####                 #     ###              ###     #   *\n");
	printf("                                 *                                                                     #    #   #            #   #    #   *\n");
	printf("                                 *     #####   #####     #    #####   #   #   #####     #######        #     ###              ###     #   *\n");
	printf("                                 *     #       #   #     #    #       ##  #   #    #   #               #                              #   *\n");
	printf("                                 *     #####   ####      #    #####   # # #   #    #    ######         ###   ###################    ###   *\n");
	printf("                                 *     #       #   #     #    #       #  ##   #    #          #          #   #                  #   #     *\n");
	printf("                                 *     #       #    #    #    #####   #   #   #####    #######            ###                    ###      *\n");
	printf("                                 *                                                                                                        *\n");
	printf("                                 **********************************************************************************************************\n");
	printf("                                 *                            ->  Bem vindo ao aplicativo de carona solid�ria!  <-                        *\n");
	printf("                                 *                          -> J� possui uma conta? Digite 1 para realizar login! <-                      *\n");
	printf("                                 *                             -> � um novo usu�rio? Digite 2 para se registrar! <-                       *\n");
	printf("                                 *                                                                                                        *\n");
	printf("                                 *                                      >>>> Para sair, digite 0. <<<<                                    *\n");
	printf("                                 **********************************************************************************************************\n");
	printf("                                 ");
		if (z == 0){
			for (k = 0; k < 100; k++){
				Usuariox[k].dispmot = 0;
				Usuariox[k].dispcarona = 0;
				Usuariox[k].nota = 0;
				Usuariox[k].carro = 0;
				Usuariox[k].cpf = 0;
			}
		} // Isso inicializa algumas vari�veis dos usu�rios do sistema como 0, limpando os eventuais lixos de mem�ria 
		scanf ("%d", &menu);
		z++;
		system ("cls");
		switch (menu){
			case 1:
			login (Usuariox);
			break;		
			case 2: 
			registrar (Usuariox, num);
			num++;
			break;
			case 0:
			printf ("Obrigado por usar o aplicativo! Cr�ditos - Equipe NAE Batedeira\n\n");
			break;
			default:
			printf ("Digite uma op��o v�lida.\n\n");						
		}				 				
	} while (menu != 0);	
}
	
