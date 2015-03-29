/**
* Vitor M. N. Fernandes, vmnf@yahoo.com, 29/03/2015
* InfoTech - Clube de Programação e Robótica
* https://www.facebook.com/clubeinfotech
* 
* ONI2015 - Qualificacao
* Problema C - Numeros do Fogo
* Versão 1: Ingenua com O(N^3)
*/

#include <iostream>

using namespace std;

int main()
{
	int n; //numero de intervalos
	int start; //numero inicial
	int end; //numero final
	//
	int nfogo;
	bool up, down;
	int parse;
	int d1, d2;
	//
	cin >> n;
	for (int i = 0; i < n; i++) //n intervalos
	{
		// Load data
		cin >> start;
		cin >> end;
		// Data loaded
		// Algorithm: O(N^2) from here so it will be a O(N^3)!!!
		nfogo = 0;
		//numeros inferiores a 100 so com dois digitos nao sao de fogo!
		if(start < 100) start = 100;
		if (end >= start) //se end nao for maior ou igual ao start terminar
		{
			for (int j = start; j <= end; j++)
			{
				//um numero de fogo necessita de digitos a subir e descer!
				up = false;
				down = false;
				parse = j; //digitos (d1, d2) extraidos do int parse
				//verificar da direita para esquerda ou vice-versa é igual!
				d1 = parse % 10;
				while ( (!(up && down)) && (parse > 9) )
				{
					parse /= 10; //so funciona para parse > 9!
					d2 = parse % 10;
					if(d2 > d1)
					{
						up = true;
					}
					else if(d2 < d1)
					{
						down = true;
					}
					d1 = d2;
				}
				if(up && down) nfogo++;
			}
		}
		cout << nfogo << endl;
	}
	return 0;
}
