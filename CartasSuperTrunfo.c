#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

// Decalaração das funções para calcular a densidade populacional e PIB per capita
float calcularDensidadePopulacional(int populacao, float area);
float calcularPIBPerCapita(float pib, int populacao);

int main() {
    // Sugestão: Defina variáveis separadas para cada atributo da cidade.
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
    
    // Cadastro das Cartas:
    // Sugestão: Utilize a função scanf para capturar as entradas do usuário para cada atributo.
    // Solicite ao usuário que insira as informações de cada cidade, como o código, nome, população, área, etc.
    // Armazene cada atributo em uma variável separada.

    printf("Cadastro de Cartas de Cidades\n");
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

    //Adição da densidade populacional e PIB per capita
    densidade_populacional = calcularDensidadePopulacional(populacao, area);
    pib_per_capita = calcularPIBPerCapita(pib, populacao);
    
    // Exibição dos Dados das Cartas:
    // Sugestão: Utilize a função printf para exibir as informações das cartas cadastradas de forma clara e organizada.
    // Exiba os valores inseridos para cada atributo da cidade, um por linha.
    // Utilize frases para indicar o significado de cada valor, como "População: 1000000".

    printf("\nCarta de Cidade\n");
    printf("Código do Estado: %c\n", estado);
    printf("Código da Cidade: %s\n", codigo);
    printf("Nome da Cidade: %s\n", nome_cidade);
    printf("População: %d\n", populacao);
    printf("Área: %.2f km²\n", area);
    printf("Densidade Populacional: %.2f pessoas/km²\n", densidade_populacional);
    printf("PIB: %.2f bilhões de reais\n", pib);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita);
    printf("Pontos Turísticos: %d\n", pontos_turisticos);

    return 0;
}

//Funções para calcular a densidade populacional e PIB per capita

float calcularDensidadePopulacional(int populacao, float area) {
    return populacao / area;
}

float calcularPIBPerCapita(float pib, int populacao) {
    return pib / populacao;
}
