#include <stdio.h>
#include <string.h> // Para strcpy e strcspn

int main() {
    // ---- Variáveis para a CARTA 1 ----
    char estado1[50];                 // Uma letra de 'A' a 'H' (representando um dos oito estados).
    char codigoDoEstado1[50];         // A letra do estado seguida de um número de 01 a 04 (ex: A01, B03).
    char nomeDaCidade1[50];           // O nome da cidade.
    int populacao1;                   // O número de habitantes da cidade.
    float areaEmKm1;                  // A área da cidade em quilômetros quadrados.
    float PIB1;                       // O Produto Interno Bruto da cidade.
    int numeroPontosTuristicos1;      // A quantidade de pontos turísticos na cidade.
    float densidadePopulacional1;     // Densidade populacional calculada (populacao1 / areaEmKm1).
    float PIBperCapita1;              // PIB per capita calculado (PIB1 / populacao1).

    // ---- Variáveis para a CARTA 2 ----
    char estado2[50];                 // Uma letra de 'A' a 'H' (representando um dos oito estados).
    char codigoDoEstado2[50];         // A letra do estado seguida de um número de 01 a 04 (ex: A01, B03).
    char nomeDaCidade2[50];           // O nome da cidade.
    int populacao2;                   // O número de habitantes da cidade.
    float areaEmKm2;                  // A área da cidade em quilômetros quadrados.
    float PIB2;                       // O Produto Interno Bruto da cidade.
    int numeroPontosTuristicos2;      // A quantidade de pontos turísticos na cidade.
    float densidadePopulacional2;     // Densidade populacional calculada (populacao2 / areaEmKm2).
    float PIBperCapita2;              // PIB per capita calculado (PIB2 / populacao2).

    int c; // Variável auxiliar para limpar o buffer de entrada

    // ---- CARTA 1 ----
    printf("---- CARTA 1 ----\n");
    printf("Digite uma letra de 'A' a 'H' para representar o estado: \n");
    scanf(" %c", &estado1[0]);        // Lê um caractere para o estado1. O espaço antes de %c consome newlines pendentes.
    estado1[1] = '\0';                // Garante que estado1 seja uma string terminada em nulo.

    printf("Digite a letra escolhida seguida de um numero de 01 a 04 (ex: A01, B03): \n");
    scanf("%s", codigoDoEstado1);     // Lê o código do estado1.

    // Limpa o buffer de entrada APÓS scanf %s e ANTES de fgets
    // scanf %s deixa um '\n' no buffer que seria lido pelo fgets.
    while ((c = getchar()) != '\n' && c != EOF); 

    printf("Digite o nome da cidade: \n");
    fgets(nomeDaCidade1, sizeof(nomeDaCidade1), stdin); // Lê o nome da cidade1, incluindo espaços.
    nomeDaCidade1[strcspn(nomeDaCidade1, "\n")] = 0;   // Remove o caractere de nova linha ('\n') do final da string, se presente.

    printf("Digite o número de habitantes da cidade: \n");
    scanf("%i", &populacao1);         // Lê o número de habitantes da cidade1.

    printf("Digite a área da cidade em quilometros quadrados: \n");
    scanf("%f", &areaEmKm1);          // Lê a área da cidade1.

    printf("Digite o número do PIB da cidade: \n");
    scanf("%f", &PIB1);               // Lê o PIB da cidade1.

    printf("Digite a quantidade em números de pontos turisticos na cidade: \n");
    scanf("%i", &numeroPontosTuristicos1); // Lê a quantidade de pontos turísticos da cidade1.

    // Cálculo da densidade populacional e o PIB per capita da Carta 1
    if (areaEmKm1 > 0) { // Evita divisão por zero para densidade
        densidadePopulacional1 = (float)populacao1 / areaEmKm1; // Calcula a densidade populacional (habitantes por km²).
    } else {
        densidadePopulacional1 = 0; // Define como 0 se a área for inválida.
    }
    if (populacao1 > 0) { // Evita divisão por zero para PIB per capita
        PIBperCapita1 = (float)PIB1 / populacao1;             // Calcula o PIB per capita (PIB por habitante).
    } else {
        PIBperCapita1 = 0; // Define como 0 se a população for inválida.
    }

    // ---- CARTA 2 ----
    printf("\n---- CARTA 2 ----\n");
    printf("Digite uma letra de 'A' a 'H' para representar o estado: \n");
    scanf(" %c", &estado2[0]);        // Lê um caractere para o estado2.
    estado2[1] = '\0';                // Garante que estado2 seja uma string terminada em nulo.

    printf("Digite a letra escolhida seguida de um numero de 01 a 04 (ex: A01, B03): \n");
    scanf("%s", codigoDoEstado2);     // Lê o código do estado2.

    // Limpa o buffer de entrada APÓS scanf %s e ANTES de fgets
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Digite o nome da cidade: \n");
    fgets(nomeDaCidade2, sizeof(nomeDaCidade2), stdin); // Lê o nome da cidade2, incluindo espaços.
    nomeDaCidade2[strcspn(nomeDaCidade2, "\n")] = 0;   // Remove o caractere de nova linha ('\n').

    printf("Digite o número de habitantes da cidade: \n");
    scanf("%i", &populacao2);         // Lê o número de habitantes da cidade2.

    printf("Digite a área da cidade em quilometros quadrados: \n");
    scanf("%f", &areaEmKm2);          // Lê a área da cidade2.

    printf("Digite o número do PIB da cidade: \n");
    scanf("%f", &PIB2);               // Lê o PIB da cidade2.

    printf("Digite a quantidade em números de pontos turisticos na cidade: \n");
    scanf("%i", &numeroPontosTuristicos2); // Lê a quantidade de pontos turísticos da cidade2.

    // Cálculo da densidade populacional e o PIB per capita da Carta 2
    if (areaEmKm2 > 0) { // Evita divisão por zero
        densidadePopulacional2 = (float)populacao2 / areaEmKm2; // Calcula a densidade populacional.
    } else {
        densidadePopulacional2 = 0;
    }
    if (populacao2 > 0) { // Evita divisão por zero
        PIBperCapita2 = (float)PIB2 / populacao2;             // Calcula o PIB per capita.
    } else {
        PIBperCapita2 = 0;
    }

    // ---- Exibição dos Dados das Cartas Cadastradas ----
    printf("\n---- Dados das Cartas Cadastradas ----\n");

    printf("\nCarta 1:\n");
    printf("Estado: %s\n", estado1);
    printf("Código: %s\n", codigoDoEstado1);
    printf("Nome da cidade: %s\n", nomeDaCidade1);
    printf("População: %i\n", populacao1);
    printf("Área: %.3f km²\n", areaEmKm1);                 // Exibe com 3 casas decimais e unidade.
    printf("PIB: %.2f\n", PIB1);                           // Exibe com 2 casas decimais.
    printf("Pontos turísticos: %i\n", numeroPontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional1); // Exibe com 2 casas decimais e unidade.
    printf("PIB per Capita: %.2f\n", PIBperCapita1);       // Exibe com 2 casas decimais.

    printf("\nCarta 2:\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s\n", codigoDoEstado2);
    printf("Nome da cidade: %s\n", nomeDaCidade2);
    printf("População: %i\n", populacao2);
    printf("Área: %.3f km²\n", areaEmKm2);                 // Exibe com 3 casas decimais e unidade.
    printf("PIB: %.2f\n", PIB2);                           // Exibe com 2 casas decimais.
    printf("Pontos turísticos: %i\n", numeroPontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2); // Exibe com 2 casas decimais e unidade.
    printf("PIB per Capita: %.2f\n", PIBperCapita2);       // Exibe com 2 casas decimais.

    // ---- Comparação das Cartas ----
    printf("\n---- Comparação das Cartas ----\n");

    // ESCOLHA O ATRIBUTO PARA COMPARAÇÃO AQUI (MUDE O NÚMERO):
    // 1: População (Maior vence)
    // 2: Área (Maior vence)
    // 3: PIB (Maior vence)
    // 4: Densidade Populacional (MENOR vence)
    // 5: PIB per Capita (Maior vence)
    // 6: Número de Pontos Turísticos (Maior vence)
    const int ATRIBUTO_ESCOLHIDO = 1; // Exemplo: Comparar por População. Mude este valor para testar outros atributos.

    char nomeAtributoComparado[50]; // Para armazenar o nome do atributo que está sendo comparado.

    switch (ATRIBUTO_ESCOLHIDO) {
        case 1: // Comparação por População
            strcpy(nomeAtributoComparado, "População");
            printf("Comparando por: %s\n", nomeAtributoComparado);
            printf("Carta 1 - %s (%s): %d habitantes\n", nomeDaCidade1, estado1, populacao1);
            printf("Carta 2 - %s (%s): %d habitantes\n", nomeDaCidade2, estado2, populacao2);

            if (populacao1 > populacao2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nomeDaCidade1);
            } else if (populacao2 > populacao1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nomeDaCidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2: // Comparação por Área
            strcpy(nomeAtributoComparado, "Área");
            printf("Comparando por: %s\n", nomeAtributoComparado);
            printf("Carta 1 - %s (%s): %.3f km²\n", nomeDaCidade1, estado1, areaEmKm1);
            printf("Carta 2 - %s (%s): %.3f km²\n", nomeDaCidade2, estado2, areaEmKm2);

            if (areaEmKm1 > areaEmKm2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nomeDaCidade1);
            } else if (areaEmKm2 > areaEmKm1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nomeDaCidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3: // Comparação por PIB
            strcpy(nomeAtributoComparado, "PIB");
            printf("Comparando por: %s\n", nomeAtributoComparado);
            printf("Carta 1 - %s (%s): %.2f\n", nomeDaCidade1, estado1, PIB1);
            printf("Carta 2 - %s (%s): %.2f\n", nomeDaCidade2, estado2, PIB2);

            if (PIB1 > PIB2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nomeDaCidade1);
            } else if (PIB2 > PIB1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nomeDaCidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4: // Comparação por Densidade Populacional (MENOR vence)
            strcpy(nomeAtributoComparado, "Densidade Populacional");
            printf("Comparando por: %s\n", nomeAtributoComparado);
            printf("Carta 1 - %s (%s): %.2f hab/km²\n", nomeDaCidade1, estado1, densidadePopulacional1);
            printf("Carta 2 - %s (%s): %.2f hab/km²\n", nomeDaCidade2, estado2, densidadePopulacional2);

            if (densidadePopulacional1 < densidadePopulacional2) { // MENOR valor vence
                printf("Resultado: Carta 1 (%s) venceu!\n", nomeDaCidade1);
            } else if (densidadePopulacional2 < densidadePopulacional1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nomeDaCidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5: // Comparação por PIB per Capita
            strcpy(nomeAtributoComparado, "PIB per Capita");
            printf("Comparando por: %s\n", nomeAtributoComparado);
            printf("Carta 1 - %s (%s): %.2f\n", nomeDaCidade1, estado1, PIBperCapita1);
            printf("Carta 2 - %s (%s): %.2f\n", nomeDaCidade2, estado2, PIBperCapita2);

            if (PIBperCapita1 > PIBperCapita2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nomeDaCidade1);
            } else if (PIBperCapita2 > PIBperCapita1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nomeDaCidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 6: // Comparação por Número de Pontos Turísticos
            strcpy(nomeAtributoComparado, "Número de Pontos Turísticos");
            printf("Comparando por: %s\n", nomeAtributoComparado);
            printf("Carta 1 - %s (%s): %d\n", nomeDaCidade1, estado1, numeroPontosTuristicos1);
            printf("Carta 2 - %s (%s): %d\n", nomeDaCidade2, estado2, numeroPontosTuristicos2);

            if (numeroPontosTuristicos1 > numeroPontosTuristicos2) {
                printf("Resultado: Carta 1 (%s) venceu!\n", nomeDaCidade1);
            } else if (numeroPontosTuristicos2 > numeroPontosTuristicos1) {
                printf("Resultado: Carta 2 (%s) venceu!\n", nomeDaCidade2);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default: // Caso o ATRIBUTO_ESCOLHIDO seja inválido
            printf("Atributo de comparação inválido (%d) selecionado no código.\n", ATRIBUTO_ESCOLHIDO);
            printf("Por favor, escolha um valor entre 1 e 6.\n");
            break;
    }

    return 0; // Indica que o programa terminou com sucesso.
}