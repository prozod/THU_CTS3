#include <iostream>
#include "dlist.h"

using namespace std;

int main() {
    DList<int> queue{};

    initializeDList(queue);

    //insert 5 values
    for (int i = 1; i <= 5; i++) {
        cout << "put: " << 10 * i << endl;
        put(queue, 10 * i);
    }

    //remove 3 values and print them to console
    for (int j = 1; j <= 3; j++) {
        int value;
        if (get(queue, value))
            cout << "     get: " << value << endl;
    }

    cout << "Laenge: " << length(queue) << endl;

    //insert 5 values
    for (int i = 6; i <= 10; i++) {
        cout << "put: " << 10 * i << endl;
        put(queue, 10 * i);
    }

    cout << "Laenge: " << length(queue) << endl;

    //remove all values and print them
    while (!isEmpty(queue)) {
        int value;
        get(queue, value);
        cout << "     get: " << value << endl;
    }

    return 0;
}
