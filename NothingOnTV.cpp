#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

struct Pub {
    int id;
    int x;
    int y;
    double angle;
};

bool isnear(Pub a, Pub b) {
        double center_x = a.x / 2.0;
        double center_y = a.y / 2.0;
        double radius = sqrt(center_x * center_x + center_y * center_y);
        double distance = sqrt(pow(b.x - center_x, 2) + pow(b.y - center_y, 2));
        return distance <= radius; 
}

int main() {
    int n;
    cin >> n;
    vector<Pub> pubs;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pubs.push_back({i + 1, x, y, atan2(y, x)});
    }

    sort(pubs.begin(), pubs.end(), [](Pub p1, Pub p2) {
        return p1.x * p1.x + p1.y * p1.y < p2.x * p2.x + p2.y * p2.y;

    });
    auto comparer = [](Pub p1, Pub p2) {
        return p1.angle < p2.angle;
    };
    set<Pub, decltype(comparer)> good_pubs(comparer);
    good_pubs.insert(pubs[0]);
    for (int i = 1; i < n; i++) {
        if (good_pubs.size() == 1 && !isnear(pubs[i], *good_pubs.begin())) {
            good_pubs.insert(pubs[i]);
            continue;
        }
        pair<set<Pub>::iterator, bool> ret = good_pubs.insert(pubs[i]);
        if (ret.second == false) {
            continue;
        }
        set<Pub>::iterator it, left, right;
        it = left = right = ret.first;

        // If left at beginning loop around to end.
        if (left == good_pubs.begin()) {
            left = good_pubs.end();
        }
        --left, ++right;

        // If right at end loop around to beginning.
        if (right == good_pubs.end()) {
            right = good_pubs.begin();
        }

        // If left or right Pub is close, erase added Pub.
        // If neither left or right pub is close, not other Pub can be either.
        if (isnear(pubs[i], *left) || isnear(pubs[i], *right)) {
            good_pubs.erase(it);
        }
    }
    vector<Pub> good_pubs2(good_pubs.begin(), good_pubs.end());


    cout << good_pubs2.size() << endl;
    sort(good_pubs2.begin(), good_pubs2.end(), [](Pub p1, Pub p2) {
        return p1.id < p2.id;
    });
    for (Pub p : good_pubs2) {
        cout << p.id << " ";
    }
    cout << endl;

    return 0;
}
