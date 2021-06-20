#include <stdio.h>

int exists(int board[10081], int len) {
    for (int i = 0; i < len; i++) {
        if (board[i] >= 3) return 1;
    }
    return 0;
}

int isnt_done(int board[10081], int len) {
    for (int i = 0; i < len - 1; i++) {
        if (board[i] > 1) return 1;
        if (board[i] == 1 && board[i + 1] == 1) return 1;
    }
    return 0;
}
int main() {

    int n;
    scanf("%d", &n);

    int pawns[10001];
    for (int i = 0; i <= 1000; i++) pawns[i] = 0;
    int p;
    for (int i = 0; i < n; i++) {
        scanf("%d", &p);
        scanf("%d", &pawns[p]);
    }

    int max_ = 0;
    for (int i = 0; i <= p; i++) {
        if (pawns[i] > max_) max_ = pawns[i];
    }
    int l = 40;
    int len = p + (2 * l) + 1;
    int board[10081];
    for (int i = 0; i < l; i++) board[i] = 0;
    for (int i = l; i <= p + l; i++) board[i] = pawns[i - l];
    for (int i = p + l + 1; i < len; i++) board[i] = 0;
    //for (int i = 0; i < len; i++) printf("%d ", board[i]);

    while (exists(board, len)) {
        for (int i = 0; i < len; i++) {
            if (board[i] >= 3) {
                board[i + 2] += board[i] / 3;
                board[i - 2] += board[i] / 3;
                board[i] = board[i] % 3;
            }
        }
    }
    //for (int i = 0; i < len; i++) printf("%d ", board[i]);

    int idx;
    for (int i = len - 1; i >= 0; i--) {
        if (board[i]) {
            idx = i - 1;
            break;
        }
    }

    while (isnt_done(board, len)) {

        if (board[idx] > 0 && board[idx + 1] > 0) {
            board[idx]--;
            board[idx + 1]--;
            board[idx + 2]++;
            idx += 2;
            continue;
        }

        if (board[idx] == 2 &&  board[idx - 1] > 0) {
            idx -= 1;
            continue;
        }

        if (board[idx] == 2 && board[idx + 1] == 0) {
            board[idx] -= 2;
            board[idx + 1]++;
            board[idx - 2]++;
            idx++;
            continue;
        }

        if (board[idx] == 3) {
            board[idx] = 0;
            board[idx + 2]++;
            board[idx - 2]++;
            idx += 2;
            continue;
        }

        int jdx = 0;
        for (int i = 0; i < len; i++) {
            if (board[i] > 0) {
                jdx = i;
                break;
            }
        }

        if (idx == jdx) {
            for (int i = 0; i < len; i++) {
                if (board[i]) printf("%d ", i - l);
            }
            return 0;
        }

        else {
            for (int i = idx - 1; i >= 0; i--) {
                if (board[i]) {
                    idx = i;
                    break;
                }
            }
            continue;
        }
    }

    for (int i = 0; i < len; i++) {
        if (board[i]) printf("%d ", i - l);
    }

    return 0;
}