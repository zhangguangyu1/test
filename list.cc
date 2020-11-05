#include <iostream>

class ListNode {
public:
    int value;
    ListNode* next;

    ListNode(int i) : value(i), next(nullptr) {}
};

ListNode* PartReverse(ListNode* head, int left, int right)
{
    // 1
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    // 2
    ListNode* p0 = head;
    ListNode* p1 = head->next;

    if (p1->next == nullptr)
    {
        p1->next = head;
        p0 = nullptr;

        return p0;
    }   

    ListNode* p2 = p1->next;

    int i = 1;

    ListNode* i1 = nullptr;
    ListNode* i2 = nullptr;
    while (true)
    {
        if (i >= left && i < right)
        {
            if (i1 == nullptr)
            {
                i1 = p0;
                i2 = p1;
            }

            auto tmp = p2;

            p2=p2->next;
            p0 = p1;

            tmp->next = p1;
            p1= tmp;
        }
		
		if (i == right)
		{
			break;
		}
		++i;
    }

    i1->next = p1;
    i2->next = p2;

    return head;
}

void ShowList(ListNode* head)
{
    if (head == nullptr)
    {
        std::cout << "nullptr" << std::endl;
    }

    while (head != nullptr)
    {
        std::cout << head->value << " ";
        head = head->next;
    }

    std::cout << std::endl;
}

int main() {
    ListNode* head = nullptr;

    ListNode* t;
    for (int i = 1; i < 8; ++i)
    {
        ListNode* tmp = new ListNode(i);

        if (head == nullptr)
        {
            head = tmp;
            t = head;
        }
        else
        {
            t->next = tmp;
            t= t->next;
        }
    }

    ShowList(head);

    PartReverse(head, 1, 3);
    ShowList(head);

    return 0;

}
