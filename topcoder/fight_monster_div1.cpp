#include <iostream>
#include <algorithm>

using namespace std;

class FightMonsterDiv1 {

    long long attack;
    long long level;
    long long duration;
    long long hp;

public:

    long long points_until(long long t) {
        return attack * t + (level * attack / 100) * (t * (t - 1) / 2);
    }

    bool check(long long t) {
        long long part1 = points_until(t - 1);
        if (part1 < 0) return true;
        long long start = max(0LL, t - duration - 1);
        long long part2 = 4 * (part1 - points_until(start));
        return (part1 + part2) < 0 || (part1 + part2) >= hp;
    }

    long long fightTime(long long hp, long long attack, int level, long long duration) {
        if (attack >= hp) return 1;
        this->attack = attack;
        this->level = level;
        this->duration = duration;
        this->hp = hp;
        long long left = 2;
        long long right = hp / attack + 1;

        while (left < right) {
            long long mid = (left + right) / 2;
            if (check(mid)) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return right;
    }
};

int main() {
    FightMonsterDiv1 sol;
    cout << sol.fightTime(999999251054, 7800, 22, 330) << endl;
}