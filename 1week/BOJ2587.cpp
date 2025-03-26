// 백준 문제 : 대표값2

#include <iostream>
#define SWAP(x,y,tmp) (tmp = x, x = y, y = tmp)

using namespace std;

int partition(int list[], int left, int right){
	int pivot, low, high;
	pivot = left;
	low = left;
	high = right;
	int tmp;
	
	while(low < high){
		while(low < right && list[low] <= list[pivot]){ // list[low]가 list[pivot]보다 커지면 stop
			low++;
		}
		while(high > left && list[high] >= list[pivot]){ // list[high]가 list[pivot]보다 작아지면 stop
			high--;
		}
		if(low < high) SWAP(list[low],list[high],tmp);	// list[low]와 list[high] 교환
	}
	SWAP(list[pivot],list[high],tmp); // list[pivot]와 list[high] 교환
	return high; // 바뀐 pivot값 반환
}

void quick_sort(int list[], int left, int right){
	if(left < right) { 
		int q = partition(list,left,right);
		
		quick_sort(list,left,q-1);
		quick_sort(list,q+1,right);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int leng = 5;
	int start = 0;
	int end = 4;

	int arr[leng];
	int sum = 0;
	for(int i=0;i<leng;i++){
		cin >> arr[i];
		sum += arr[i];
	}
	
	cout << sum / leng << "\n";
	quick_sort(arr,start,end);
	// for(int i=0;i<leng;i++){
	// 	cout << arr[i] << " ";
	// }
	// putchar('\n');
	cout << arr[(start+end)/2] << "\n";
	
}