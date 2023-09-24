#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int hw;
    cout << "CHOOSE HW\n";
    cin >> hw;
    if (hw == 1) {
        int a;
        int b;
        int c;
        cout << "HW #1\n\n";
        cout << "Task1\n\n";

        cout << "Your name\n\n";

        cout << "Task2\n\n";

        cout << "Int1\n";
        cin >> a;
        cout << "Int2\n";
        cin >> b;

        cout << "Addition: " << a + b << "\n";
        cout << "Substraction: " << a - b << "\n";
        cout << "Multiplication: " << a * b << "\n";
        cout << "Division: " << a % b << "\n\n";

        cout << "Task3\n\n";

        cout << "Int3\n";

        cin >> c;

        cout << "x = " << c / b << "\n\n";

        cout << "Task4\n\n";

        int D = b * b - 4 * a * c;

        if (D < 0) {
            cout << "No roots\n\n";
        }
        else if (D == 0) {
            cout << "x = " << -b / 2 * a;
        }
        else if (D > 0) {
            cout << "x1 = " << (-b + sqrt(D)) / 2 * a << "\nx2 = " << (-b - sqrt(D)) / 2 * a << "\n\n";
        }

        cout << "Task5\n\n";

        string dn;
        string curtains;
        string lamp;

        cout << "Day? \ny/n\n";
        cin >> dn;
        cout << "R curtains open? \ny/n\n";
        cin >> curtains;
        cout << "Is lamp on?";
        cin >> lamp;

        if (dn == "y" or curtains == "y" or lamp == "y") { cout << "Bright\n\n"; }
        else { cout << "Bruh\n\n"; }
    }
    if (hw == 2) {
        cout << "HW #2\n\n";
        cout << "Task1\n\n";

        double p = 3.14;
        double R, r, l, h;

        cout << "Radius of the larger base (R1)";
        cin >> R;
        cout << "Radius of the top (r)";
        cin >> r;
        cout << "Height (h)";
        cin >> h;
        cout << "Slant height (l)";
        cin >> l;

        double V = 1 / 3 * p * h * (R * R + R * r + r * r);
        double S = p * (R * R + (R + r) * l + r * r);

        cout << "V = " << V << "\n";
        cout << "S = " << S << "\n\n";

        cout << "Task3\n\n";


    }
    else { cout << "There is no such HW"; }
}