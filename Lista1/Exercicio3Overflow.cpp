#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{    
    int limite;
    cin >> limite;

    cin.ignore(1);

    string expressao;
    getline(cin, expressao);

    int count = expressao.length();

    string numeroLiteral1;
    string numeroLiteral2;
    char operador;

    int referencia;

    for (int i = 0; i < count; i++)
    {
        if (expressao[i] == ' ')
        {
            referencia = i + 1;
            operador = expressao[referencia];
            break;
        }

        numeroLiteral1 += expressao[i];
    }

    for (int i = referencia + 2; i < count; i++)
    {
        numeroLiteral2 += expressao[i];
    }

    int numero1;
    int numero2;

    istringstream ( numeroLiteral1 ) >> numero1;
    istringstream ( numeroLiteral2 ) >> numero2;

    int resultado;

    if (operador == '+')
    {
        resultado = numero1 + numero2;
    }
    else
    {
        resultado = numero1 * numero2;
    }

    if (resultado <= limite)
    {
        cout << "no overflow";
    }
    else
    {
        cout << "overflow";
    }

}