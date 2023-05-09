#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;           // 데이터
    struct node* link;  // 다음 노드를 가리키는 포인터
} Node;

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    Node* head = NULL;  // 링크드 리스트의 헤드 포인터

    // 링크드 리스트 노드 생성
    for (int i = n ; i >= 1; i--) {
        Node* newNode = (Node*)malloc(sizeof(Node));  // 새로운 노드 생성
        newNode->data = i;                            // 노드의 데이터는 인덱스 값으로 지정
        newNode->link = head;                         // 새로운 노드의 link는 이전 노드를 가리킴
        head = newNode;                               // 헤드 포인터는 새로운 노드를 가리킴
    }

    // 링크드 리스트 출력
    printf("List: ");
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->link;
    }
    printf("\n");

    return 0;
}