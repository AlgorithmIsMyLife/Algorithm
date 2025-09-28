#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> dials, vector<int> password)
{
    int n = dials.size();
    long long total_moves = 0;
    int cumulative_rotation = 0;
    for (int i = 0; i < n; ++i)
    {
        int current = (dials[i] + cumulative_rotation) % 10;
        if (current < 0)
            current += 10;
        int desired = password[i];
        int delta = (desired - current + 10) % 10;
        int delta_down = delta - 10;
        int delta_chosen;
        if (abs(delta) <= abs(delta_down))
            delta_chosen = delta;
        else
            delta_chosen = delta_down;
        cumulative_rotation += delta_chosen;
        total_moves += abs(delta_chosen);
    }
    return total_moves;
}
