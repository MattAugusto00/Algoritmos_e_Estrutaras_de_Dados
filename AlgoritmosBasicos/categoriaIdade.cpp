#include <iostream>
using namespace std;

int main()
{
	int idade;

	// Solicitar ao usuário que digite sua idade
	cout << "Digite sua idade: ";
	cin >> idade;
    
	if (idade < 5){
		cout << "Idade: " << idade << " anos." << endl;
		cout << "Categoria: Não registrado." << endl;
	}else{
		if (idade >= 5 && idade <= 7){
			cout << "Idade: " << idade << " anos." << endl;
			cout << "Categoria: Infantil." << endl;
		}else if (idade >= 8 && idade <= 10){
			cout << "Idade: " << idade << " anos." << endl;
			cout << "Categoria: Juvenil." << endl;
		}else if (idade >= 11 && idade <= 15){
			cout << "Idade: " << idade << " anos." << endl;
			cout << "Categoria: Adolescente." << endl;
		}else if (idade >= 16 && idade <= 30){
			cout << "Idade: " << idade << " anos." << endl;
			cout << "Categoria: Adulto." << endl;
		}else if (idade > 30){
			cout << "Idade: " << idade << " anos." << endl;
			cout << "Categoria: Sênior." << endl;
		}
	}
	
	return 0;
}
