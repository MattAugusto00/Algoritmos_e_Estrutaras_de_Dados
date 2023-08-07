/*O programa recebe um número inteiro "N" do usuário e calcula e exibe
 *  o fatorial desse número. O fatorial de um número "N" é o produto de
 *  todos os números inteiros positivos de 1 até "N".
 *  Por exemplo, o fatorial de 5 é 5 * 4 * 3 * 2 * 1 = 120*/

#include <iostream>
using namespace std;

int main(){
	int N, f = 1;
	cout << "Digite um valor para calcular seu fatorial: " << endl;
	cin >> N;
	for(int i = 1; i <= N; i++){
		f *= i;
	}
	cout << "O fatorial de " << N << " eh " << f << endl;
	
	return 0;
}
