#include <stdio.h>
#include <string.h>

int countKeyChanges(char* s)
{
    int l      = strlen(s);
    int result = 0;
    if (l == 1)
        return 0;
    char prev = s[0];
    if ((prev >= 'A') && (prev <= 'Z'))
        prev = prev - ('A' - 'a');
    char curr = s[0];
    for (int i = 1; i < l; i++)
    {
        curr = s[i];
        if ((curr >= 'A') && (curr <= 'Z'))
            curr = curr - ('A' - 'a');
        if (curr != prev)
            result++;
        prev = curr;
    }
    return result;
}

int main(int argc, char** argv)
{
    // Test 1
    char* test_1 = "aAbBcC";
    printf("%d\n", countKeyChanges(test_1));

    // Test 2
    char* test_2 = "AaAaAaaA";
    printf("%d\n", countKeyChanges(test_2));
    return 0;
}