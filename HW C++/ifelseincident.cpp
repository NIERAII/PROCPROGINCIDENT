#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
float ln(float x) {
    //https://ru.wikipedia.org/wiki/%D0%9D%D0%B0%D1%82%D1%83%D1%80%D0%B0%D0%BB%D1%8C%D0%BD%D1%8B%D0%B9_%D0%BB%D0%BE%D0%B3%D0%B0%D1%80%D0%B8%D1%84%D0%BC
    return 2.30259 * log(x);
}

float calculateY(float x) {
    return (x * x - 2 * x + 2) / (x - 1);
} // https://discord.com/channels/@me/1075531659451056259/1150796298585382942

int main()
{
    int hw;
    cout << "CHOOSE HW\n";
    cin >> hw;
    if (hw == 39) {
        cout << "HAHABINO JUST DEFEATED HIHIBINO. YAY!!! :)";
    }
    else if (hw == 1) {
        int a;
        int b;
        int c;
        cout << "HW #1\n\n";
        cout << "Task1\n\n";

        cout << "Kostya\n\n";

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
        else {
            cout << "Bruh\n\n";
        }
        return 0;

    }
    else if (hw == 2) {
        cout << "HW #2\n\n";
        cout << "Task1\n\n";

        float p = 3.14;
        float R, r, l, h;

        cout << "Radius of the larger base (R1)";
        cin >> R;
        cout << "Radius of the top (r)";
        cin >> r;
        cout << "Height (h)";
        cin >> h;
        cout << "Slant height (l)";
        cin >> l;
        if (R == r) { cout << "Err: Its a cylinder\n\n"; }
        else {
            float V1;
            V1 = p * h * (R * R + R * r + r * r) / 3;
            float S = p * (R * R + (R + r) * l + r * r);

            cout << "V = " << V1 << "\n";
            cout << "S = " << S << "\n\n";
        }
        cout << "Task2\n\n";
        float x2, a2, w;
        cout << "FloatX2";
        cin >> x2;
        cout << "FloatA2";
        cin >> a2;
        if (abs(x2) < 1) {
            w = x2 * ln(abs(x2));
        }
        else {
            w = sqrt(a2 - pow(x2, 2));
        }
        if (isnan(w)) {
            cout << "\nInvalid input\n" << "\n\n";
        }
        else {
            cout << "w = " << w << "\n\n";
        }



        cout << "Task3\n\n";
        float x, y, b, z;

        cout << "FloatX\n";
        cin >> x;
        cout << "FloatY\n";
        cin >> y;
        cout << "FloatB\n";
        cin >> b;
        cout << "FloatZ\n";

        z = ln(b - y) * sqrt(b - x);
        if (isnan(z)) {
            cout << "\nInvalid input\n" << "\n\n";
        }
        else {
            cout << "z = " << z << "\n\n";
        }

        cout << "Task 4\n\n";
        int nn;
        cout << "intNN\n";
        cin >> nn;
        for (int i = nn + 1; i < nn + 11; i++) {
            cout << "Next is " << i << "\n\n";
        }

        cout << "Task5\n\n";

        float x3 = -4;
        float step = 0.5;

        cout << "    x    |    y    " << endl;
        cout << "--------------------" << endl;

        while (x3 <= 4) {
            float y2 = calculateY(x3);
            cout << setw(8) << x3 << " | " << setw(8) << y2 << endl;
            x3 += step;
        }

        return 0;

    }
    else if (hw == 3) {
        cout << "HW #3\n\n";
        cout << "Task1\n\n";
        float S, p, n;
        cout << "S, p, n\n";
        cin >> S >> p >> n;
        float r = p / 100.0;
        float m = ((S * r * pow(1 + r, n) / (12 * ((pow(1 + r, n) - 1)))));

        if (isnan(m) or isinf(m)) {
            cout << "Invalid\n\n";
        }
        else {
            cout << m << "\n\n";
        }

        cout << "Task2\n\n";

        float m0;
        cout << "S, m, n\n";
        cin >> S >> m0 >> n;

        //float m0 = ((S * r * pow(1 + r, n) / (12 * ((pow(1 + r, n) - 1)))));

        for (int p = 1; p <= 100; p++) {
            r = p / 100.0;
            m = ((S * r * pow(1 + r, n) / (12 * ((pow(1 + r, n) - 1)))));


            if (abs(m - m0) < 1) {
                break;
            }
        }
        cout << p << "\n\n";

        cout << "Task3+4\n\n";

        ofstream file("hahabino.txt");

        file << "Hello world 839";

        file.close();

        ifstream readFile("hahabino.txt");

        string contents;

        getline(readFile, contents);

        char arr[50];
        strcpy_s(arr, contents.c_str());
        cout << arr;
        cout << "\n";
        int i1 = 0;
        for (char i : arr) {
            if (i1 < contents.length()) {
                if (0 < (i - '0') && (i - '0') < 10) {
                    cout << (i - '0');
                }
            }
            i1++;
        }

        readFile.close();

        cout << "\n\nTask5\n\n";

        string input;
        string alphabet;

        cin >> input;


        for (char ch : input) {
            if (isdigit(ch) == 0)
                alphabet.push_back(ch);
        }
        sort(alphabet.begin(), alphabet.end());
        cout << alphabet << "\n";



    }
    else { cout << "There is no such HW"; }
}