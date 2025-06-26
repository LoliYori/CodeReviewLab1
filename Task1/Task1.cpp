//Археолог нашел N артефактов.Известны веса(сi) и объемы(di) артефактов.Нужно
//выбрать такое подмножество найденных вещей, чтобы суммарный их вес не превысил B кг, но
//был наиболее близок к B, а количество взятых артефактов было как можно больше.Известно,
//что решение единственно.Укажите порядковые номера вещей, которые надо взять.Исходные
//данные находятся в текстовом файле, в первой строке указаны N и B, а во второй строке 
//значения весов(в кг), в третьей объемы находок(в куб.см).Вывести так же суммарный вес 
//и суммарный объем результата.

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Artifact
{
	int weight;
	int volume;
};

bool SortWeight(Artifact a, Artifact b) {
	return a.weight < b.weight;
}

int main()
{
	setlocale(0, "");
	ifstream f1;
	f1.open("f.txt");
	if (!f1.is_open()) {
		cout << "Не удалось открыть файл f.txt(" << endl;
		return 1;
	}
	int n, b, sumw = 0, sumv = 0, k = 0, maxw = 0, maxv = 0;

	f1 >> n >> b;

	vector<Artifact> artifacts(n);

	for (int i = 0; i < n; i++) {
		f1 >> artifacts[i].weight;
	}
	for (int i = 0; i < n; i++) {
		f1 >> artifacts[i].volume;
	}

	sort(artifacts.begin(), artifacts.end(), SortWeight);
	while (k < n) {
		sumw = 0;
		sumv = 0;
		for (int j = k; j < n; j++) {
			if (artifacts[j].weight + sumw <= b) {
				sumw += artifacts[j].weight;
				sumv += artifacts[j].volume;
				if (maxw < sumw) {
					maxw = sumw;
					maxv = sumv;
				}
			}
		}
		if (maxw == b) {
			break;
		}
		else {
			k++;
		}
	}

	cout << "Максимальный вес артефактов = " << maxw << "\n" << "Объем взятых артефактов = " << maxv;
}
