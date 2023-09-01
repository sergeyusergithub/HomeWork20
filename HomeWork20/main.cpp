#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
void fill_arr(T arr[], const int length, int left, int right);

template <typename T>
void print_arr(T arr[], const int length);

template <typename T>
int search_index(T arr[], const int length, T num, int begin = 0);

template <typename T>
int search_last_index(T arr[], const int length, T num);

template <typename T>
int search_last_index(T arr[], const int length, T num, int begin);

template <typename T>
T arr_min(T arr[], const int length);

template <typename T>
T arr_max(T arr[], const int length);

template <typename T>
double mean_value(T arr[], const int length);

template <typename T>
void range(T arr[], int length, T first, T last);

template <typename T>
int count(T arr[], const int length, T num);

template <typename T>
void sort_arr(T arr[], const int length);



int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	const int size = 20;
	int arr[size]{ 0 };

	std::cout << "Заполнение массива случайными числами:\n";
	fill_arr(arr, size, -50, 50);
	print_arr(arr, size);
	std::cout << '\n';
	std::cout << "Поиск индекса первого вхождения элемента в массив:\n";
	std::cout << "Введите искомый элемент массива -> ";
	std::cin >> n;

	int index = search_index(arr, size, n);
	if (index != -1)
		std::cout << "Позиция искомого элемента: " << index << "\n\n";
	else
		std::cout << "Такого элемента в массиве нет!\n\n";

	std::cout << "Поиск индекса последнего вхождения элемента в массив:\n";
	std::cout << "Введите искомый элемент массива -> ";
	std::cin >> n;
	int last_index = search_last_index(arr, size, n);
	if (last_index != -1)
		std::cout << "Позиция искомого элемента: " << last_index << "\n\n";
	else
		std::cout << "Такого элемента в массиве нет!\n\n";

	std::cout << "Поиск индекса последнего вхождения элемента в массив:\n";
	std::cout << "Введите начальную позицию поиска в массива -> ";
	int bgn;
	std::cin >> bgn;
	last_index = search_last_index(arr, size, n,bgn);
	if (last_index != -1)
		std::cout << "Позиция искомого элемента: " << last_index << "\n\n";
	else
		std::cout << "Такого элемента в массиве нет!\n\n";

	std::cout << "Минимальный элемент массива: \n";
	std::cout << arr_min(arr, size);
	std::cout << "\n\n";

	std::cout << "Максимальный элемент массива: \n";
	std::cout << arr_max(arr, size);
	std::cout << "\n\n";

	std::cout << "Среднее арифметическое массива: \n";
	std::cout << mean_value(arr, size);
	std::cout << "\n\n";

	std::cout << "Элементы массива входящие в заданный диапазон:\n";
	int lst;
	std::cout << "Введите диапазон -> ";
	std::cin >> bgn >> lst;

	range(arr, size, bgn, lst);

	std::cout << "\n\n";

	std::cout << "Введите число ->";
	std::cin >> n;
	std::cout << "Количество " << n << " в массиве: " << count(arr, size, n) << "\n\n";

	std::cout << "Отсортированный по возрастанию массив:\n";
	sort_arr(arr, size);
	print_arr(arr, size);



	return 0;
}

template <typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
}

template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}

template <typename T>
int search_index(T arr[], const int length, T num, int begin) {
	for (int i = begin; i < length; i++)
		if (arr[i] == num)
			return i;
	return -1;
}

template <typename T>
int search_last_index(T arr[], const int length, T num) {
	for (int i = length - 1; i >= 0; i--)
		if (arr[i] == num)
			return i;
	return -1;
}

template <typename T>
int search_last_index(T arr[], const int length, T num, int begin) {
	for (int i = length - 1; i >= begin; i--)
		if (arr[i] == num)
			return i;
	return -1;
}

template <typename T>
T arr_min(T arr[], const int length) {
	T min;
	min = arr[0];
	for (int i = 1; i < length; i++)
		if (min > arr[i])
			min = arr[i];
	return min;
}

template <typename T>
T arr_max(T arr[], const int length) {
	T max;
	max = arr[0];
	for (int i = 1; i < length; i++)
		if (max < arr[i])
			max = arr[i];
	return max;
}

template<typename T>
double mean_value(T arr[], const int length)
{	
	T sum = 0;
	for (int i = 0; i < length; i++)
		sum += arr[i];

	return sum/(double)length;
}

template<typename T>
void range(T arr[], int length, T first, T last)
{
	for (int i = 0; i < length; i++)
		if (first < arr[i] && arr[i] < last)
			std::cout << arr[i] << ", ";
	std::cout << "\b\b \n";
}

template <typename T>
int count(T arr[], const int length, T num) {
	int count = 0;
	for (int i = 0; i < length; i++)
		if (num == arr[i])
			count++;

	return count;
}

template <typename T>
void sort_arr(T arr[], const int length) {
	for (int i = length - 1; i > 0; i--)
		for (int j = 0; j < length-1; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
}
