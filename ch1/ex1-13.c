#include <stdio.h>

/* suppose the max length of words is less than MAX_WORD_LEN */

#define MAX_WORD_LEN 20
#define IN 					 1
#define OUT					 0

void draw_horizontal_histgram(int *word_len, int len_upper);
void draw_vertical_histgram(int *word_len, int len_upper);

int main()
{
	int c, cur_word_len, state, i;
	int word_len[MAX_WORD_LEN];

	state = OUT;
	cur_word_len = 0;
	for (i = 0; i < MAX_WORD_LEN; ++i) {
		word_len[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			state = OUT;
			if (cur_word_len > 0) {
				++word_len[cur_word_len-1];
				cur_word_len = 0;
			}
		} else if (state == OUT) {
			state = IN;
			cur_word_len = 1;
		} else if (state == IN) {
			++cur_word_len;
		}
	}

	for (i = 0; i < MAX_WORD_LEN; ++i) {
		printf("%d ", word_len[i]);
	}
	printf("\n");

	printf("\n****    Horizontal Histgram    ****\n");
	draw_horizontal_histgram(word_len, MAX_WORD_LEN);
	printf("\n****      Verical Histgram     ****\n");
	draw_vertical_histgram(word_len, MAX_WORD_LEN);

	return 0;
}

void draw_horizontal_histgram(int *word_len, int len_upper)
{
	int i, j;
	for (i = 0; i < len_upper; ++i) {
		printf("%3d - ", i+1);
		for (j = 0; j < word_len[i]; ++j) {
			printf("|");
		}
		printf("\n");
	}
}

void draw_vertical_histgram(int *word_len, int len_upper)
{
	int i, j, max_len;

	max_len = 0;
	for (i = 0; i < len_upper; ++i) {
		if (word_len[i] > max_len)
			max_len = word_len[i];
	}

	for (j = 0; j < max_len; ++j) {
		for (i = 0; i < len_upper; ++i) {
			if (j < max_len - word_len[i]) {
				printf("   ");
			} else {
				printf("-- ");
			}
		}
		printf("\n");
	}
	for (i = 0; i < len_upper; ++i) {
		printf("%2d ", i);
	}
	printf("\n");
}
