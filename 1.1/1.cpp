#include <iostream>
#include <string>

using namespace std;


string reverse_string(const string& s) {
    if (s.empty()) {
        return "";
    }
    return s.back() + reverse_string(s.substr(0, s.size() - 1));
}

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* swap_pairs(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* new_head = head->next;
    head->next = swap_pairs(new_head->next);
    new_head->next = head;
    return new_head;
}

void print_list(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int climb_stairs(int n) {
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        return 0;
    }
    return climb_stairs(n - 1) + climb_stairs(n - 2);
}

double pow_recursive(double x, int n) {
    if (n == 0) {
        return 1.0;
    }
    if (n < 0) {
        return 1.0 / pow_recursive(x, -n);
    }
    return x * pow_recursive(x, n - 1);
}

int main()
{
    string s;
    int f, n;



    cout << "Task 1:\n" << "Input string - ";
    cin >> s;
    cout << reverse_string(s) << endl;



    cout << "\nTask 2:\n";
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    cout << "Original list: ";
    print_list(head);
    head = swap_pairs(head);
    cout << "Swapped list: ";
    print_list(head);
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }



    cout << "\nTask 3:\n";
    cout << "Input x for fibonacci - ";
    cin >> f;
    cout << fibonacci(f);



    cout << endl;
    cout << "\nTask 4:\n";
    cout << "Input n steps - ";
    cin >> n; 
    cout << climb_stairs(n);



    cout << endl;
    cout << "\nTask 5:\n";
    cout << "Input x - ";
    cin >> f;
    cout << "Input n - ";
    cin >> n;
    cout << pow_recursive(f, n);
    return 0;
}