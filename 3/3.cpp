#include <iostream>
#include <stack>
#include <queue>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode dummy;
    ListNode* tail = &dummy;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        }
        else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    tail->next = list1 ? list1 : list2;
    return dummy.next;
}

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* current = head;

    while (current && current->next) {
        if (current->val == current->next->val) {
            current->next = current->next->next;
        }
        else {
            current = current->next;
        }
    }

    return head;
}

bool hasCycle(ListNode* head) {
    ListNode* slow = head, * fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }

    return false;
}

void reorderList(ListNode* head) {
    if (!head || !head->next) return;

    ListNode* slow = head, * fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* prev = nullptr;
    ListNode* curr = slow->next;
    slow->next = nullptr;

    while (curr) {
        ListNode* next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }

    ListNode* first = head;
    ListNode* second = prev;

    while (second) {
        ListNode* temp1 = first->next;
        ListNode* temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
    }
}

void deleteNode(ListNode* node) {
    node->val = node->next->val;
    node->next = node->next->next;
}

ListNode* doubleList(ListNode* head) {
    std::stack<int> s;
    ListNode* current = head;

    while (current) {
        s.push(current->val);
        current = current->next;
    }

    int carry = 0;
    ListNode* newHead = nullptr;

    while (!s.empty() || carry) {
        int sum = (s.empty() ? 0 : s.top()) * 2 + carry;
        if (!s.empty()) s.pop();

        carry = sum / 10;
        ListNode* newNode = new ListNode(sum % 10);
        newNode->next = newHead;
        newHead = newNode;
    }

    return newHead;
}

struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    std::priority_queue<ListNode*, std::vector<ListNode*>, Compare> pq;

    for (auto list : lists) {
        if (list) pq.push(list);
    }

    ListNode dummy;
    ListNode* tail = &dummy;

    while (!pq.empty()) {
        ListNode* node = pq.top();
        pq.pop();
        tail->next = node;
        tail = tail->next;

        if (node->next) {
            pq.push(node->next);
        }
    }

    return dummy.next;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    auto reverse = [](ListNode* start, ListNode* end) {
        ListNode* prev = nullptr;
        ListNode* curr = start;

        while (curr != end) {
            ListNode* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }

        return prev;
        };

    ListNode dummy(0, head);
    ListNode* prev = &dummy;
    ListNode* end = head;

    while (end) {
        for (int i = 0; i < k; ++i) {
            if (!end) return dummy.next;
            end = end->next;
        }

        ListNode* start = prev->next;
        prev->next = reverse(start, end);
        start->next = end;
        prev = start;
    }

    return dummy.next;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    auto reverse = [](ListNode* start, ListNode* end) {
        ListNode* prev = nullptr;
        ListNode* curr = start;

        while (curr != end) {
            ListNode* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
        }

        return prev;
        };

    ListNode dummy(0, head);
    ListNode* prev = &dummy;
    ListNode* end = head;

    while (end) {
        for (int i = 0; i < k; ++i) {
            if (!end) return dummy.next;
            end = end->next;
        }

        ListNode* start = prev->next;
        prev->next = reverse(start, end);
        start->next = end;
        prev = start;
    }

    return dummy.next;
}

ListNode* partition(ListNode* head, int x) {
    ListNode before(0), after(0);
    ListNode* beforeTail = &before, * afterTail = &after;

    while (head) {
        if (head->val < x) {
            beforeTail->next = head;
            beforeTail = beforeTail->next;
        }
        else {
            afterTail->next = head;
            afterTail = afterTail->next;
        }
        head = head->next;
    }

    afterTail->next = nullptr;
    beforeTail->next = after.next;

    return before.next;
}

int main()
{
    std::cout << "Hello World!\n";
}