#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rod_cutting(int length, int prices[], int lengths[], int n, int cuts[], int cuts_size); 

int main(int argc, char *argv[]) { // argc is number of arguments, argv array of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <supplied rod length>\n", argv[0]); // fprintf(stream, format, arguments) writes the C string pointed by format to the stream (AI), consult
        return 1;
    }

    int supplied_rod_length = atoi(argv[1]);
  
    int lengths[100];
    int prices[100];  // FIXME Explore dynamic memory later? malloc/realloc
    int n = 0;

    char line[256];

    // (AI): fgets returns a pointer to the buffer (line) if it successfully reads a line, or NULL if it encounters the end of the input or an error.
    printf("Enter lengths and prices separated by a comma (e.g. 1, 2):\n");
    printf("Windows: Ctrl + Z, Enter to finish. Mac: Ctrl + D to finish.\n");

    while (fgets(line, sizeof(line), stdin)) {
        if (sscanf(line, "%d, %d", &lengths[n], &prices[n]) != 2){ // Parse (?) the line and store values in length and price arrays
            break; 
        }
        n++;
    }

    int cuts[101]; // Declare cuts array; capped at 101; again, consider dynamic memory
    memset(cuts, 0, sizeof(cuts)); // (AI): memset is a function that fills a block of memory with a particular value. It is declared in string.h

    int max_profit = rod_cutting(supplied_rod_length, prices, lengths, n, cuts, 101);

    int remaining_length = supplied_rod_length;
    for (int i = 0; i < n; i++) {
        if (cuts[lengths[i]] > 0) {
            printf("\n");
            printf("%d @ %d = %d\n", cuts[lengths[i]], lengths[i], cuts[lengths[i]] * prices[i]); // (AI): Print the number of cuts, length, and total value
            remaining_length -= cuts[lengths[i]] * lengths[i];
        }
    }

    printf("Remainder: %d\n", remaining_length);

    printf("Value: %d\n", max_profit);
    return 0;
}



// rod_cutting function to calculate the maximum profit using dynamic programming (dp). Takes length, prices, lengths, n, cuts, and cuts_size as arguments, returns maximum profit. Can be optimized to take less arguments.
int rod_cutting(int length, int prices[], int lengths[], int n, int cuts[], int cuts_size) {
    int dp[length + 1], piece[length + 1];
    memset(dp, 0, sizeof(dp));
    memset(piece, 0, sizeof(piece));

    for (int i = 1; i <= length; i++) {
        for (int j = 0; j < n; j++) {
            if (lengths[j] <= i) {
                int new_profit = prices[j] + dp[i - lengths[j]];
                if (new_profit > dp[i]) {
                    dp[i] = new_profit; 
                    piece[i] = lengths[j];
                }
            }
        }
    } // Double for loop done; optimize?

    for (int temp_length = length; temp_length > 0; temp_length -= piece[temp_length]) {
        cuts[piece[temp_length]]++;
    }

    return dp[length];
}