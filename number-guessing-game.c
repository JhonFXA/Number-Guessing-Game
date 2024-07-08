#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    const int MIN = 1;
    const int MAX = 20;
    const int GUESS_LIMIT = 5;
    int guess;
    int guesses = 0;
    int answer;

    // Usa o tempo atual como seed
    srand(time(0));

    // Gera um número aleatório entre MIN e MAX
    answer = (rand() % MAX) + MIN;

    printf("|| JOGO DE ADIVINHAÇÂO ||\n\n");
    printf("Você tem %d chances!\n", GUESS_LIMIT);
    do
    {
        printf("Chute um número de %d a %d\n", MIN, MAX);
        scanf("%d", &guess);
        guesses++;
        system("cls");

        if(guesses == GUESS_LIMIT) break;

        if (guess == answer)
        {
            printf("Você acertou!\n\n");
        }
        else if (abs(guess - answer) <= 3)
        {
            printf("Quente!\n\n");
            printf("Tentativas restantes: %d\n", GUESS_LIMIT - guesses);
        }
        else
        {
            printf("Frio!\n\n");
            printf("Tentativas restantes: %d\n", GUESS_LIMIT - guesses);
        }
    } while (guess != answer && guesses < GUESS_LIMIT);

    if (guesses == GUESS_LIMIT)
    {
        printf("Suas chances acabaram! :(\n\n");
    }
    printf("==========================\n");
    printf("Resposta: %d\n", answer);

    return 0;
}