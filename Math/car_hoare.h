// Сортировка v[left] ... v[right] в порядке возрастания

void qsort(char *v[], int left, int right) {
	int i, last;
	void swap(char *v[], int i, int j);

	if (left >= right) // Ничего не делать, если в массиве
		return; // Меньше 2 элементов
	swap(v, left, (left+right)/2); // Переместить
	last = left; // Разделить v[0]

	for (i = left+1; i <= right; i++)
		if (strcmp(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last); // Вернуть разделить на место
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}