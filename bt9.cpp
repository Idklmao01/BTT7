#include <iostream>

using namespace std;

struct Node {
    char word[10];
    Node* next;
    Node(const char* w) {
        int i = 0;
        while (w[i] != '\0') {
            word[i] = w[i];
            i++;
        }
        word[i] = '\0';
        next = nullptr;
    }
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}

    void add(const char* word) {
        Node* newNode = new Node(word);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    const char* getMostFrequentWord() const {
        int maxCount = 0;
        const char* mostFrequent = nullptr;
        Node* current = head;
        while (current != nullptr) {
            int count = 0;
            Node* temp = head;
            while (temp != nullptr) {
                if (compareWords(temp->word, current->word)) {
                    count++;
                }
                temp = temp->next;
            }
            if (count > maxCount) {
                maxCount = count;
                mostFrequent = current->word;
            }
            current = current->next;
        }
        return mostFrequent;
    }

    void removeDuplicateWords() {
        Node* current = head;
        while (current != nullptr) {
            Node* runner = current;
            while (runner->next != nullptr) {
                if (compareWords(runner->next->word, current->word)) {
                    Node* temp = runner->next;
                    runner->next = runner->next->next;
                    delete temp;
                } else {
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    }

    int countWords() const {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    void print() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->word << " ";
            current = current->next;
        }
        cout << endl;
    }

private:
    Node* head;

    bool compareWords(const char* word1, const char* word2) const {
        int i = 0;
        while (word1[i] != '\0' && word2[i] != '\0') {
            if (word1[i] != word2[i]) {
                return false;
            }
            i++;
        }
        return word1[i] == '\0' && word2[i] == '\0';
    }
};

int main() {
    LinkedList list;
    char sentence[] = "Mot chiec la xanh xanh";
    char word[10];
    int index = 0;
    for (size_t i = 0; i <= sizeof(sentence); i++) {
        if (sentence[i] != ' ' && sentence[i] != '\0') {
            word[index++] = sentence[i];
        } else {
            if (index > 0) {
                word[index] = '\0';
                list.add(word);
                index = 0;
            }
        }
    }
    cout << "Từ xuất hiện nhiều nhất: " << list.getMostFrequentWord() << endl;
    list.removeDuplicateWords();
    cout << "Số từ trong danh sách: " << list.countWords() << endl;

    return 0;
}
