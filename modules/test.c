#include "lists.h"

int main() {
    Node * list1 = create_list(0.0f);
    for (int i = 1; i <= 10; i++) {
        add_node(list1, i);
    }
    print_list(list1);
    delete_pos(list1, 1);
    print_list(list1);
    free_list(list1);
    print_list(list1);
}