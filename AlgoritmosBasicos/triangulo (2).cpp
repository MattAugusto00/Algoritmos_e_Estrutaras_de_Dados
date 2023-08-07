#include <iostream>
using namespace std;

int main()
{
	int x;
	int y;
	int z;
	cout << "Digite o valor de x:" << endl;
	cin >> x;
	cout << "Digite o valor de y:" << endl;
	cin >> y;
	cout << "Digite o valor de z:" << endl;
	cin >> z;
	
	if((x!=y)and(x!=z)and(y!=z)){
		cout << "O triangulo eh escaleno";
	}else if((x==y)and(x==z)and(y==z)){
		cout << "O triangulo eh equilatero";
	}else if((x==y)and(x!=z)){
		cout << "O triangulo eh isoceles";
	}else if((x==z)and(x!=y)){
		cout << "O triangulo eh isoceles";
	}else if((y==z)and(y!=x)){
		cout << "O triangulo eh isoceles";
	}
	
return 0;
}
