//background:
//Once upon a time, in the Kingdom of Loowater, a minor nuisance turned into a major problem.
//The shores of Rellau Creek in central Loowater had always been a prime breeding ground for geese.Due to the lack of predators, the geese population was out of control.The people of Loowater mostly kept clear of the geese.Occasionally, a goose would attack one of the people, and perhaps bite off a finger or two, but in general, the people tolerated the geese as a minor nuisance.
//
//One day, a freak mutation occurred, and one of the geese spawned a multi - headed fire - breathing dragon.When the dragon grew up, he threatened to burn the Kingdom of Loowater to a crisp.Loowater had a major problem.The king was alarmed, and called on his knights to slay the dragon and save the kingdom.
//
//The knights explained : "To slay the dragon, we must chop off all its heads. Each knight can chop off one of the dragon's heads. The heads of the dragon are of different sizes. In order to chop off a head, a knight must be at least as tall as the diameter of the head. The knights' union demands that for chopping off a head, a knight must be paid a wage equal to one gold coin for each centimetre of the knight's height."
//
//Would there be enough knights to defeat the dragon ? The king called on his advisors to help him decide how many and which knights to hire.After having lost a lot of money building Mir Park, the king wanted to minimize the expense of slaying the dragon.As one of the advisors, your job was to help the king.You took it very seriously : if you failed, you and the whole kingdom would be burnt to a crisp.
//
//The input contains several test cases.The first line of each test case contains two integers between 1 and 20000 inclusive, indicating the number n of heads that the dragon has, and the number m of knights in the kingdom.The next n lines each contain an integer, and give the diameters of the dragon's heads, in centimetres. The following m lines each contain an integer, and specify the heights of the knights of Loowater, also in centimetres. 
//The last test case is followed by a line containing :
//0 0
//
//For each test case, output a line containing the minimum number of gold coins that the king needs to pay to slay the dragon.If it is not possible for the knights of Loowater to slay the dragon, output the line :
//Loowater is doomed!


#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int partition(int arr[], int left, int right) {
	int key = arr[left];

	while (left < right) {
		while (left < right && arr[right] >= key)
			--right;
		if (left >= right)
			break;
		else {
			arr[left] = arr[right];
		}

		while (left < right && arr[left] <= key)
			++left;
		if (left >= right)
			break;
		else {
			arr[right] = arr[left];
		}

	}
	arr[left] = key;
	return left;
}

void Sort(int arr[], int left, int right) {
	int mid;
	if (left < right) {
		mid = partition(arr, left, right);
		Sort(arr, left, mid - 1);
		Sort(arr, mid + 1, right);
	}
}

int main() {
	//n:龙头数量 m:骑士数量 dhs:dragon heads kts:knights
	int n, m, dhs[20000], kts[20000];
	while (scanf("%d%d", &n, &m)) {
		//结束用例
		if (n == 0 && m == 0)
			break;

		for (int i = 0; i < n; ++i) {
			scanf("%d", &dhs[i]);
		}

		for (int i = 0; i < m; ++i) {
			scanf("%d", &kts[i]);
		}
		//printf("end of input");

		//骑士的数量比少
		if (m < n) {
			printf("Loowater is doomed!\n");
			continue;
		}

		Sort(dhs, 0, n-1);
		Sort(kts, 0, m-1);
		//printf("end of sort");

		int i = 0, j = 0, cost = 0;
		while (i < n && j < m) {
			while (kts[j] < dhs[i] && j < m)
				++j;
			if (kts[j] >= dhs[i]) {
				cost += kts[j];
				j++;
				i++;
			}
		}
		if(i < n)
			printf("Loowater is doomed!\n");
		else 
			printf("%d\n", cost);
	}

	return 0;
}
