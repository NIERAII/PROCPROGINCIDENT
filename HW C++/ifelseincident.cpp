#include <iostream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
#include <Windows.h>
#include <map>
#include <vector>
#include <sstream>

using namespace std;
float ln(float x) {
    //https://ru.wikipedia.org/wiki/%D0%9D%D0%B0%D1%82%D1%83%D1%80%D0%B0%D0%BB%D1%8C%D0%BD%D1%8B%D0%B9_%D0%BB%D0%BE%D0%B3%D0%B0%D1%80%D0%B8%D1%84%D0%BC
    return 2.30259 * log(x);
}

float calculateY(float x) {
    return (x * x - 2 * x + 2) / (x - 1);
} // https://discord.com/channels/@me/1075531659451056259/1150796298585382942

int sign(int x) {
    if (x > 0) {
        return 1;
    }
    else if (x == 0) {
        return 0;
    }
    else if (x < 0) {
        return -1;
    }
}

#define WIDTHs 80
#define HEIGHTs 24



void setCursorPosition(int x, int y) {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}

void drawGraph() {
    double y;
    int x;

    for (x = 0; x < WIDTHs; x++) {

        y = sin(2 * 3.14159 * x / WIDTHs);

        int plotY = (int)((y + 1) * 0.5 * HEIGHTs);

        setCursorPosition(x, plotY + 52);
        cout << '*';
    }
    setCursorPosition(0, 80);
}


double calculateRectangleArea(double length, double width) {
    return length * width;
}

double calculateTriangleArea(double base, double height) {
    return 0.5 * base * height;
}

double calculateCircleArea(double radius) {
    return 3.14 * pow(radius, 2);
}


int romanToInt(string s) {
    map<char, int> romanValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int result = 0;

    for (int i = 0; i < s.length(); i++) {
        int current = romanValues[s[i]];

        if (i < s.length() - 1 && current < romanValues[s[i + 1]]) {
            result -= current;
        }
        else {
            result += current;
        }
    }

    return result;
}


void genSeq(int m, int i, int c) {
    int S = i;

    S = (m * S + i) % c;
    cout << S << " ";

    cout << endl;
}


int convertDigit(char digit) {
    if (digit >= '0' && digit <= '9') {
        return digit - '0';
    }
    else {
        return 10 + digit - 'A';
    }
}

char convertToNewBase(int digit) {
    if (digit >= 0 && digit <= 9) {
        return '0' + digit;
    }
    else {
        return 'A' + (digit - 10);
    }
}

string convertNumber(const string& number, int oldBase, int newBase) {
    int decimal = 0;
    int power = 1;

    // Convert the number to decimal
    for (int i = number.length() - 1; i >= 0; i--) {
        int digit = convertDigit(number[i]);
        decimal += digit * power;
        power *= oldBase;
    }

    string result = "";

    // Convert the decimal number to new base representation
    while (decimal > 0) {
        int digit = decimal % newBase;
        result += convertToNewBase(digit);
        decimal /= newBase;
    }

    // Reverse the result to get the correct order
    reverse(result.begin(), result.end());

    return result;
}

int divison(int firstNumber, int secondNumber) { // НОД Делением
    while (firstNumber != 0 and secondNumber != 0) {
        if (firstNumber > secondNumber) {
            firstNumber = firstNumber % secondNumber;
        }
        else {
            secondNumber = secondNumber % firstNumber;
        }
    }
    return firstNumber + secondNumber;
}

int substruction(int firstNumber, int secondNumber) { // НОД Вычитанием
    while (firstNumber != 0 and secondNumber != 0) {
        if (firstNumber > secondNumber) {
            firstNumber = firstNumber - secondNumber;
        }
        else {
            secondNumber = secondNumber - firstNumber;
        }
    }
    return firstNumber + secondNumber;
}

bool isConsonant(char c) {
    // Здесь можно указать условия для определения согласных букв
    // Например:
    return isalpha(c) && !strchr("aeiouAEIOU", c);
}


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
        cout << alphabet << "\n\n";



    }
    else if (hw == 4) {
        cout << "HW #4\n\n";
        cout << "Task1\n\n";
        ofstream file("numbers.txt"); // создаем файл для записи

        if (file.is_open()) {
            cout << "Input 10 numbers: " << endl;

            int number;
            for (int i = 0; i < 10; i++) {
                cin >> number;
                file << number << endl; // записываем число в файл
            }

            file.close(); // закрываем файл

            ifstream inputFile("numbers.txt"); // открываем файл для чтения

            if (inputFile.is_open()) {
                int sum = 0;
                int value;

                while (inputFile >> value) {
                    sum += value; // суммируем числа из файла
                }

                inputFile.close(); // закрываем файл

                cout << "Addition result: " << sum << endl << endl;
            }
            else {
                cout << "Err." << endl << endl;
            }
        }
        else {
            cout << "Err." << endl << endl;
        }

        cout << "Task2\n\n";
        int input;
        cout << "Int1\n";
        cin >> input;
        cout << sign(input) << endl << endl;

        cout << "Task3\n\n";

        int choice;
        double result;

        cout << "Choose shape:\n";
        cout << "1. Rectangle\n";
        cout << "2. Triangle\n";
        cout << "3. Circle\n";
        cin >> choice;

        switch (choice) {
        case 1:
            double length, width;
            cout << "Length n Width: ";
            cin >> length >> width;
            result = calculateRectangleArea(length, width);
            break;
        case 2:
            double base, height;
            cout << "Base n Height: ";
            cin >> base >> height;
            result = calculateTriangleArea(base, height);
            break;
        case 3:
            double radius;
            cout << "Radius: ";
            cin >> radius;
            result = calculateCircleArea(radius);
            break;
        default:
            cout << "Invalid.\n\n";
            return 0;
        }

        cout << "S: " << result << endl << endl;

        cout << "Task4\n\n";
        int numStars = 36;
        int numStripes = 8;

        for (int i = 1; i <= numStripes / 2; i++) {
            for (int j = 1; j <= numStars; j++) {
                if (j <= numStars / 3) {
                    cout << "*";
                }
                else {
                    cout << "_";
                }
            }
            cout << endl;
        }
        for (int i = 1; i <= numStripes / 2; i++) {
            for (int j = 1; j <= numStars; j++) {
                if (j <= numStars) {
                    cout << "_";
                }
            }
            cout << endl;
        }

        cout << "\n\nTask5\n\n";
        drawGraph();

        cout << "Task6\n\n";

        string romanNumeral;
        cout << "Roman Number: ";
        cin >> romanNumeral;

        int arabicNumeral = romanToInt(romanNumeral);

        cout << "Arabic Number: \n\n" << arabicNumeral << endl;

        cout << "Task7\n\n";

        int m1 = 37, i1 = 3, c1 = 64;
        int m2 = 25173, i2 = 13849, c2 = 65537;

        cout << "Variant 1: ";
        genSeq(m1, i1, c1);

        cout << "Variant 2: ";
        genSeq(m2, i2, c2);

        cout << "\n\nTask8\n\n";

        float A[3][4]{ {5,  2, 0, 10},
                       {3,  5, 2, 5},
                       {20, 0, 0, 0} };

        float B[4][2]{ {1.2, 0.5},
                       {2.8, 0.4},
                       {5,   1},
                       {2,   1.5} };

        float C[3][2]{ {0, 0},
                       {0, 0},
                       {0, 0} };

        cout << "\n \n";
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 2; col++) {
                for (int res = 0; res < 4; res++) { //Переменная res используется во вложенном цикле для выполнения итераций по каждому элементу результирующей матрицы C. В данном случае, 
                    //res итерируется от 0 до 3, чтобы умножить каждый элемент строки матрицы A на соответствующий элемент столбца матрицы B и получить конечное значение для каждого элемента матрицы C. 
                    //Внешний цикл for итерируется по строкам матрицы A, внутренний цикл for итерируется по столбцам матрицы B, а цикл с переменной res итерируется по индексам элементов, которые участвуют в умножении.
                    //Таким образом, при каждой итерации цикла res, происходит умножение соответствующих элементов из матриц A и B, и результат суммируется в элементе результирующей матрицы C.
                    C[row][col] += A[row][res] * B[res][col];
                }
            }
        }

        float sumMax = 0, sumMin = 38;
        float comMax = 0, comMin = 19;
        float sumMoney = 0, sumCom = 0;
        float sum = 0;
        for (int i = 0; i < 3; i++) {
            sumMoney += C[i][0];
            sumCom += C[i][1];
            sumMax = max(sumMax, C[i][0]);
            sumMin = min(sumMin, C[i][0]);
            comMax = max(comMax, C[i][1]);
            comMin = min(comMin, C[i][1]);
        }

        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 2; col++) {
                cout << C[row][col] << " ";
            }
            cout << "\n";
        }
        cout << "sumMax: " << sumMax << endl;
        cout << "sumMin: " << sumMin << endl;
        cout << "comMax: " << comMax << endl;
        cout << "comMin: " << comMin << endl;
        cout << "sumMoney: " << sumMoney << endl;
        cout << "sumCom: " << sumCom << endl;
        cout << "sum: " << sumMoney + sumCom << endl;

        cout << "\n\nTask9\n\n";

        string number;
        int oldBase, newBase;

        cout << "Enter the number: ";
        cin >> number;

        cout << "Enter the old base: ";
        cin >> oldBase;

        cout << "Enter the new base: ";
        cin >> newBase;

        string convertedNumber = convertNumber(number, oldBase, newBase);

        cout << "Converted number: " << convertedNumber << endl;
    }
    else if (hw == 5) {
        cout << "HW #5\n\n";
        cout << "Task1\n\n";
        int firstNumber;
        cout << "Enter first number: " << endl;
        cin >> firstNumber;
        int secondNumber;
        cout << "Enter second number: " << endl;
        cin >> secondNumber;
        int number;
        cout << "Select method: " << endl;
        cout << "1. Division\n2. Substruction " << endl;
        cin >> number;
        switch (number) {
        case 1:
            cout << divison(firstNumber, secondNumber) << endl;
            break;
        case 2:
            cout << substruction(firstNumber, secondNumber) << endl;
            break;
        }
        cout << "\n\nTask2\n\n";
        int lastNumber;
        cout << "\n\nLast Number" << endl;
        cin >> lastNumber;
        bool flanderson;
        for (int i = lastNumber; i > 1; --i) {
            flanderson = true;
            for (int j = pow(i, 0.5); j > 1; --j) {
                if (i % j == 0) {
                    flanderson = false;
                    break;
                }
            }
            if (flanderson) {
                cout << i << endl;
            }
        }
        cout << "Task3.1" << endl << endl; // Статистическая обработка текстового файла: поиск наименее встречающейся согласной буквы.

        ofstream file("text.txt");
        if (file.is_open()) {
            cout << "Input text: " << endl;
            string tx;
            cin.ignore();
            getline(cin, tx);
            file << tx << endl;
            file.close();
        }
        else {
            cout << "Can't open file." << endl;
            return 1;
        }

        string filename = "text.txt";
        ifstream file_stream(filename);
        if (!file_stream) {
            cout << "Can't open file." << endl;
            return 1;
        }

        map<char, int> consonantCount;

        char c;
        while (file_stream.get(c)) {
            if (isConsonant(c)) {
                consonantCount[c]++;
            }
        }

        vector<pair<char, int>> sortedConsonants;
        for (const auto& entry : consonantCount) {
            sortedConsonants.push_back(entry);
        }

        sort(sortedConsonants.begin(), sortedConsonants.end(),
            [](const auto& a, const auto& b) {
                return a.second < b.second;
            });

        if (!sortedConsonants.empty()) {
            cout << "Consonant min: "
                << sortedConsonants[0].first << endl;
        }
        else {
            cout << "No consonants." << endl;
        }

        cout << "Task3.2" << endl << endl;

        ifstream inputFile("text.txt");
        ofstream outputFile("output.txt");

        if (inputFile.is_open() && outputFile.is_open()) {
            string line;
            vector<string> words;

            while (getline(inputFile, line)) {
                stringstream ss(line);
                string word;

                while (ss >> word) {
                    words.push_back(word);
                }
            }

            for (const string& word : words) {
                outputFile << word << ",";
            }

            inputFile.close();
            outputFile.close();
        }
        else {
            cout << "Err: can't open file." << endl;
        }

        

    }
    else { cout << "There is no such HW"; }
}