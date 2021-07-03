#include <stdio.h>

int main(void) {
	// In this case, this performs the exact same as a regular while loop.
	// However, this becomes a lot more interesting if you set i to 11 and
	// compile it.
	int i = 1;


	do {
		i++;
		printf("%d", i);
		printf("\n");
	} while (i < 10);

	return 0;
}
