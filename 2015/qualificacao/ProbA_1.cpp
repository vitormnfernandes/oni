/**
* Vitor M. N. Fernandes, vmnf@yahoo.com, 29/03/2015
* InfoTech - Clube de Programacao e Robotica
* https://www.facebook.com/clubeinfotech
* 
* ONI2015 - Qualificacao
* Problema A - Confusão Classificativa
* Versao 1: Ordenacao com O(NlogN), usando o quicksort
*/

#include <iostream>
#include <string.h>

using namespace std;

//usando uma estrutura simplificamos o processo de troca num unico array
struct item {
	int soma;
	string nome;
};

//quicksort adapted from
//http://en.wikipedia.org/wiki/Quicksort
int partition(struct item A[], int lo, int hi)
{
	int pivotIndex = lo; //como melhorar?
	int pivotValue = A[pivotIndex].soma;
	string pivotValue2 = A[pivotIndex].nome;
	//put the chosen pivot at A[hi] //pivot fica em hi!
	swap(A[pivotIndex], A[hi]);
	int storeIndex = lo;
	// compare remaining array elements against pivotValue = A[hi]
	for(int i = lo; i < hi; i++)
	{
		if(A[i].soma > pivotValue) //ordem decrescente
		{
			swap(A[i], A[storeIndex]);
			storeIndex++;
		}
		//segunda ordenacao em caso de empate...
		else if(A[i].soma == pivotValue) // empates temos de ordenar por nome!
		{
			if(A[i].nome.compare(pivotValue2) < 0 ) //ordem crescente
			{
				swap(A[i], A[storeIndex]);
				storeIndex++;
			}
		}
	}
	swap(A[storeIndex], A[hi]);
	return storeIndex;
}

void quicksort(struct item A[], int lo, int hi)
{
	int p;
	if(lo < hi)
	{
		p = partition(A, lo, hi);
		quicksort(A, lo, p - 1);
		quicksort(A, p + 1, hi);
	}
}

int main()
{
	int n; //numero de concorrentes
	int nprob; //numero de problemas
	//
	item* items;
	//
	int total, aux;
	int lo, hi;
	//
	cin >> n;
	cin >> nprob;
	items = new item[n];
	// Load data
	for (int i = 0; i < n; i++)
	{
		cin >> items[i].nome;
		total = 0;
		for (int j = 0; j < nprob; j++)
		{
			cin >> aux;
			total += aux;
		}
		items[i].soma = total;
	}
	// Data loaded
	// Algorithm: O(NlogN) ordenacao com um quicksort modificado
	//
	lo = 0;
	hi = n - 1; //n concorrentes
	quicksort(items, lo, hi);
	//
	for (int i = 0; i < n; i++) // quicksort (total: decrescente, nome: crescente)
	{
		cout << items[i].nome << " " << items[i].soma << endl;
	}
	delete[] items; //desnecessario mas fica "bonito" saber o que se faz
	return 0;
}
