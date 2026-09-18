// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (isBadVersion(mid)) {
                // mid is bad, so first bad is at mid or before it
                right = mid;
            } else {
                // mid is good, so first bad is after mid
                left = mid + 1;
            }
        }

        return left;
    }
};
