void towerOfHanoi(int n, char src, char dest, char aux)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from peg %c to peg %c", src, dest);
        return;
    }
    towerOfHanoi(n-1, src, aux, dest);
    printf("\n Move disk %d from peg %c to peg %c", n, src, dest);
    towerOfHanoi(n-1, aux, dest, src);
}

int main()
{
    int n = 4; // Number of disks
    towerOfHanoi(n, 'A', 'C', 'B');  // A, B and C are names of rods
    return 0;
}
