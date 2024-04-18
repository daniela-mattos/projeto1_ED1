#include <stdio.h>
#define TAM 5

int digitaInteiro();
void consultaVetor(int vetor[TAM]);
void mostraVetor(int vetor[TAM]);
void removeNumero(int vetor[TAM], int contaVetor);
void insereNumero(int vetor[TAM], int contaVetor);

int main()
{
    int i, menu, vetor[TAM], contaVetor=0;
    
    //inserindo valores para teste
    for (i=0; i<TAM; i++) {
        vetor[i] = 100+i;
    }
    
    while(menu!=4) {
        printf("\n\nConsulte, remova ou insira valores num vetor.\n");
        printf("\n\t1 - Consulta");
        printf("\n\t2 - Inserir");
        printf("\n\t3 - Remover");
        printf("\n\t4 - Sair\n");
        
        printf("\nInforme o número da opção desejada: ");    
            menu = digitaInteiro();
        
        switch(menu) {
            case 1: consultaVetor(vetor);
            break;
            case 2: 
                if(contaVetor>=TAM) {
                    printf("\nO vetor está cheio. Não é possível inserir mais valores.\n");
                    mostraVetor(vetor);
                } else {
                    printf("\ncontaVetor: %i\n", contaVetor);
                    insereNumero(vetor, contaVetor);
                }
                break;
            case 3: 
                if(contaVetor==0) {
                    printf("Vetor já está vazio.");
                    mostraVetor(vetor);
                } else {
                    removeNumero(vetor, contaVetor); //está com loop interno resolvido
                }
                break;
            case 4: //sair?
            break;
        } 
    }

    return 0;
}

int digitaInteiro() {
    int num;
    
    do {
        printf("\n\nDigite um número inteiro: ");
        scanf("%i", &num); getchar();
        if(num>0) {
            break;
        }
    } while (1);
    
    return num;
}

void consultaVetor(int vetor[TAM]) {
    do {
        printf("\n\nEscolha a posição no vetor entre 1 e %d", TAM);
        int num = digitaInteiro();
        if(num<TAM-1 && num>=0) {
            printf("\n*\nPosição %i \tValor: %d\n*\n", num, vetor[num]);
            break;
        } else {
            printf("\n*\nPosição inválida!\n*\n");
        }
    } while(1);    
}

void mostraVetor(int vetor[TAM]) {
    //mostrando vetor completo
    int i;
    for (i=0; i<TAM; i++) {
        printf("\nPosição: %i \tValor: %i", i, vetor[i]);
    }
}

void removeNumero(int vetor[TAM], int contaVetor) {
        int i, num = 0;
    
    while (1) {
        
        if(contaVetor==0) {
            return;
        }
        printf("\nInforme a posição a ser removida (de 1 a %i): ", TAM);    
        printf("\nDigite -1 para voltar ao menu principal\n");
        scanf("%d", &num);
        
        if(num == -1) {
            printf("\nPrograma encerrado...\n");
            return;
        }
        
        num--; // Ajusta o índice para a faixa de 0 a TAM-1
        
        if (num < 0 || num >= TAM) {
                printf("***Posição inválida.\n");
                continue; //volta para o início do loop
            }
    
        // Reordena o vetor após a remoção
        for (i = num; i < TAM - 1; i++) {
            vetor[i] = vetor[i + 1];
        }
        
        // Ajusta o último elemento para manter o vetor com o mesmo número de posições
        vetor[TAM - 1] = 0;
        contaVetor--;
        
        printf("\nVetor após remoção e reordenação:\n");
        for (i = 0; i < TAM; i++) {
            printf("Vetor[%i] %i\n", i, vetor[i]);
        }
        
    }    
}

void insereNumero(int vetor[TAM], int contaVetor) {
    int i, numeroPosicao=0, numeroDigitado;
    
    do {
        printf("\ncontaVetor: %i\n", contaVetor);
        if (contaVetor==TAM) {
        	return;
        }	
        
        printf("\nInforme a posição no vetor (de 1 a %i): ", TAM);    
        scanf("%i", &numeroPosicao);
        numeroPosicao--;
        
        if(numeroPosicao<0 || numeroPosicao>TAM-1) {
        	//valida posição no vetor
        	printf("Posição inválida. Insira um número entre 0 e 4: \n");
        	
        } else if (vetor[numeroPosicao] == 0 && contaVetor == numeroPosicao) {
        	//insere o número no vetor
        	numeroDigitado = digitaInteiro();
        	vetor[numeroPosicao] = numeroDigitado;
            contaVetor++;
            printf("Número inserido na posição indicada %d.\n", numeroPosicao);
            mostraVetor(vetor);
        	
        } else if (contaVetor<numeroPosicao) {
        	//verifica qual a primeira posição vazia até posição => insere o número no vetor
        	numeroDigitado = digitaInteiro();
        	for(i=0;i<numeroPosicao;i++) {
                if(vetor[i] == 0) {
                //verifica qual a primeira posição vazia até posição => insere o número
                    vetor[i] = numeroDigitado;
                    contaVetor++;
                        
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
                contaVetor++;
        	printf("Número inserido na posição %d. Reordenado\n", numeroPosicao);
        	mostraVetor(vetor);
        }
    } while(numeroPosicao!=100);
}

