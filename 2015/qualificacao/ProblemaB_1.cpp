/**
* Vitor M. N. Fernandes, vmnf@yahoo.com, 29/03/2015
* InfoTech - Clube de Programação e Robótica
* https://www.facebook.com/clubeinfotech
* 
* ONI2015 - Qualificacao
* Problema B - Teoria de (Quase) Tudo
* Versão 1: Ingenua com O(N^4)
*/

#include <iostream>
#include <stdlib.h> //abs

using namespace std;

int main()
{
	int c; //numero de conjuntos
	int n; //numero de particulas por conjunto
	int d; //distancia de estabilidade
	//se p estatico teremos no máximo 1M x 32bit = 4MB mas so uma alocacao (...)
	int *p; //particulas por conjunto 
	//
	int particula; //a testar
	int index; //intervalo de teste
	//
	int estaveis; //resultado
	//
	cin >> c;
	for (int i = 0; i < c; i++) //c conjuntos
	{
		// Load data
		cin >> n;
		cin >> d;
		p = new int[n]; //alocar so o que é necessário e conhecido //fazer delete!
		for (int j = 0; j < n; j++)
		{
			cin >> p[j];
		}
		// Data loaded
		// Algorithm: O(N^3) from here so it will be a O(N^4)!!!
		estaveis = 0;
		if(n >= 3) //se n < 3 nao existe intervalo entre particulas!
		{
			for (int i1 = 0; i1 < n - 2; i1++) //garantir 1 particula no meio 
			{
				//so funciona quando c >= 3!
				for (int i2 = i1 + 2; i2 < n; i2++) //garantir 1 particula no meio 
				{
					cout << i2 << ".";
					if(p[i1] == p[i2]) //temos um intervalo para testar
					{
						particula = p[i1];
						index = i1 + 1;
						while( (abs(particula - p[index]) <= d) && (index < i2) )
						{
							index++;
						}
						if(index == i2) estaveis++; //se distancia sempre <= estavel!
					}
				}
			}
		}
		// 
		delete p; //libertar a memoria para o proximo conjunto
		cout << estaveis << endl;
	}
	return 0;
}
