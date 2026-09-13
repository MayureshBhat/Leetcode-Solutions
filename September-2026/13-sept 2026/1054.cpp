class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> freq;

        for (int x : barcodes) {
            freq[x]++;
        }

        // Sort by frequency
        vector<pair<int, int>> v;
        for (auto p : freq) {
            v.push_back({p.second, p.first});
        }

        sort(v.rbegin(), v.rend());

        vector<int> ans(barcodes.size());
        int pos = 0;

        for (auto p : v) {
            int count = p.first;
            int value = p.second;

            while (count--) {
                ans[pos] = value;

                pos += 2;

                // Move to odd positions after even positions are filled
                if (pos >= barcodes.size()) {
                    pos = 1;
                }
            }
        }

        return ans;
    }
};
