
class TreeAncestor {
public:
    int p = 1;
    vector<vector<int>> parents;

    TreeAncestor(int n, vector<int>& parent) {
        p = n;
        parents.assign(n, vector<int>(20, -1));

        for(int i = 0; i < n; i++) {
            parents[i][0] = parent[i];
        }

        for(int j = 1; j < 20; j++) {
            for(int i = 0; i < n; i++) {
                int mid = parents[i][j - 1];

                if(mid == -1) {
                    parents[i][j] = -1;
                } else {
                    parents[i][j] = parents[mid][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        int step = 0;

        while(k > 0 && node != -1) {
            if(k % 2 == 1) {
                node = parents[node][step];
            }

            k = k / 2;
            step++;
        }

        return node;
    }
};
