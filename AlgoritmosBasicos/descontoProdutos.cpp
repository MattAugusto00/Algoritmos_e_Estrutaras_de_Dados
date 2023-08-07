#include <iostream>
using namespace std;

int main()
{
    float c, q;

    // Solicitar ao usuário que digite o valor do produto (c)
    cout << "Digite o valor do produto: ";
    cin >> c;

    // Solicitar ao usuário que digite a quantidade comprada (q)
    cout << "Digite a quantidade comprada: ";
    cin >> q;

    if (c >= 1 && c <= 10 && (c * q) < 250)
    {
        cout << "Desconto de 5% aplicado!" << endl;
        cout << "Valor original: " << c * q << endl;
        cout << "Valor com desconto: " << (c * q) - (c * q * 0.05) << endl;
    }
    else if (c >= 1 && c <= 10 && ((c * q) >= 250 && (c * q) <= 500))
    {
        cout << "Desconto de 10% aplicado!" << endl;
        cout << "Valor original: " << c * q << endl;
        cout << "Valor com desconto: " << (c * q) - (c * q * 0.10) << endl;
    }
    else if (c >= 1 && c <= 10 && (c * q) > 500)
    {
        cout << "Desconto de 15% aplicado!" << endl;
        cout << "Valor original: " << c * q << endl;
        cout << "Valor com desconto: " << (c * q) - (c * q * 0.15) << endl;
    }
    else if (c >= 11 && c <= 20 && (c * q) < 250)
    {
        cout << "Desconto de 5% aplicado!" << endl;
        cout << "Valor original: " << c * q << endl;
        cout << "Valor com desconto: " << (c * q) - (c * q * 0.05) << endl;
    }
    else if (c >= 11 && c <= 20 && ((c * q) >= 250 && (c * q) <= 500))
    {
        cout << "Desconto de 10% aplicado!" << endl;
        cout << "Valor original: " << c * q << endl;
        cout << "Valor com desconto: " << (c * q) - (c * q * 0.10) << endl;
    }
    else if (c >= 11 && c <= 20 && (c * q) > 500)
    {
        cout << "Desconto de 15% aplicado!" << endl;
        cout << "Valor original: " << c * q << endl;
        cout << "Valor com desconto: " << (c * q) - (c * q * 0.15) << endl;
    }
    else if (c >= 21 && c <= 30 && (c * q) < 250)
    {
        cout << "Desconto de 5% aplicado!" << endl;
        cout << "Valor original: " << c * q << endl;
        cout << "Valor com desconto: " << (c * q) - (c * q * 0.05) << endl;
    }
    else if (c >= 21 && c <= 30 && ((c * q) >= 250 && (c * q) <= 500))
    {
        cout << "Desconto de 10% aplicado!" << endl;
        cout << "Valor original: " << c * q << endl;
        cout << "Valor com desconto: " << (c * q) - (c * q * 0.10) << endl;
    }
    else if (c >= 21 && c <= 30 && (c * q) > 500)
    {
        cout << "Desconto de 15% aplicado!" << endl;
        cout << "Valor original: " << c * q << endl;
        cout << "Valor com desconto: " << (c * q) - (c * q * 0.15) << endl;
    }
    else if (c >= 31 && c <= 40 && (c * q) < 250)
    {
        cout << "Desconto de 5% aplicado!" << endl;
        cout << "Valor original: " << c * q << endl;
        cout << "Valor com desconto: " << (c * q) - (c * q * 0.05) << endl;
    }
    else if (c >= 31 && c <= 40 && ((c * q) >= 250 && (c * q) <= 500))
    {
        cout << "Desconto de 10% aplicado!" << endl;
        cout << "Valor original: " << c * q << endl;
        cout << "Valor com desconto: " << (c * q) - (c * q * 0.10) << endl;
    }
    else if (c >= 31 && c <= 40 && (c * q) > 500)
    {
        cout << "Desconto de 15% aplicado!" << endl;
        cout << "Valor original: " << c * q << endl;
        cout << "Valor com desconto: " << (c * q) - (c * q * 0.15) << endl;
    }
    else
    {
        cout << "Erro: valores inválidos inseridos." << endl;
    }

    return 0;
}
