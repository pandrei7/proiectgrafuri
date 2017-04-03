#include "Algorithms.h"
#include "Graph.h"
#include "List.h"
#include "Queue.h"
#include "Util.h"
#include <stdlib.h>

ListNode* RetraceCycle(int *pred, float *costs, int nodes, int start)
{
    ListNode *list = NULL;
    char *visited = CreateString(nodes);

    int i;
    for (i = 0; i < nodes; ++i) {
        visited[i] = 0;
    }

    while (!visited[start]) {
        visited[start] = 1;
        AddToList(&list, start);
        start = pred[start];
    }
    return list;
}

ListNode* FindNegativeCycle(GraphNode *graph, int nodes, int start)
{
    float *costs = FloatVector(nodes, INFINITE);
    int *predecessors = IntVector(nodes, -1);
    int *times_relaxed = IntVector(nodes, 0);
    char has_negative_cycle = 0;

    Queue queue = (Queue){NULL, NULL};
    AddToQueue(&queue, start);
    costs[start] = 0;

    while (queue.left != NULL) {
        start = PopQueue(&queue);

        ++times_relaxed[start];
        if (times_relaxed[start] >= nodes) {
            has_negative_cycle = 1;
            break;
        }

        EdgeListNode *it = graph[start].edges;
        while (it != NULL) {
            int next = it->node;
            float new_cost = costs[start] + it->cost;

            if (Smaller(new_cost, costs[next])) {
                costs[next] = new_cost;
                predecessors[next] = start;
                AddToQueue(&queue, next);
            }
            it = it->next;
        }
    }

    EmptyQueue(&queue);

    if (!has_negative_cycle) {
        return NULL;
    }
    return RetraceCycle(predecessors, costs, nodes, start);
}