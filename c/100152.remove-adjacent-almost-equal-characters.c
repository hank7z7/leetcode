#include <bits/stdc++.h>

bool is_almost_equal(char a, char b)
{
	int equal = a - b;
	if (equal == 0 || equal == 1 || equal == -1)
		return true;
	else
		return false;
}

int removeAlmostEqualCharacters(char *word)
{
	int result = 0;
	int l = strlen(word);

	int prev = 0;
	for (int i = 0; i < l - 1; i++) {
		if (is_almost_equal(word[i], word[i + 1])) {
			// arr_almost_equal[i] = prev + 1;
			prev++;
		} else {
			result = result + ((prev + 1) / 2);
			prev = 0;
		}
	}

	result = result + ((prev + 1) / 2);
	return result;
}

int main(int argc, char **argv)
{
	int size = 0;

	// test 1
	char test1[] = "aaaaa";
	printf("%d\n", removeAlmostEqualCharacters(test1));

	// test 2
	char test2[] = "abddez";
	printf("%d\n", removeAlmostEqualCharacters(test2));

	// test 3
	char test3[] = "zyxyxyz";
	printf("%d\n", removeAlmostEqualCharacters(test3));

	return 0;
}
