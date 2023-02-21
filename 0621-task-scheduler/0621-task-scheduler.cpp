class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<char> keys;
        unordered_map<char, pair<int, int>> dict;
        for (int i = 0; i < tasks.size(); i++) {
            if (dict.find(tasks[i]) != dict.end()) {
                dict[tasks[i]].first++;
            } else {
                keys.push_back(tasks[i]);
                dict[tasks[i]] = make_pair(1, 0);
            }
        }

        int cnt = tasks.size();
        int timer = 0;
        while(cnt > 0) {
            char candidate = '\0';
            int remained = 0;
            for (int i = 0; i < keys.size(); i++) {
                if (dict[keys[i]].first > 0 && dict[keys[i]].second == 0) {
                    if (dict[keys[i]].first > remained) {
                        candidate = keys[i];
                        remained = dict[candidate].first;
                    }
                    continue;
                }
                if (dict[keys[i]].second > 0) {
                    dict[keys[i]].second--;
                }
            }
            if (candidate != '\0') {
                dict[candidate].first--;
                dict[candidate].second = n;
                cnt--;
            }
            timer++;
        }
        return timer;
    }
};