## Topics
- Sliding Window, Counting

## Idea
- Combine all the words from all documents into a 1D vector of entry_t = {position, word_id}, sorted by `position`
- Use sliding window that expans when we don't have all the individual words in the sliding window (j ++ - right ptr iff `missing_words != 0`), and shrinks when we found a sliding window that has all words in it (i ++ - left ptr iff `missing_words == 0`).
- To count in O(1) - online which words are currently stored in the sliding window, we use a 1D vector: `word_count[i] = # of times word `i` is in the current sliding window [i:j] inclusive` and a variable: `missing_words =  Number of words that are missing from the sliding window;`
- The variable `missing_words` is updated when `word_count[i] == 0` (meaning that the word was removed from the sliding window) OR when `word_count[j] == 1` (meaning that the word was just added to the sliding window, and there was no word `j` in the SW before).

## Time complexity
- `O(NlogN)` due to sorting, even though sliding window is `O(N)`
