#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct comp
{
    int pair_comp;
    bool found;

} comp;

bool found_pair_with_sum(int arr[], int length, int sum, int highest_num);

int main(void)
{
    int arr1[] = {1, 2, 3, 9, 7};
    int arr2[] = {1, 2, 4, 4};

    int highest_num = 0;

    int length = sizeof(arr1) / sizeof(int);

    for (int i = 0; i < length; i++)
    {
        if (highest_num <= arr1[i])
        {
            highest_num = arr1[i];
        }
    }

    // printf("hn: %i\n", highest_num);
    found_pair_with_sum(arr1, length, 8, highest_num);
    found_pair_with_sum(arr2, length, 8, highest_num);
}

bool found_pair_with_sum(int arr[], int length, int sum, int highest_num)
{
    comp pairs[highest_num + 1];

    for (int i = 0; i < length; i++)
    {
        if (arr[i] < sum)
        {
            int compliment = sum - arr[i];

            if (!pairs[arr[i]].found)
            {

                pairs[compliment].pair_comp = compliment;
                pairs[compliment].found = true;
            }
            else if (pairs[arr[i]].found)
            {
                pairs[compliment].pair_comp = compliment;
                printf("Found Pair:%i and %i\n", pairs[compliment].pair_comp, arr[i]);
                return true;
            }
        }
    }
    printf("Not found");
    return false;
}
