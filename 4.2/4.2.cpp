#include <iostream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

int firstUniqChar(string s) {
    unordered_map<char, int> count;
    for (char c : s)
        count[c]++;
    for (int i = 0; i < s.size(); i++)
        if (count[s[i]] == 1)
            return i;
    return -1;
}

//

class MyStack {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        int top = q1.front();
        q1.pop();
        return top;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

//

class RecentCounter {
    queue<int> q;
public:
    RecentCounter() {}

    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }
};

//

class MyCircularDeque {
    vector<int> deque;
    int front, rear, size, capacity;
public:
    MyCircularDeque(int k) : deque(k, 0), front(0), rear(k - 1), size(0), capacity(k) {}

    bool insertFront(int value) {
        if (isFull()) return false;
        front = (front - 1 + capacity) % capacity;
        deque[front] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull()) return false;
        rear = (rear + 1) % capacity;
        deque[rear] = value;
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) return false;
        rear = (rear - 1 + capacity) % capacity;
        size--;
        return true;
    }

    int getFront() {
        return isEmpty() ? -1 : deque[front];
    }

    int getRear() {
        return isEmpty() ? -1 : deque[rear];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

//

vector<int> movesToStamp(string stamp, string target) {
    int m = stamp.size(), n = target.size();
    vector<int> res;
    bool visited[n] = {};
    int stars = 0;

    while (stars < n) {
        bool doneReplace = false;
        for (int i = 0; i <= n - m; ++i) {
            if (!visited[i] && canReplace(target, i, stamp)) {
                stars = replace(target, i, m, stars);
                visited[i] = true;
                doneReplace = true;
                res.push_back(i);
                if (stars == n) break;
            }
        }
        if (!doneReplace) return {};
    }

    reverse(res.begin(), res.end());
    return res;
}

bool canReplace(string& target, int pos, string& stamp) {
    for (int i = 0; i < stamp.size(); ++i) {
        if (target[pos + i] != '?' && target[pos + i] != stamp[i])
            return false;
    }
    return true;
}

int replace(string& target, int pos, int len, int count) {
    for (int i = 0; i < len; ++i) {
        if (target[pos + i] != '?') {
            target[pos + i] = '?';
            count++;
        }
    }
    return count;
}

//

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1)
            res.push_back(nums[dq.front()]);
    }
    return res;
}

//

int constrainedSubsetSum(vector<int>& nums, int k) {
    deque<int> dq;
    int maxSum = nums[0];
    for (int i = 0; i < nums.size(); ++i) {
        nums[i] += dq.empty() ? 0 : max(0, nums[dq.front()]);
        maxSum = max(maxSum, nums[i]);
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();
        dq.push_back(i);
        if (dq.front() == i - k)
            dq.pop_front();
    }
    return maxSum;
}


int main()
{
    return 0;
}