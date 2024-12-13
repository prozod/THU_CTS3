#include <iostream>
#include "Bibliography.h"
#include "Medium.h"
#include "Article.h"
#include "Book.h"
using namespace std;

void testBibliography() {
    Bibliography bibliography(10);
    auto b1 = new Book("Ra01", "Dietmar Ratz", "Grundkurs Programmieren in Java", 2001, "Hanser-Verlag");

    auto b2 = new Book("Kr03", "Guido Krueger", "Handbuch der Java-Programmierung", 2003, "Addison-Wesley");

    auto *a1 = new Article("Pa72",
                           "D. L. Parnas",
                           "On the Criteria To Be Used in Decomposing Systems into Modules",
                           1972,
                           "Communications of the ACM",
                           15,
                           1053);

    bibliography.insert(b1);
    bibliography.insert(b2);
    bibliography.insert(a1);
    cout << "Bibliography:" << endl << bibliography;
    cout << (*bibliography["Pa72"]).toString() << endl;
}

int main() {
    testBibliography();
    return 0;
}
