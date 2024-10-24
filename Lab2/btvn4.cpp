#include <bits/stdc++.h>

using namespace std;

class Matrix {
public:
    int m; 
    vector<vector<int>> originalMatrix;
public:
    Matrix(const vector<vector<int>>& matrix) : m(matrix.size()), originalMatrix(matrix) {}
    Matrix(int _size = 1) : m(_size), originalMatrix(vector<vector<int>>(_size, vector<int>(_size, 0))) {}
    // Ham xac dinh chu ki k 
    int findCycleLength() {
        vector<vector<int>> matrix(m, vector<int>(m, 0));

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < m; ++j) 
                matrix[i][j] = originalMatrix[i][j];

        int cycleLength = 0;

        do {
            matrix = applyCatMap(matrix);
            cycleLength++;
        } while (!checkVectorEqual(matrix, originalMatrix));

        return cycleLength;
    }

     // Ham thuc hien phep bien doi
    vector<vector<int>> applyCatMap(const vector<vector<int>>& matrix)
    {
        vector<vector<int>> transformedMatrix(m, vector<int>(m, 0));
        for (int i = 0; i < m; ++i) 
        {
            for (int j = 0; j < m; ++j) 
            {
                int x = (2 * i + j) % m;
                int y = (i + j) % m;
                transformedMatrix[x][y] = matrix[i][j];
            }
        }

        
        return transformedMatrix;
    }

    // Dinh nghia >> 
    friend istream& operator>>(istream& inp, Matrix& u)
    {
        inp >> u.m;
        u.originalMatrix.resize(u.m, vector<int>(u.m));
        
        for (int i = 0; i < u.m; ++i) 
            for (int j = 0; j < u.m; ++j)
                inp >> u.originalMatrix[i][j];

        return inp;
    }

    // Kiem tra 2 vector bang nhau
    bool checkVectorEqual(const vector<vector<int>>& u, const vector<vector<int>> & v) const
    {
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < m; ++j)
                if (u[i][j] != v[i][j]) return false;
        return true;
    }
};


int main()
{
    Matrix a;

    cin >> a;

    cout << a.findCycleLength();
    return 0;
}
