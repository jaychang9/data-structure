#include<stdio.h>

void swap(int *a, int *b) {
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void bubbleSort(int array[], int n) {
	// 总共需要执行n-1次，每执行一次，将剩余元素中的最小元素冒泡至i位置
	for (int i = 0; i < n - 1; i++) {
		// 从最后两个元素开始两两比较，j从n-2开始递减至i,相邻两个元素两两比较，
		// 若后面元素大于前面的元素，则交换两个元素的位置
		// 直至array[i],array[i+1]
		for (int j = n - 2; j >= i; j--) {
			if (array[j + 1] < array[j]) {
				swap(&array[j + 1], &array[j]);
			}
		}
	}
}

void selectSort(int array[], int n) {
	// 简单选择排序，每次选出剩余元素中的最小元素放在i位置处
	int min = -1;
	for (int i = 0, minIndex = i; i < n - 1; i++) {
		min = array[i];
		for (int j = i + 1; j < n; j++) {
			if (array[j] < min) {
				min = array[j];
				minIndex = j;
			}
		}
		if (minIndex != i) {
			array[minIndex] = array[i];
			array[i] = min;
		}
	}
}

void insertSort(int array[], int n) {
	// 插入排序，类似打牌的时候，逐张拿牌，逐张理牌的一个过程
	for (int i = 1, j, temp; i < n; i++) {
		if ((temp = array[i]) < array[i - 1]) {
			for (j = i - 1; j >= 0; j--) {
				if (temp < array[j]) {
					// 将array[j]后移
					array[j + 1] = array[j];
				}
			}
			array[j + 1] = temp;
		}
	}
}

void print(int array[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

// 希尔排序
void shellSort(int array[], int n) {
	// 希尔排序是在直接插入排序基础上
	// 对所有元素进行分组，每个分组分别执行直接插入排序
	// 首次分组的步长为，元素个数除以2，后续每次分组的步长为当前步长除以2
	// 直至步长等于1时，对所有元素进行一次直接插入排序后结束
	for (int increment = n / 2; increment > 0; increment /= 2) {
		// 步长是几，就有几个分组
		for (int group = 0; group < increment; group++) {
			for (int i = increment + group, temp, j; i < n; i += increment) {
				if ((temp = array[i]) < array[i - increment]) {
					for (j = i - increment; j >= group && temp < array[j]; j -=
							increment) {
						array[j + increment] = array[j];
					}
					array[j + increment] = temp;
				}
			}
		}
	}
}

// 希尔排序
void shellSort2(int array[], int n) {
	// 希尔排序是在直接插入排序基础上
	// 对所有元素进行分组，每个分组分别执行直接插入排序
	// 首次分组的步长为，元素个数除以2，后续每次分组的步长为当前步长除以2
	// 直至步长等于1时，对所有元素进行一次直接插入排序后结束
	for (int increment = n / 2; increment > 0; increment /= 2) {
		// 其实无需显示的去分组，可以去掉分组的这一层循环，因为i从0循环到length-1，整个喧哗你的过程，也完成对所有分组内的插入排序
		for (int i = increment, temp, j; i < n; i++) {
			if ((temp = array[i]) < array[i - increment]) {
				for (j = i - increment; j >= 0 && temp < array[j]; j -=
						increment) {
					array[j + increment] = array[j];
				}
				array[j + increment] = temp;
			}
		}
	}
}

// 这里的s并不是数组的索引，而是指的是树的结点编号
void heapAdjust(int array[], int s, int m) {
	// 将所有非叶子节点为根节点的子树调整为大顶堆
	int i, temp;
	for (i = 2 * s, temp = array[s]; i <= m; i *= 2) {
		if (i < m && array[i] < array[i + 1]) {
			i++;
		}
		if (temp > array[i]) {
			break;
		}
		// 将左右孩子中的较大的那个赋值给array[startIndex]
		array[s] = array[i];
		s = i;
	}
	array[s] = temp;
}

//堆排序
void heapSort(int array[], int n) {
	//调整为大顶堆
	for (int i = n / 2; i >= 1; i--) {
		//调整以i为根节点的树为大顶堆
		heapAdjust(array, i, n);
	}

	//将大顶堆的根节点与最后一个元素交换
	int last = n;
	while (last > 1) {
		swap(&array[1], &array[last]);
		heapAdjust(array, 1, --last);
	}
}

int partion(int array[], int low, int high) {

	int pivot = array[high];
	while (low < high) {

		while (low < high && array[low] <= pivot) {
			low++;
		}
		if (low != high) {
			swap(&array[low], &array[high]);
		}
		while (low < high && array[high] >= pivot) {
			high--;
		}
		if (low != high) {
			swap(&array[low], &array[high]);
		}
	}
	return high;
}

void doQuickSort(int array[], int low, int high) {
	if (low < high) {
		int pivotKey = partion(array, low, high);
		doQuickSort(array, low, pivotKey - 1);
		doQuickSort(array, pivotKey + 1, high);
	}
}

void quickSort(int array[], int n) {
	doQuickSort(array, 1, n);
}

int main() {
//int array[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

//bubbleSort(array, 10);
//selectSort(array, 10);
//insertSort(array, 10);
	//shellSort2(array, 9);
	int array[] = { 0, 50, 10, 90, 30, 70, 40, 80, 60, 20 };
	//heapSort(array, 9);
	quickSort(array, 9);
	print(array, 10);
	return 0;
}
