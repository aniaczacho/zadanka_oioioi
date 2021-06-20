#include <stdio.h>
#include <stdlib.h>

struct element { int in1, in2, out, calced; };

void calc_gate(struct element *net, int i, int n) {
    int in1, in2;
    in1 = net[i].in1;
    in2 = net[i].in2;
    if (net[in1].calced == 0) calc_gate(net, in1, n);
    if (net[in2].calced == 0) calc_gate(net, in2, n);
    net[i].out = ((net[in1].out + net[in2].out) % 2);
    net[i].calced = 1;
}

int not_same(const int *data, const int *lim, int n) {
    for (int i = 0; i < n; i++) {
        if (data[i] != lim[i]) return 1;
    }
    return 0;
}

void next_data(int *data, int n) {
    data[n - 1]++;
    for (int i = n - 1; i >= 0; i--) {
        if (data[i] == 2) {
            data[i] = 0;
            data[i - 1]++;
        }
    }
}

int xor(int a, int b) {
    return ((a + b) % 2);
}

int output(const int *a, const int *data, int n) {
    int res = xor(a[0] * data[0], a[1] * data[1]);
    for (int i = 2; i < n; i++) res = xor(res, a[i] * data[i]);
    return res;
}

int main() {

    int n, m, gate_out;
    scanf("%d%d%d", &n, &m, &gate_out);
    gate_out += n - 1;

    struct element net[m + n];
    for (int i = n; i < m + n; i++) scanf("%d %d", &net[i].in1, &net[i].in2);
    for (int i = n; i < m + n; i++) {
        if (net[i].in1 < 0) net[i].in1 = abs(net[i].in1) - 1;
        else net[i].in1 += n - 1;
        if (net[i].in2 < 0) net[i].in2 = abs(net[i].in2) - 1;
        else net[i].in2 += n - 1;
    }

    char sdata[n + 1];
    scanf("%s", &sdata);
    char slim[n + 1];
    scanf("%s", &slim);

    int data[n];
    int lim[n];
    for (int i = 0; i < n; i++) {
        data[i] = (int) (sdata[i] - 48);
        lim[i] = (int) (slim[i] - 48);
    }

    int a[n];
    for (int i = n - 1; i >= 0; i--) {

        for (int j = 0; j < n; j++) {
            net[j].out = 0;
            net[j].calced = 1;
        }
        net[i].out = 1;
        for (int j = n; j < m + n; j++) net[j].calced = 0;

        calc_gate(net, gate_out, n);
        a[i] = net[gate_out].out;
    }

    int ones = output(a, data, n);
    while (not_same(data, lim, n)) {
        next_data(data, n);
        ones += output(a, data, n);
    }

    printf("%d", ones);
    return 0;
}