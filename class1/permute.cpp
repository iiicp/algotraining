#include <stdio.h>
#include <vector>

using namespace std;

void permute_recursive(vector<vector<int>>&ans, vector<bool>&memo, vector<int>&path, int k, int idx) {

	if (idx == k) {
		ans.push_back(path);
		return;
	}

	// all choise
	for (int i = 0; i < k; ++i) {
		if (memo[i] == false) {
			memo[i] = true;
			path.push_back(i+1);
			permute_recursive(ans, memo, path, k, idx + 1);
			path.pop_back();
			memo[i] = false;
		}
	}
}

void combination_recursive(vector<vector<int>>&ans, vector<bool>&memo, vector<int>&path, int k, int idx) {
	if (idx == k) {
		ans.push_back(path);
		return;
	}

	for (int i = idx; i < k; i++) {
		if (memo[i] == false) {
			memo[i] = true;
			path.push_back(i+1);
			combination_recursive(ans, memo, path, k, i + 1);
			memo[i] = false;
			path.pop_back();
		}
	}
}

int main(void){
	int k = 5;
	vector<int> path;
	vector<bool> memo(k, false);
	vector<vector<int>> ans;
	printf("permute\n");
	permute_recursive(ans, memo, path, k, 0);

	for (auto &p: ans) {
		for (auto &q : p) {
			printf("%d ", q);
		}
		printf("\n");
	}

	printf("nums: %d\n", ans.size());

	printf("combinations\n");
	ans.clear();
	path.clear();
	memo = vector<bool>(k, false);
	combination_recursive(ans, memo, path, k, 0);

	
	for (auto &p: ans) {
		for (auto &q : p) {
			printf("%d ", q);
		}
		printf("\n");
	}
	printf("nums: %d\n", ans.size());
	return 0;
}
