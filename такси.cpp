#include "iostream"
using namespace std;
int main()

{
	setlocale(LC_ALL, "Russian");
	const int A = 100;
	int N;
	cout << "Введите количество сотрудников компании: ";
	cin >> N;
	int dist[A];
	int taxi[A];
	int taxi№[A];//тарифы за один километр
	int dist_index[A];//расстояние до дома сотрудника
	
	cout << "Введите по порядку расстояние для всех сотрудников:" << endl;
	for (int i = 0; i < N; i++) {
		cin >> dist[i];//ввыод расстояния
		dist_index[i] = i;
	}
	cout << "Введите по порядку тарифы за один километр в каждом такси: " << endl;
	for (int i = 0; i < N; i++) {
		cin >> taxi[i];
		taxi№[i] = i;
	}

	for (int i = 0; i < N - 1; i++) {//Сортировка расстояний методом пузырька
		for (int j = i + 1; j < N; j++) {
			if (dist[i] < dist[j]) {
				int t = dist[i];
				dist[i] = dist[j];
				dist[j] = t;
				t = dist_index[i];
				dist_index[i] = dist_index[j];
				dist_index[j] = t;
			}
		}
	}
	for (int i = 0; i < N - 1; i++) {//Сортировка тарифов в обратном порядке
		for (int j = i + 1; j < N; j++) {
			if (taxi[i] > taxi[j]) {
				int t = taxi[i];
				taxi[i] = taxi[j];
				taxi[j] = t;
				t = taxi№[i];
				taxi№[i] = taxi№[j];
				taxi№[j] = t;
			}
		}
	}
	for (int i = 0; i < N - 1; i++) { //Сопоставление дистанций и тарифов
		for (int j = i + 1; j < N; j++) {
			if (dist_index[i] > dist_index[j]) {
				int t = dist_index[i];
				dist_index[i] = dist_index[j];
				dist_index[j] = t;
				t = taxi№[i];
				taxi№[i] = taxi№[j];
				taxi№[j] = t;
			}
		}
	}

	for (int i = 0; i < N; i++) {//вывод номера такси для каждого сотрудника
		cout << "\nсотруднику №" << i + 1 << " следует уехать на такси №" << taxi№[i] + 1 << endl;
	}

	cout << "\n\n";
	return 0;
}
