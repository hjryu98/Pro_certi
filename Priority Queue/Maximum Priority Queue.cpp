#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <iostream>
using namespace std;

typedef struct MaxPriorityQueue {
	int arr[100020];
	int len = 0;

	void push(int x) {
		arr[++len] = x;
		register int i = len;

		while (i > 1) {
			if (arr[i] > arr[i / 2]) {
				int tmp = arr[i];
				arr[i] = arr[i / 2];
				arr[i / 2] = tmp;
				i /= 2;
			}

			else break;
		}
	}

	int pop() {
		if (!len) return 0;
		int ret = arr[1];
		arr[1] = arr[len];
		arr[len--] = -1 * 0x7fff0000;

		register int i = 1;

		while (i * 2 <= len) {
			if (arr[i] >= arr[i * 2] && arr[i] >= arr[i * 2 + 1]) break;
			else if (arr[i * 2] > arr[i * 2 + 1]) {
				int tmp = arr[i];
				arr[i] = arr[i * 2];
				arr[i * 2] = tmp;
				i *= 2;
			}
			else {
				int tmp = arr[i];
				arr[i] = arr[i * 2 + 1];
				arr[i * 2 + 1] = tmp;
				i = i * 2 + 1;
			}
		}

		return ret;
	}

	int size_() {
		return len;
	}
};
MaxPriorityQueue pq;
int n;
int main() {
	fastio;

	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		if (!a) cout << pq.pop() << "\n";
		else pq.push(a);
	}

	return 0;
}