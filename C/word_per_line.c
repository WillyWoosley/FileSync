#include <stdio.h>

int main() {
	
	int c, last;

	while ((c = getchar()) != EOF || c != '`') {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (last != ' ' && last != '\n' && last != '\t') {
				printf("\n");
			}
		} else {
			putchar(c);
		}

		last = c;
	}
	
	return 0;
}

