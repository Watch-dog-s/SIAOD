#include <iostream>
#include <vector>
using namespace std;

int countSequences(int n) {
    // Инициализация массива для хранения промежуточных результатов
    vector<int> dp(n + 1, 0);

    // Базовые случаи
    dp[1] = 2; // 0 или 1
    dp[2] = 3; // 00, 01, 10

    // Заполнение массива с использованием динамического программирования
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    string a = "10101011010000101010101010101010101010110101010101010101011010110101000001010101010101101010101010101010101010110";

    // Вычисление длины строки
    int len = a.length();

    // Подсчет числа последовательностей для длины len
    int result = countSequences(len);

    cout << "Number of sequences without consecutive 1s: " << result << endl;

    return 0;
}
