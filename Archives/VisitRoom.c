#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ROOMS 100 // Assuming a maximum number of rooms

typedef struct {
    int rooms[MAX_ROOMS][MAX_ROOMS];
    int roomSizes[MAX_ROOMS];
    bool seen[MAX_ROOMS];
    int numRooms;
} Solution;

void initSolution(Solution *sol, int inputRooms[MAX_ROOMS][MAX_ROOMS], int inputRoomSizes[MAX_ROOMS], int numRooms) {
    sol->numRooms = numRooms;
    for (int i = 0; i < numRooms; i++) {
        sol->roomSizes[i] = inputRoomSizes[i];
        for (int j = 0; j < inputRoomSizes[i]; j++) {
            sol->rooms[i][j] = inputRooms[i][j];
        }
        sol->seen[i] = false;
    }
}

void dfs(Solution *sol, int node) {
    sol->seen[node] = true;
    for (int i = 0; i < sol->roomSizes[node]; i++) {
        int neighbor = sol->rooms[node][i];
        if (!sol->seen[neighbor]) {
            dfs(sol, neighbor);
        }
    }
}

bool canVisitAllRooms(Solution *sol) {
    dfs(sol, 0);
    for (int i = 0; i < sol->numRooms; i++) {
        if (!sol->seen[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    Solution sol;
    int rooms[MAX_ROOMS][MAX_ROOMS] = {{1}, {2}, {3}, {}};
    int roomSizes[MAX_ROOMS] = {1, 1, 1, 0};
    initSolution(&sol, rooms, roomSizes, 4);
    if (canVisitAllRooms(&sol)) {
        printf("Can visit all rooms.\n");
    } else {
        printf("Cannot visit all rooms.\n");
    }
    return 0;
}