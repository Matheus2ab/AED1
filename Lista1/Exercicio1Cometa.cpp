#include <iostream>

using namespace std;

const int anoReferencia = 1986;
const int tempoDePassagem = 76;

bool AnoEscolhidoEhMaiorAnoReferencia(int anoEscolhido)
{
    return anoEscolhido > anoReferencia;
}

int ObtenhaDiferencaAnos(int anoEscolhido)
{
    return AnoEscolhidoEhMaiorAnoReferencia(anoEscolhido)
               ? anoEscolhido - anoReferencia
               : anoReferencia - anoEscolhido;
}

bool EhAnoDePassagem(int anoEscolhido)
{
    int diferencaAnos = ObtenhaDiferencaAnos(anoEscolhido);

    int divisao = diferencaAnos / tempoDePassagem;

    return divisao * tempoDePassagem == diferencaAnos;
}

int main()
{
    int anoEscolhido;

    cin >> anoEscolhido;

    if (EhAnoDePassagem(anoEscolhido))
    {
        cout << anoEscolhido + tempoDePassagem << endl;
        return 0;
    }

    int anoProximo1 = anoReferencia;
    int anoProximo2;

    bool ehAnoDePassagemMaisProximo = false;

    while (!ehAnoDePassagemMaisProximo)
    {
        anoProximo2 = AnoEscolhidoEhMaiorAnoReferencia(anoEscolhido) ? anoProximo1 + tempoDePassagem : anoProximo1 - tempoDePassagem;

        if ((anoProximo1 > anoEscolhido ? anoProximo1 - anoEscolhido : anoEscolhido - anoProximo1) 
            > (anoProximo2 > anoEscolhido ? anoProximo2 - anoEscolhido : anoEscolhido - anoProximo2))
        {
            anoProximo1 = anoProximo2;
        }
        else
        {
            break;
        }
    }

    if (AnoEscolhidoEhMaiorAnoReferencia(anoEscolhido))
    {
        cout << anoProximo1 + 76;
        return 0;
    }

    cout << anoProximo1;
}
