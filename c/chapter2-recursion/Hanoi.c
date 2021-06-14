#include <stdio.h>

// A B C

/*

1) n = 3
2개를 B에 놓고 나머지 1개를 C에 놓는다.
B에 있는 2개를 C에 놓는다.

2) n = 4
3개를 B에 놓고 나머지 1개를 C에 놓는다.
B에 있는 3개를 C에 놓는다.

3) n = i
i-1개를 B에 놓고 나머지 1개를 C에 놓는다.
B에 있는 i-1개를 C에 놓는다.

4) n = 1
0개를 B에 놓고 나머지 1개를 C에 놓는다. 

5) n = 2
1개를 B에 놓고 나머지 1개를 C에 놓는다.
B에 있는 1개를 C에 놓는다.

*/

// from에서 by를 거쳐 to에 놓는다.
void hanoi_move(int i, char from, char by, char to)
{
    if (i == 1)
    {
        printf("%d : %c -> %c\n", i, from, to);
    }
    else
    {
        hanoi_move(i - 1, from, to, by);        // i-1개를 B에 놓는다.
        printf("%d : %c -> %c\n", i, from, to); // 나머지 1개를 C에 놓는다.
        hanoi_move(i - 1, by, from, to);        // i-1개를 C로 놓는다.
    }
}

int main()
{
    int n;
    printf("n >>> ");
    scanf_s("%d", &n);

    hanoi_move(n, 'A', 'B', 'C');

    return 0;
}