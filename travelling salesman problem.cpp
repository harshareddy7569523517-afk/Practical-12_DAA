#include <iostream>
using namespace std;

int main()
{
    int n;
    int cost[10][10];
    int visited[10] = {0};
    int totalCost = 0;
    int current = 0;

    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    visited[0] = 1;

    cout << "\nPath: 1";

    for (int count = 1; count < n; count++)
    {
        int minCost = 99999;
        int nextCity = -1;

        for (int j = 0; j < n; j++)
        {
            if (!visited[j] && cost[current][j] < minCost)
            {
                minCost = cost[current][j];
                nextCity = j;
            }
        }

        visited[nextCity] = 1;
        totalCost += minCost;
        current = nextCity;

        cout << " -> " << current + 1;
    }

    totalCost += cost[current][0];

    cout << " -> 1";
    cout << "\nMinimum cost: " << totalCost;

    return 0;
}
