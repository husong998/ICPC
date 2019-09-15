# include <bits/stdc++.h>

using namespace std;

int get_cell_count(int r) {
    int num_cells = 0;
    for (int i = r; i < 2 * r; i++) {
        num_cells += i;
    }

    for (int i = 2 * r - 2; i >= r; i--) {
        num_cells += i;
    }
    return num_cells;
}
int main()
{
    int r, k; scanf("%d%d", &r, &k);
    vector<int> orange(k);
    for (int i = 0; i < k; i++) scanf("%d", &orange[i]);
    if (r == 1) {
        printf("6\n");
        return 0;
    }

    int num_cells = get_cell_count(r);
    vector<bool> is_home(num_cells + 1, false);
    for (int i = 0; i < k; i++) {
        is_home[orange[i]] = true;
    }
    vector< vector<int> > AL (num_cells + 1);
    vector<int> borders (num_cells + 1, 0);
    // top borders
    for (int i = 1; i <= r; i++) {
        borders[i] = 2;
    }
    borders[1] = 3;
    borders[r] = 3;

    for (int i = num_cells; i > num_cells - r; i--) {
        borders[i] = 2;
    }
    borders[num_cells] = 3;
    borders[num_cells - r + 1] = 3;

    int curr_cell = 1;

    for (int i = r; i < 2 * r - 1; i++) {
        int start_cell = curr_cell;
        int next_start_cell = curr_cell + i;
        if (i != r) {
            borders[start_cell] = 2;
            borders[next_start_cell - 1] = 2;
        }
        for (int curr = start_cell; curr < next_start_cell; curr++) {
            AL[curr].push_back(curr + i);
            AL[curr + i].push_back(curr);
            AL[curr].push_back(curr + i + 1);
            AL[curr + i + 1].push_back(curr);
            if (curr != next_start_cell - 1) {
                AL[curr].push_back(curr + 1);
                AL[curr + 1].push_back(curr);
            }
        }
        curr_cell = next_start_cell;
    }
    borders[curr_cell] = 3;
    borders[curr_cell + 2 * r - 2] = 3;

    for (int i = 2 * r - 1; i >= r; i--) {
        int start_cell = curr_cell;
        int next_start_cell = curr_cell + i;
        if (i != r && i != r * 2 - 1) {
            borders[start_cell] = 2;
            borders[next_start_cell - 1] = 2;
        }

        for (int curr = start_cell; curr < next_start_cell; curr++) {
            if (curr != next_start_cell - 1) {
                AL[curr].push_back(curr + 1);
                AL[curr + 1].push_back(curr);
            }
            if (i == r) continue;
            if (curr != start_cell) {
                AL[curr].push_back(curr + i - 1);
                AL[curr + i - 1].push_back(curr);
            }
            if (curr != next_start_cell - 1) {
                AL[curr].push_back(curr + i);
                AL[curr + i].push_back(curr);
            }
        }
        curr_cell = next_start_cell;
    }

    vector<bool> visited(num_cells + 1, false);
    vector<bool> bad_cells(num_cells + 1, false);

    for (int i = 1; i <= num_cells; i++) {
        if (visited[i]) continue;
        if (is_home[i]) continue;
        vector<int> cells;
        queue<int> q;
        q.push(i);
        visited[i] = true;
        bool hit_border = false;
        while(!q.empty()) {
            int u = q.front();
            cells.push_back(u);
            if (borders[u]) hit_border = true;
            q.pop();
            for(int v: AL[u]) {
                if (visited[v]) continue;
                if (is_home[v]) continue;
                visited[v] = true;
                q.push(v);
            }
        }
        if (!hit_border) {
            for (int cell: cells) bad_cells[cell] = true;
        }
    }
    /*
    for (int i = 0; i < bad_cells.size(); i++) {
        if (bad_cells[i])  printf("bad_cells = %d\n", i);
    }

    for (int i = 0; i < AL.size(); i++) {
        printf("AL[%d]: ", i);
        for (int j = 0; j < AL[i].size(); j++) {
            printf("%d, ", AL[i][j]);
        }
        printf("\n");
    }
    */


    int count = 0;
    for (int i = 1; i <= num_cells; i++) {
        if (!is_home[i]) {
            continue;
        }
        count += 6;
        for (int u: AL[i])
            if (is_home[u] || bad_cells[u]) count--;
    }
    printf("%d\n", count);

}