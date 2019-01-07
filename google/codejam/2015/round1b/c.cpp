#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define ll long long int

using namespace std;

int n;
ll d[1005], h[1005], m[1005];

struct Event {
  double time;
  double speed;

  Event(double t, double s) {
    time = t;
    speed = s;
  }
};

class CompareDist {
public:
  bool operator()(Event e1, Event e2) {
    return e1.time > e2.time || (e1.time == e2.time && e2.time > e2.speed);
  }
};

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> n;
    int h_count = 0;
    for (int i = 0; i < n; i++) {
      cin >> d[i] >> h[i] >> m[i];
      h_count += h[i];
    }
    priority_queue<Event, vector<Event>, CompareDist > time_speed;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < h[i]; j++) {
	double t1 = (360.0 - d[i]) / (360.0 / (m[i] + j));
	time_speed.push(Event(t1, m[i] + j));
      }
    }
    int count = 0;
    int enc = h_count;
    int end = 2 * h_count;
    int ans = h_count;
    while (count <= 2 * end) {
      Event e = time_speed.top();
      time_speed.pop();
      if (e.time < e.speed) {
	h_count--;
      }
      else {
	h_count++;
      }
      ans = min(h_count, ans);
      time_speed.push(Event(e.time + e.speed, e.speed));
      count++;
    }
    cout << "Case #" << t << ": " << ans << endl;
  }
}
