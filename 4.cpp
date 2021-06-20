#include <iostream>
#include <queue>  

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	queue <int> q;  

	cout << "Пользователь, пожалуйста введите 5 чисел: " << endl;

	for (int h = 0; h < 5; h++) {
		int a;

		cin >> a;

		q.push(a);  
	}

	cout << endl;
	cout << "Самый первый элемент в очереди: " << q.front() << endl;  
																	 
	q.pop();  

	cout << "Новый первый элемент (после удаления): " << q.front() << endl;

	if (!q.empty()) cout << "Очередь не пуста!";  

	system("pause");
	return 0;
}