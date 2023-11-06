#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Item {
public:
    int weight;
    int value;

    Item(int w, int v) : weight(w), value(v) {}
};

bool compareItems(const Item& item1, const Item& item2) {
    return (item1.value * 1.0 / item1.weight) > (item2.value * 1.0 / item2.weight);
}

class Knapsack {
public:
    vector<Item> items;
    int capacity;

    Knapsack(int cap) : capacity(cap) {}

    void addItem(int weight, int value) {
        items.push_back(Item(weight, value));
    }

    double fractionalKnapsack() {
        double totalValue = 0.0;
        sort(items.begin(), items.end(), compareItems);

        for (const Item& item : items) {
            if (capacity == 0) {
                break;  // Knapsack is full
            }
            double fraction = min(static_cast<double>(capacity), static_cast<double>(item.weight));
            totalValue += (fraction / item.weight) * item.value;
            capacity -= fraction;
        }
        return totalValue;
    }
};

int main() {
    int n;  // Number of items
    int capacity;  // Knapsack capacity

    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    Knapsack knapsack(capacity);

    for (int i = 0; i < n; ++i) {
        int weight, value;
        cout << "Enter weight and value for item " << i + 1 << ": ";
        cin >> weight >> value;
        knapsack.addItem(weight, value);
    }

    double maxValue = knapsack.fractionalKnapsack();

    cout << "The maximum value that can be obtained is: " << maxValue << endl;

    return 0;
}
