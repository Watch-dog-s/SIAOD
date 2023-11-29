
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


void bubbleSort(vector<int>& vec);


struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value)
    {
        this->data = value;
        left = nullptr;
        right = nullptr;
    }
};





TreeNode* createTree(vector <int>arr, int start, int end) {


    bubbleSort(arr);

    if (start > end) {
        return nullptr;
    }

    int mid = (start + end) / 2;
    TreeNode* root = new TreeNode(arr[mid]);

    root->left = createTree(arr, start, mid - 1);
    root->right = createTree(arr, mid + 1, end);

    return root;
}




int getHeight(TreeNode* root)
{
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return 1 + max(leftHeight, rightHeight);
}




int countEdges(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }


    int edges = 0;


    if (root->left != nullptr) {
        edges++;
    }


    if (root->right != nullptr) {
        edges++;
    }


    edges += countEdges(root->left);
    edges += countEdges(root->right);

    return edges;
}






void printTree(TreeNode* root, int space = 0)
{
    const int spacing = 5;

    if (root == nullptr)
    {
        return;
    }

    space += spacing;

    printTree(root->right, space);

    cout << endl;
    for (int i = spacing; i < space; i++) {
        cout << " ";
    }
    cout << root->data << "\n";

    printTree(root->left, space);
}




float calculateAverage(TreeNode* root, int& sum, int& count) {
    if (root == nullptr) {
        return 0.0;
    }

    sum += root->data;
    count++;

    float leftSum = calculateAverage(root->left, sum, count);
    float rightSum = calculateAverage(root->right, sum, count);

    return root->data + leftSum + rightSum;
}



void bubbleSort(vector<int>& vec) {
    int n = vec.size();

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            // Если текущий элемент больше следующего, меняем их местами
            if (vec[j] > vec[j + 1]) {
                int temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}

int main() {

    setlocale(LC_ALL, "Russian");
    cout << "Введите количество вершин ";
    int n;
    cin >> n;


    vector <int>arr;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        arr.push_back(k);
    }








    TreeNode* root = createTree(arr, 0, n - 1);


    printTree(root);

    int choice = -1;
    int x;
    while (choice != 0)
    {
        cout << "1-Вывод высоты дерева" << endl;
        cout << "2-Вывод длины пути дерева" << endl;
        cout << "3-Вывод среднего арифметического всех чисел в дереве" << endl;
        cin >> choice;
        if (choice == 1)

            cout << "\nВысота дерева: " << getHeight(root) - 1 << endl;

        if (choice == 2)
        {


            cout << "Длина пути дерева: " << countEdges(root) << endl;
        }


        if (choice == 3)
        {
            int sum = 0, count = 0;
            float average = calculateAverage(root, sum, count) / count;
            cout << "Среднее арифметическое: " << average << endl;
        }
    }
    return 0;
}
