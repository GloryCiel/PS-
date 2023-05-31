#include <iostream>

using namespace std;

void DFS(int x, int y, int** farm, bool** visited, int M, int N)
{
    visited[y][x] = true;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < M && ny >= 0 && ny < N)
        {
            if (farm[ny][nx] == 1 && !visited[ny][nx])
            {
                DFS(nx, ny, farm, visited, M, N);
            }
        }
    }
}

int main()
{
    int T;cin >> T;

    while (T--) {
        int M, N, K;
        cin >> M >> N >> K;

        int **farm = new int *[N];
        for (int i = 0; i < N; ++i) {
            farm[i] = new int[M]();
        }

        bool **visited = new bool *[N];
        for (int i = 0; i < N; ++i) {
            visited[i] = new bool[M]();
        }

        for (int i = 0; i < K; ++i) {
            int X, Y;
            cin >> X >> Y;
            farm[Y][X] = 1;
        }

        int count = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (farm[i][j] == 1 && !visited[i][j]) {
                    DFS(j, i, farm, visited, M, N);
                    count++;
                }
            }
        }
        cout << count << endl;
    }
}