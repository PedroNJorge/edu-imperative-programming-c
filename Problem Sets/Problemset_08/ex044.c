#include <stdio.h>
#include <stdbool.h>

typedef struct velocity {
    int x;
    int y;
} Velocity;

typedef struct position {
    int x;
    int y;
} Position;

void add_vel_to_pos(Velocity* vel, Position* pos);
void sub_vel_to_pos(Velocity* vel, Position* pos);
bool pos_out(int n, int m, Position* pos, Velocity* vel);

int main() {
    int n, m, x, y, k;
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);

    Position pos = {x, y};
    /* Velocity vel = {1, 1};

    for (int i = 0; i < k; i++) {
        add_vel_to_pos(&vel, &pos);
        if (pos_out(n, m, &pos, &vel)) {
            add_vel_to_pos(&vel, &pos);
        }
    }
    */
    if (k < n) pos.x = (pos.x + k) % n;
    else if ((k / n) % 2 == 0) pos.x = (pos.x + (k % n) + 1) % n;
    else pos.x = (pos.x - (k % n) - 1) % n;
    
    if (k < m) pos.y = (pos.y + k) % m;
    else if ((k / m) % 2 == 0) pos.y = (pos.y + (k % m) + 1) % m;
    else pos.y = (pos.y - (k % m) - 1) % m;

    if (pos.x == 0) pos.x = n;
    else if (k < n) pos.x++;
    if (pos.y == 0) pos.y = m;
    else if (k < m) pos.y++;
    printf("%d %d\n", pos.x, pos.y);

    return 0;
}

void add_vel_to_pos(Velocity* vel, Position* pos) {
    pos->x += vel->x;
    pos->y += vel->y;
}

void sub_vel_to_pos(Velocity* vel, Position* pos) {
    pos->x -= vel->x;
    pos->y -= vel->y;
}

bool pos_out(int n, int m, Position* pos, Velocity* vel) {
    bool out = false;
    int x = pos->x, y = pos->y;
    if (x < 0 || x > n){
        out = true;
        sub_vel_to_pos(vel, pos);
        vel->x *= -1;
    }
    if (y < 0 || y > m) {
        if (!out) {
            out = true;
            sub_vel_to_pos(vel, pos);
        }
        vel->y *= -1;
    }
    return out;
}
