 class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        
        // HINT 2: Start point par hi health kam ho sakti hai!
        int start_health = health - grid[0][0];
        
        // Agar pehle hi cell par health 0 ya negative ho gayi, toh aage jane ka fayda nahi
        if (start_health <= 0) {
            return false;
        }

        // HINT 3: Visited array ka upgrade. 
        // Yeh track karega ki kisi cell par hum maximum kitni health bacha kar pahuche hain.
        // Shuru mein sabko -1 set kar diya.
        vector<vector<int>> max_health(n, vector<int>(m, -1));
        max_health[0][0] = start_health;

        // 0-1 BFS ke liye hum 'deque' use karte hain jisme dono taraf se data push ho sakta hai
        // Data format: {row, col, current_health}
        deque<vector<int>> dq;
        dq.push_back({0, 0, start_health});
        
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!dq.empty()) {
            // Deque ke aage se current node nikalo
            auto curr = dq.front();
            dq.pop_front();
            
            int i = curr[0];
            int j = curr[1];
            int curr_h = curr[2];

            // Agar hum aakhiri cell par pahuch gaye aur health > 0 hai, toh rasta mil gaya!
            if (i == n - 1 && j == m - 1 && curr_h >= 1) {
                return true;
            }

            for (auto &d : dir) {
                int ni = i + d[0];
                int nj = j + d[1];

                // Boundary check
                if (ni >= 0 && nj >= 0 && ni < n && nj < m) {
                    
                    // HINT 1: Naye cell par jane ki keemat (toll) chukao
                    int new_health = curr_h - grid[ni][nj];
                    
                    // Hum naye cell par tabhi jayenge jab:
                    // 1. Hum zinda hon (new_health > 0)
                    // 2. Hum wahan pichli baar se ZYADA health le kar pahuch rahe hon
                    if (new_health > 0 && new_health > max_health[ni][nj]) {
                        
                        max_health[ni][nj] = new_health; // Nayi maximum health update karo
                        
                        // THE 0-1 BFS MAGIC:
                        // Agar raste ki cost 0 hai, toh usko High Priority (front) do
                        // Agar raste ki cost 1 hai, toh usko Normal Priority (back) do
                        if (grid[ni][nj] == 0) {
                            dq.push_front({ni, nj, new_health});
                        } else {
                            dq.push_back({ni, nj, new_health});
                        }
                    }
                }
            }
        }
        
        // Agar queue khali ho gayi aur aakhiri cell tak nahi pahuch paye
        return false;
    }
};