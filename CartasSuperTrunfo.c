#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

// Decalaração das funções para calcular a densidade populacional e PIB per capita
// Definindo a estrutura "Carta"
typedef struct {
    char estado;
    char codigo[3];
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
} Carta;
float calcularDensidadePopulacional(int populacao, float area);
float calcularPIBPerCapita(float pib, int populacao);
float calcularSuperPoder(int populacao, float area, float pib, int pontos_turisticos, float densidade_populacional, float pib_per_capita);
void inicializarCarta(Carta *carta);
void exibirCarta(const Carta *carta);
void compararCartas(const Carta *carta1, const Carta *carta2);
void compararCartasPorAtributo(const Carta *carta1, const Carta *carta2, int atributo);

int main() {
    
    // Criação das instancias das cartas
    Carta carta1, carta2;

    // Atribuição dos valores das cartas
    printf("Cadastro da carta 1\n");
    inicializarCarta(&carta1);

    // Exibição da carta 1
    exibirCarta(&carta1);

    printf("Cadastro da carta 2\n");
    inicializarCarta(&carta2);

    // Exibição da carta 2
    exibirCarta(&carta2);

    // Comparação das cartas
    //compararCartas(&carta1, &carta2);

    // Comparação das cartas por atributo
    int atributo = 1;
    compararCartasPorAtributo(&carta1, &carta2, atributo);


    return 0;
}

//Funções para calcular a densidade populacional e PIB per capita

float calcularDensidadePopulacional(int populacao, float area) {
    return populacao / area;
}

float calcularPIBPerCapita(float pib, int populacao) {
    return pib / populacao;
}

//Função para calcular o super poder da cidade (Soma de todos os atributos)
float calcularSuperPoder(int populacao, float area, float pib, int pontos_turisticos, float densidade_populacional, float pib_per_capita) {
    return populacao + area + pib + pontos_turisticos + densidade_populacional + pib_per_capita;
}

// Função para inicializar uma carta
void inicializarCarta(Carta *carta) {
    // Exemplos de atributos: código da cidade, nome, população, área, PIB, número de pontos turísticos.
    char estado;
    char codigo[3];
    char nome_cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
    float super_poder;
    printf("Digite o código do estado: ");
    scanf(" %c", &estado);
    getchar(); // Limpa o buffer do teclado

    printf("Digite o código da cidade: ");
    scanf("%s", codigo);
    getchar();

    printf("Digite o nome da cidade: ");
    fgets(nome_cidade, sizeof(nome_cidade), stdin); //Tive ajuda do copilot para usar o fgets
    // Remove a nova linha (\n) que o fgets inclui no final
    nome_cidade[strcspn(nome_cidade, "\n")] = '\0';

    printf("Digite a população da cidade: ");
    scanf("%d", &populacao);

    printf("Digite a área da cidade: ");
    scanf("%f", &area);

    printf("Digite o PIB da cidade: ");
    scanf("%f", &pib);

    printf("Digite o número de pontos turísticos da cidade: ");
    scanf("%d", &pontos_turisticos);

    //Adição da densidade populacional, PIB per capita e super poder
    densidade_populacional = calcularDensidadePopulacional(populacao, area);
    pib_per_capita = calcularPIBPerCapita(pib, populacao);
    // Calculando o super poder
    super_poder = calcularSuperPoder(populacao, area, pib, pontos_turisticos, densidade_populacional, pib_per_capita);
    carta->estado = estado;
    strncpy(carta->codigo, codigo, 3);
    strncpy(carta->nome_cidade, nome_cidade, 50);
    carta->populacao = populacao;
    carta->area = area;
    carta->pib = pib;
    carta->pontos_turisticos = pontos_turisticos;
    carta->super_poder = super_poder;

    // Calculando valores derivados
    carta->densidade_populacional = (float)carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}

// Função para exibir uma carta
void exibirCarta(const Carta *carta) {
    printf("Estado: %c\n", carta->estado);
    printf("Código: %s\n", carta->codigo);
    printf("Nome da Cidade: %s\n", carta->nome_cidade);
    printf("População: %d\n", carta->populacao);
    printf("Área: %.2f\n", carta->area);
    printf("PIB: %.2f\n", carta->pib);
    printf("Pontos Turísticos: %d\n", carta->pontos_turisticos);
    printf("Densidade Populacional: %.2f\n", carta->densidade_populacional);
    printf("PIB per Capita: %.2f\n", carta->pib_per_capita);
    printf("Super Poder: %.2f\n", carta->super_poder);
    printf("\n");
}

// Função para comparar as cartas em cada atributo
void compararCartas(const Carta *carta1, const Carta *carta2) {
    printf("Comparação das Cartas:\n");

    printf("População: %d\n", carta1->populacao > carta2->populacao);
    printf("Área: %d\n", carta1->area > carta2->area);
    printf("PIB: %d\n", carta1->pib > carta2->pib);
    printf("Pontos Turísticos: %d\n", carta1->pontos_turisticos > carta2->pontos_turisticos);
    printf("Densidade Populacional: %d\n", carta1->densidade_populacional < carta2->densidade_populacional);
    printf("PIB per Capita: %d\n", carta1->pib_per_capita > carta2->pib_per_capita);
    printf("Super Poder: %d\n", carta1->super_poder > carta2->super_poder);
}

void compararCartasPorAtributo(const Carta *carta1, const Carta *carta2, int atributo) {
    if (atributo == 1) {
        printf("Comparação das Cartas por População:\n");
        if(carta1->populacao > carta2->populacao) {
            printf("A carta 1 venceu!\n");
        } else if (carta1->populacao < carta2->populacao) {
            printf("A carta 2 venceu!\n");
        } else {
            printf("Empate!\n");
        }
    }
    if (atributo == 2) {
        printf("Comparação das Cartas por Área:\n");
        if(carta1->area > carta2->area) {
            printf("A carta 1 venceu!\n");
        } else if (carta1->area < carta2->area) {
            printf("A carta 2 venceu!\n");
        } else {
            printf("Empate!\n");
        }
    }
    if (atributo == 3) {
        printf("Comparação das Cartas por PIB:\n");
        if(carta1->pib > carta2->pib) {
            printf("A carta 1 venceu!\n");
        } else if (carta1->pib < carta2->pib) {
            printf("A carta 2 venceu!\n");
        } else {
            printf("Empate!\n");
        }
    }
    if (atributo == 4) {
        printf("Comparação das Cartas por Pontos Turísticos:\n");
        if(carta1->pontos_turisticos > carta2->pontos_turisticos) {
            printf("A carta 1 venceu!\n");
        } else if (carta1->pontos_turisticos < carta2->pontos_turisticos) {
            printf("A carta 2 venceu!\n");
        } else {
            printf("Empate!\n");
        }
    }
    if (atributo == 5) {
        printf("Comparação das Cartas por Densidade Populacional:\n");
        if(carta1->densidade_populacional < carta2->densidade_populacional) {
            printf("A carta 1 venceu!\n");
        } else if (carta1->densidade_populacional < carta2->densidade_populacional) {
            printf("A carta 2 venceu!\n");
        } else {
            printf("Empate!\n");
        }
    }
    if (atributo == 6) {
        printf("Comparação das Cartas por PIB per Capita:\n");
        if(carta1->pib_per_capita > carta2->pib_per_capita) {
            printf("A carta 1 venceu!\n");
        } else if (carta1->pib_per_capita < carta2->pib_per_capita) {
            printf("A carta 2 venceu!\n");
        } else {
            printf("Empate!\n");
        }
    }
    if (atributo == 7) {
        printf("Comparação das Cartas por Super Poder:\n");
        if(carta1->super_poder > carta2->super_poder) {
            printf("A carta 1 venceu!\n");
        } else if (carta1->super_poder < carta2->super_poder) {
            printf("A carta 2 venceu!\n");
        } else {
            printf("Empate!\n");
        }
    }
    
}
