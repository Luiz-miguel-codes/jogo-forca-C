#include <iostream>
#include <string>
#include <locale.h>
#include <cctype>

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    string palavra;
    string descoberta;
    string historico;

    int dificuldade;
    int maxTentativas;
    int tentativas;
    int vidas;
    int pontos;
    int tamanho;

    char letra;
    char opcaoDica;
    char jogarNovamente = 's';

    bool acertou;
    bool repetida;

    while (jogarNovamente == 's' || jogarNovamente == 'S')
    {
        tentativas = 0;
        pontos = 20;
        historico = "";

        cout << "\n=================================\n";
        cout << "          JOGO DA FORCA\n";
        cout << "=================================\n";

        cout << "\nEscolha a dificuldade:\n";
        cout << "1 - Facil\n";
        cout << "2 - Medio\n";
        cout << "3 - Dificil\n";
        cout << "Digite sua escolha: ";
        cin >> dificuldade;

        // Escolha da palavra
        if (dificuldade == 1)
        {
            palavra = "COMPUTADOR";
            maxTentativas = 8;
        }
        else if (dificuldade == 2)
        {
            palavra = "PROGRAMACAO";
            maxTentativas = 6;
        }
        else if (dificuldade == 3)
        {
            palavra = "PROCESSADOR";
            maxTentativas = 4;
        }
        else
        {
            cout << "\nOpcao invalida! Jogo encerrado.\n";
            return 0;
        }

        tamanho = palavra.length();
        vidas = maxTentativas;

        // Cria a palavra escondida
        descoberta = "";

        for (int i = 0; i < tamanho; i++)
        {
            descoberta += "_";
        }

        cout << "\nA palavra possui "
             << tamanho
             << " letras.\n";

        // Loop principal
        while (tentativas < maxTentativas && descoberta != palavra)
        {
            cout << "\n---------------------------------\n";
            cout << "Palavra: " << descoberta << endl;
            cout << "Tentativas: " << tentativas
                 << "/" << maxTentativas << endl;
            cout << "Vidas: " << vidas << endl;
            cout << "Pontos: " << pontos << endl;

            cout << "Palpites realizados: ";

            if (historico.empty())
            {
                cout << "Nenhum";
            }
            else
            {
                cout << historico;
            }

            cout << endl;

            // Dica
            cout << "\nDeseja usar uma dica? (s/n): ";
            cin >> opcaoDica;

            if (opcaoDica == 's' || opcaoDica == 'S')
            {
                if (pontos >= 10)
                {
                    bool encontrou = false;

                    for (int i = 0; i < tamanho; i++)
                    {
                        if (descoberta[i] == '_')
                        {
                            descoberta[i] = palavra[i];
                            pontos -= 10;

                            cout << "\nDICA: a letra '"
                                 << palavra[i]
                                 << "' foi revelada!\n";

                            cout << "Voce gastou 10 pontos.\n";

                            encontrou = true;
                            break;
                        }
                    }

                    if (!encontrou)
                    {
                        cout << "\nTodas as letras ja foram reveladas!\n";
                    }
                }
                else
                {
                    cout << "\nVoce nao possui pontos suficientes!\n";
                    cout << "E necessario ter pelo menos 10 pontos.\n";
                }
            }

            // Verifica se a dica revelou a palavra inteira
            if (descoberta == palavra)
            {
                break;
            }

            // Entrada da letra
            cout << "\nDigite uma letra: ";
            cin >> letra;

            letra = toupper(letra);

            // Verifica se a letra ja foi utilizada
            repetida = false;

            for (int i = 0; i < historico.length(); i++)
            {
                if (historico[i] == letra)
                {
                    repetida = true;
                    break;
                }
            }

            if (repetida)
            {
                cout << "Voce ja tentou essa letra!\n";
                continue;
            }

            // Adiciona ao historico
            historico += letra;
            historico += " ";

            // Verifica se acertou
            acertou = false;

            for (int i = 0; i < tamanho; i++)
            {
                if (letra == palavra[i])
                {
                    descoberta[i] = letra;
                    acertou = true;
                }
            }

            // Resultado da tentativa
            if (acertou)
            {
                cout << "Voce acertou!\n";

                if (dificuldade == 1)
                {
                    pontos += 10;
                }
                else if (dificuldade == 2)
                {
                    pontos += 20;
                }
                else
                {
                    pontos += 30;
                }
            }
            else
            {
                cout << "Voce errou!\n";

                tentativas++;
                vidas--;

                if (pontos >= 5)
                {
                    pontos -= 5;
                }
            }
        }

        // Resultado final
        cout << "\n=================================\n";

        if (descoberta == palavra)
        {
            cout << "          PARABENS!\n";
            cout << "        VOCE VENCEU!\n";

            cout << "\nPalavra: " << palavra << endl;
            cout << "Tentativas utilizadas: "
                 << tentativas << endl;
            cout << "Vidas restantes: "
                 << vidas << endl;
            cout << "Pontuacao: "
                 << pontos << endl;
        }
        else
        {
            cout << "         VOCE PERDEU!\n";

            cout << "\nA palavra era: "
                 << palavra << endl;
            cout << "Tentativas utilizadas: "
                 << tentativas << endl;
            cout << "Pontuacao: "
                 << pontos << endl;
        }

        cout << "\nDeseja jogar novamente? (s/n): ";
        cin >> jogarNovamente;
    }

    cout << "\n=================================\n";
    cout << "          FIM DE JOGO!\n";
    cout << "=================================\n";
    cout << "Obrigado por jogar!\n";

    return 0;
}
