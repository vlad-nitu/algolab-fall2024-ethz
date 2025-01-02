#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


using vec_t = std::vector<int>;

struct entry_t {
	int pos; 
	int word; 
};

void solve() {
	int vec_len = 0;
	int n; cin >> n;
	vec_t word_count(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> word_count[i];
		vec_len += word_count[i];
	}

	std::vector<entry_t> v{};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < word_count[i]; ++j) {
			int pij; cin >> pij; // Position of word `i` in document `j`
			v.push_back({pij, i});
		}
	}

	sort(v.begin(), v.end(), [](const entry_t &e1, const entry_t &e2) {
      		return e1.pos < e2.pos;
	});

	int min_interval = INT_MAX;
	int i = 0, j = 0;
	int missing_words = n - 1;  // Number of words that are missing in the sliding window; Initially, word[0] is the only one in the sliding window => n - 1 words not in the SW yet
	word_count.clear(); word_count.resize(vec_len, 0); // word_count[i] = # of times word `i` is in the current sliding window [i:j] inclusive
	word_count[v[0].word] = 1;
	while (i < vec_len && j < vec_len) {
		if (i > j) {
			j = i;
		}

		if (missing_words != 0) {
			// Add word[j] to SW
			j ++;
			word_count[v[j].word] ++;
			if (word_count[v[j].word] == 1)
				missing_words --;
				
		}
		else {
			while (missing_words == 0) {

				min_interval = std::min(min_interval, v[j].pos - v[i].pos + 1);
				// Remove word[i] from SW
				i ++; 
				word_count[v[i - 1].word] --;
				if (word_count[v[i - 1].word] == 0)
					missing_words ++;
			}
		}

	}

	std::cout << min_interval << '\n';
}

int main() {
	int t; cin >> t;
	while (t--)
		solve();
}
