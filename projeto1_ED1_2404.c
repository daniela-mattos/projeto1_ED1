#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define TAM 18

int digitaInteiro();
bool testaInteiro(const char *str);
void pausa();
void consultaVetor(int vetor[TAM]);
void mostraVetor(int vetor[TAM]);
void removeNumero(int vetor[TAM], int *contaVetor);
void insereNumero(int vetor[TAM], int *contaVetor);

int main()
{
    int i, menu, vetor[TAM], contaVetor=0; 
    
    /*
    //FOR para teste de vetor cheio
    for(i=0;i<TAM;i++){
        vetor[i] = 100+i;
        contaVetor++;
    }
    */
    
    
    while(menu!=5) {
        printf("\n\nConsulte, remova ou insira valores num vetor.\n");
        printf("\n\t1 - Consulta posição");
        printf("\n\t2 - Mostrar Vetor");
        printf("\n\t3 - Inserir");
        printf("\n\t4 - Remover");
        printf("\n\t5 - Sair\n");
        
        printf("\n*--=--*\nO vetor esta com %i posições ocupadas.\n*--=--*\n", contaVetor);
        
        printf("\nInforme o número da opção desejada: ");    
            menu = digitaInteiro();
        
        switch(menu) {
            case 1: 
                if(contaVetor!=0) consultaVetor(vetor);
                else printf("\n*\nNão há posições ocupadas no vetor.\n*\n*\n\n");
            break;
            case 2: mostraVetor(vetor);
            break;
            case 3: 
                if(contaVetor>=TAM) {
                    printf("\n*--=--*\nO vetor está cheio. Não é possível inserir mais códigos.\n");
                    mostraVetor(vetor);
                } else {
                    printf("\ncontaVetor: %i\n", contaVetor);
                    insereNumero(vetor, &contaVetor);
                }
                break;
            case 4: 
                if(contaVetor==0) {
                    printf("Vetor já está vazio.");
                    mostraVetor(vetor);
                } else {
                    removeNumero(vetor, &contaVetor); //está com loop interno resolvido
                }
                break;
            case 5: printf("\nAplicação encerrada...");
            break;
            default: printf("\n*\nEntrada inválida. \nDigite um número entre 1 e 5.\n*\n*\n\n");
        } 
    }

    return 0;
}

void pausa(){
    printf("\n*\nPressione qualquer tecla para continuar...\n");
    getchar();
    system("clear");
    printf("\n*\n*\n\n");
}


bool testaInteiro(const char *str) {
    // Verifica se a string está vazia
    if (str[0] == '\0') {
        return false;
    }
    
    // Verifica cada caractere da string
    for (int i = 0; str[i] != '\0'; i++) {
        // Se o caractere não é um dígito, retorna falso
        if (!isdigit(str[i])) {
            return false;
        }
    }
    
    // Se todos os caracteres forem dígitos, retorna verdadeiro
    return true;
}

int digitaInteiro() {
    
    char numPalavra[100];
    while(1) {
        printf("\nDigite um número: ");
        
        // Lê a entrada do usuário como uma string
        fgets(numPalavra, sizeof(numPalavra), stdin);
        
        // Remove o caractere de nova linha, se tiver
        numPalavra[strcspn(numPalavra, "\n")] = '\0';
        
        // Verifica se a entrada é um número inteiro
        if (testaInteiro(numPalavra)) {
            int num = atoi(numPalavra); // Converte a string para um número inteiro
            printf("Você digitou o número: %d\n", num);
            return num;
        } else {
            printf("\n*\nEntrada inválida. Por favor, digite um número inteiro.\n*\n*\n\n");
            continue;
        }
    }
}

void consultaVetor(int vetor[TAM]) {
    system("clear");
    do {
        printf("\n\nEscolha a posição no vetor entre 1 e %d", TAM);
        int num = digitaInteiro();
        if(num<=TAM && num>0) {
            printf("\n*\nPosição %i \tCódigo: %d\n*\n", num, vetor[num-1]);
            pausa();
            break;
        } else {
            printf("\n*\nPosição inválida!\n*\n");
        }
    } while(1);    
}

void mostraVetor(int vetor[TAM]) {
    int i;
    
    //mostrando vetor completo
    printf("\n*\n*\n");
    for (i=0; i<TAM; i++) {
        printf("\nPosição: %i \tCódigo: %i", i+1, vetor[i]);
    }
    pausa();
}

void removeNumero(int vetor[TAM], int *contaVetor) {
    int i, num = 0;
    
    system("clear");
    
    while (1) {
        
        if(*contaVetor==0) {
            return;
        }
        printf("\nInforme a posição a ser removida (de 1 a %i): ", TAM);    
        printf("\nDigite -1 para voltar ao menu principal\n");
        scanf("%d", &num); getchar();
        
        if(num == -1) {
            printf("\n*\n*\nVoltando para o menu principal...\n");
            return;
        }
      
        if (num < 1 || num >= TAM) {
            printf("***Posição inválida.\n");
            continue; //volta para o início do loop
        }
        
        num--; // Ajusta o índice para a faixa de 1 a TAM-1
        
        if(vetor[num] == 0) {
            printf("*\n*\nPosição já está vazia.");
            continue;
        } else {
            // Reordena o vetor
            for (i = num; i < TAM - 1; i++) {
                vetor[i] = vetor[i + 1];
            }
            
            // Ajusta o último elemento para manter o vetor com o mesmo número de posições
            vetor[TAM - 1] = 0;
            (*contaVetor)--;
            
        }
        printf("\nVetor após remoção e reordenação:\n");
            mostraVetor(vetor);
    }    
}

void insereNumero(int vetor[TAM], int *contaVetor) {
    int i, numeroPosicao=0, numeroDigitado;
    
    system("clear");
    
    do {
        printf("\ncontaVetor: %i\n", *contaVetor);
        if (*contaVetor==TAM) {
        	return;
        }	
        
        printf("\nInforme a posição no vetor (de 1 a %i): ", TAM);   
        printf("\nDigite -1 para voltar ao menu principal\n");
        scanf("%i", &numeroPosicao); getchar();
        
        if(numeroPosicao == -1) {
            printf("\n*\n*\nVoltando para o menu principal...\n");
            return;
        }
        
        numeroPosicao--;
        
        if(numeroPosicao<0 || numeroPosicao>TAM-1) {
        	//valida posição no vetor
        	printf("Posição inválida. Insira um número entre 1 e %i: \n", TAM);
        	
        } else if (vetor[numeroPosicao] == 0 && *contaVetor == numeroPosicao) {
        	//insere o número no vetor
        	numeroDigitado = digitaInteiro();
        	vetor[numeroPosicao] = numeroDigitado;
            (*contaVetor)++;
            printf("Número inserido na posição indicada %d.\n", numeroPosicao);
            mostraVetor(vetor);
        	
        } else if (*contaVetor<numeroPosicao) {
        	//verifica qual a primeira posição vazia até posição => insere o número no vetor
        	numeroDigitado = digitaInteiro();
        	for(i=0;i<numeroPosicao;i++) {
                if(vetor[i] == 0) {
                //verifica qual a primeira posição vazia até posição => insere o número
                    vetor[i] = numeroDigitado;
                    (*contaVetor)++;
                        
                    printf("\n-------------------\n");
                    printf("Inserido %d na primeira posição disponivel: %d", numeroDigitado, i);
                    printf("\n-------------------\n");
                    
                    mostraVetor(vetor);
                    break;
                }
        	}    
        	
        } else {
        	//reordena posições no vetor e insere o valor
        	numeroDigitado = digitaInteiro();
        	
        	for(i=TAM-1;i>(numeroPosicao);i--) {
                    vetor[i] = vetor[i-1];    
                }
                
                //adiciona número na posição escolhida (já copiada para a posição seguinte)
                vetor[numeroPosicao] = numeroDigitado;
                (*contaVetor)++;
        	printf("Número inserido na posição %d. Reordenado\n", numeroPosicao);
        	mostraVetor(vetor);
        }
    } while(1);
}





