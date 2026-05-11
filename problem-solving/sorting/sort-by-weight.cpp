#include <iostream>
#include <vector>
#include <map>

using namespace std;

// return the list with words with ascending order of its weight. if multiple words get
// same weightage, output list should have the values in occurances to the original list
// Weight calculation = len(word) * (sum of each character's ascii value which starts from 1 ie., a = 1, b=2,c=3)
// input = ["gnat", "brown","tang", "blue"]

struct Word {
    string word;
    int idx;
    int weight;

    friend ostream& operator<<(ostream& os, const Word& w) {
        return os << "Idx: " << w.idx << ", Word: " << w.word << ", Weight: " << w.weight << endl; 
    }
};

void bubble_sort(vector<Word> &words) {
    for(int i = words.size() - 1; i > 0; i--) {
        bool is_sorted = false;
        for(int j = 0; j < i; j++) {
            bool should_swap = false;
            if (words[j].weight > words[j+1].weight) {
                should_swap = true;
            } else if(words[j].weight == words[j + 1].weight && words[j].idx > words[j + 1].idx) {
                should_swap = true;
            }

            if(should_swap) {
                Word temp = words[j];
                words[j] = words[j+1];
                words[j+1] = temp;
                is_sorted = true;
            }
        }

        if(is_sorted == false) {
            break;
        }
    }
}

vector<string> sort_by_weight(string words[], int n) {
    vector<Word> res;
    for(int i = 0; i < n; i++) {
        string word = words[i];
        int sum = 0;
        for(int ch : word) {
            sum += int(ch) - 97;
        }
        int weight = sum * word.size();
        res.push_back(Word{word, i, weight});
    }

    bubble_sort(res);

    vector<string> res_to_return;
    for(int j = 0; j < n; j++) {
        cout << res[j];

        res_to_return[j] = res[j].word;
    }

    return res_to_return;
}

int main() {
    string input[4] = {"gnat", "brown","tang", "blue"};
    vector<string> res = sort_by_weight(input, 4);
    for(string word : res) {
        cout << word;
    }
    return 0;
}